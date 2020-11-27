#pragma once
# include <Windows.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
#define MAX_NUM 63353
typedef int status;
typedef int KeyType;
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef int InfoType;
typedef struct {
	KeyType  key;
	char others[20];
} VertexType; //顶点类型定义


typedef struct ArcNode {         //表结点类型定义
	int adjvex;              //顶点位置编号 
	struct ArcNode* nextarc;//下一个表结点指针
	InfoType info;			//网的权重
} ArcNode;

typedef struct VNode {				//头结点及其数组类型定义
	VertexType data;       	//顶点信息
	ArcNode* firstarc;      	 //指向第一条弧
} VNode, AdjList[MAX_VERTEX_NUM];

typedef  struct {  //邻接表的类型定义
	AdjList vertices;     	 //头结点数组
	int vexnum, arcnum;   	  //顶点数、弧数
	GraphKind  kind;        //图的类型
} ALGraph;

typedef struct {  //图表的管理表定义
	struct {
		char name[30];
		ALGraph * G;
	} elem[10];
	int length;
}GRAPHLIST;


status isrepeat(VertexType V[],int length)
{//判断是否有重复元素

	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (V[i].key == V[j].key )
				return TRUE;
		}

	}
	return FALSE;
}

status isexits(VertexType V[], KeyType u, KeyType v)
{
	int cout = 0;
	int i = 0;
	while (V[i].key != -1)
	{
		if (V[i].key == u || V[i].key == v)
			cout++;
		if (cout == 2)break;
		i++;
	}
	if (cout == 2)return TRUE;
	else return FALSE;
}

status isKeyTypeRight(VertexType V[], KeyType **VR,int arcnum)
{

	KeyType u, v;
	for (int i = 0; i < arcnum; i++)
	{
		u = VR[i][0];
		v = VR[i][1];
		if (!isexits(V, u, v))return FALSE;
	}
	return TRUE;
}

int LocateKey(ALGraph G, KeyType u)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data.key == u)return i;
	}
	return INFEASIBLE;
}

status DeleteArcofVex(ALGraph &G, int u, int v)
{
	//删除位置序号为u的顶点的临接边v
	ArcNode* p, * q;
	p = G.vertices[u].firstarc;
	q = G.vertices[u].firstarc;
	int flag = true;
	while (p != NULL)
	{
		if (p->adjvex == v)
		{
			if (p == G.vertices[u].firstarc)
			{
				G.vertices[u].firstarc = p->nextarc;
				q = p->nextarc;
				free(p);
				p = q;
			}
			else
			{
				q->nextarc = p->nextarc;
				free(p);
				p = q->nextarc;
			}
			flag = false;
			break;
		}
		else
		{
			q = p;
			p = p->nextarc;
		}
	}
	if (flag)return ERROR;
	return OK;
}

void visit(VertexType v)
{
	printf(" %d %s", v.key, v.others);
}

void CreateSpaceforVR(KeyType**&VR, ALGraph G)
{
	VR = new KeyType * [G.arcnum]; //动态分配空间
	if (G.kind % 2)
		for (int i = 0; i < G.arcnum; i++)
			VR[i] = new KeyType[3];
	else
		for (int i = 0; i < G.arcnum; i++)
			VR[i] = new KeyType[2];
}

status InsertArcofGraph(ALGraph& G, KeyType* VR)
{
	int first_index = LocateKey(G, VR[0]);
	int second_index = LocateKey(G, VR[1]);
	if (first_index < 0 || second_index < 0)return ERROR;
	//判断是否已经存在这条边
	ArcNode* p = G.vertices[first_index].firstarc;
	while (p != NULL)
	{
		if (p->adjvex == second_index)return ERROR;
		p = p->nextarc;
	}
	p = G.vertices[second_index].firstarc;
	while (p != NULL)
	{
		if (p->adjvex == first_index)return ERROR;
		p = p->nextarc;
	}
	p = (ArcNode*)malloc(sizeof(ArcNode));
	if (G.kind % 2)
		p->info = VR[2];
	p->adjvex = second_index;
	p->nextarc = G.vertices[first_index].firstarc;
	G.vertices[first_index].firstarc = p;
	if (G.kind > 1)
	{
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = first_index;
		p->nextarc = G.vertices[second_index].firstarc;
		G.vertices[second_index].firstarc = p;
	}
	return OK;
}

void LoadHelper(FILE *fp,ALGraph &G)
{
	KeyType* VR;
	fscanf(fp, "%d %d %d", &G.kind, &G.arcnum, &G.vexnum);
	for (int i = 0; i < G.vexnum; i++)
	{
		fscanf(fp, "%d %s", &G.vertices[i].data.key, G.vertices[i].data.others);
		G.vertices[i].firstarc = NULL;
	}
	if (G.kind % 2)VR = new KeyType[3];
	else  VR = new KeyType[2];
	for (int i = 0; i < G.arcnum; i++)
	{
		if (G.kind % 2)fscanf(fp, "%d %d %d", &VR[0], &VR[1], &VR[2]);
		else fscanf(fp, "%d %d", &VR[0], &VR[1]);
		InsertArcofGraph(G, VR);
	}
}

status InitGraph(ALGraph*& G)
{
	if (G)return ERROR;
	G = new ALGraph;
	G->arcnum = 0;
	G->vexnum = 0;
	G->vertices[0].firstarc = NULL;
	return OK;
}
void COLOR_PRINT(const char* s, int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
	printf(s);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}
void failed()
{
	COLOR_PRINT("\n\t\tWARNING YOU ARE DOING UNEXPEXTED ACTION!\n", 4);


	Beep(3700, 1000);
}

void success()
{
	COLOR_PRINT("\n\t\tSUCCESS!\n", 3);
}

void ShowCopyRight()
{
	system("cls");
	printf("CopyRight@suyu\n"); system("color 9");
	PlaySound(TEXT("CastleintheSky.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(2500);	
	printf("  ,0W0OXNXKOko,.;kXXNNNXK0KNWMMMMMMMMMMMMNl ;XMK; .',,cd0NMMMMMMMMMMk.,0MMMMMXkxodXMMMMMW0kkkOKXX0O0OdoodkKXXNxckXX0Okl.\n"); system("color D");
	printf(" .kWklO0dlc::cloxO0XNWWWMMMMMMMMMMMMMMMMM0, lNMO' :Okdc;;oKWMMMMWWMMk.,KMMMMWko;.oWMMMMMMMWX0O000xlll:;;:ldOXWWOoxOKWWWk\n"); Sleep(100); system("color 1");
	printf(" oNk;oNNXKXXNWWWWWWMMMWWMMMMMMMMMMMMNNMMWx..kMWk..dWMMWXkl:ldxOKOKWNd.cNMMMWKkd'.xWMMMMMMMMMMMMMWKO0XXXKXXKKKKNNOodllONW\n"); system("color 4");
	printf(",Od.'kMMMMMMMMMMMMMMMNKXMMMMMMMMMMMXxOMMNl '0WK: .xMMMMMMWKkxkOkkXWK:.kMMMW00XX:.l0WMMMMMMMMMMMMMMN00NMMMMNXWWNWN0Kk,,xW\n"); Sleep(100); system("color E");
	printf("',  :XMMMMMMMMMMMMMMN0KWMWNWMMMMMMXl,kWMKo',ONx' .xMMMMMMMMMMMNkkWNd.cXMMNK0NM0;;dk0WMMMMMMMMMMMMMMW0xOWMMWKKWMMMMMW0;'o\n"); system("color E");
	printf("   .OMMMMMMMMMMMMMMNOOWMWXKWMMMMMWk,;kWW0Ol,OXl. .xWMMMMMMMMMMKdONd.,0MWKokWMNl'xxcdXMMMMMMMMMMMMMMMWKdxXMMN0XMMMMMMMKl,\n"); Sleep(100); system("color E");
	printf("   lNMMMMMMMMMMMMMNOONMWKOKWMMMMMXdllkWWXKo,xk'.. :XMMMMMMMMMMklOk'.xWNd,;xXMK,;Kk''xWMMMMXKWMMMMMMMMMNkdKMM0ONMMMXkONXd\n"); system("color 1");
	printf("  .xMMMMMMMMMMMMMXk0WMMMkckNMMMMWOcxkOWWNNk;:;..  .kMMMMMMMMMWd....l0kl..cx0Mx.cNXc.;KMMMWolNMMMMMMMMMMWOd0WNk0MMMWKdlkK\n"); Sleep(100); system("color F");
	printf("  .xMMMNNMMMMMMWKk0WMMMMk'lXMMMMXl;kOOWWWW0;.....',oXMMMMMMMMNc   'clox:,xOKWd.oWWk'.xMMMNc:XMMMMMMMMMMMMKdkXkxXMMMMWd';\n"); system("color 4");
	printf("  .OMMMXXMMMMMN0OXMMMMMWx.,0MMMWk,c0xdO0KN0;.. .ldclkWMMMMMMMX: ...c0Nx,cOOKXo,dWMKl'cNMMX;.xWWWWMMMMMMMMMXxxkd0MMMMM0'\n"); Sleep(100); system("color 4");
	printf("  :XMMN0XMMWX00XWMMMMMW0l..xNKOo..;c,',;coo,   .ox::oXMMMMMNKo.  .:KWk'.:c;;;..:ddo;..d0Kk' lNWXNMMMMMMMMMMNOxoxNMMMMk.\n"); system("color 5");
	printf("  oWMWKOXXOkkKWMMMMMMMNk;  ,dxdc'oKXd:o0XNNd;,..o0ccx0WMMWKc'. .,oxKO' ...'..:xxOOkd:..;c;  cNNk0MMMMMMMMMMMW0l:kNMMWo\n"); Sleep(100); system("color 1");
	printf(" '0MWXd:ccdKWMMMMMMWWMN0;..;0WNxoKWW0lxWMMMNd:,.dN0dxO0XKd'    ,kOk0l.:Okxl,:0WWMMMWK:.ox,..cNXdOMWWMMMMMMMMMWx:xXWMNc\n"); system("color 1");
	printf(".oWW0l';xXWMMMMMMMWKKWWWd;c:dNNkOMMMNxkWMMMMKol:oWW0dc;cc'':c:..x0xl',0WNKc,kWMMMMMMWd.;d,coc0OoKMNNMMMMMMMMMWkdKWWMNc\n"); Sleep(100); system("color 9");
	printf(";KNo..,kWMMMMMMMMMNxlOKNk;do;ddlkOkOd::xO0000kxlc0MWk'.':dOXMK;.x0c..dWW0l..ckKXNNX00d....xXdl:lXWKKMMMMMMMMNkkKWMMMX;\n"); system("color 3");
	printf("OKc  ';OMWNWMWMMMMNk:l0N0:xO;..'oddxxookK0OxooxxlxNMNd,,oKMMMX:.oK:.cXMWO;,lkXWWWWWWNO'  :KMk'.oWNKNMMMWNWMWd'oNMMMMX;\n"); Sleep(100); system("color 8");
	printf("k,  .,cXXOxKWXXMMMWOc:dKXloXd. ,xkdlc;;loooxkO000OKWMNd,,dNMMWl.l0l:OMWN0xxdolc;;;:ll;  .:OKk,.xW00WMMMXOXMX:.cx0WMMN:\n"); system("color 5");
	printf(".  .:ckNo..xWXOXMMMKololc'.:'                'oKWWWWMMNo..xNMWd.;XOkWWNX0:.               ..,..kXkKMMMNocKWk,,;..xWMX:\n"); Sleep(100); system("color D");
	printf("   ,cokc.  :XW0kXMMWxcd, .   .'.          .';,ckNMMMMMMNd..xNWk.,KNWMMMWKc.'.          .::;. .:0kdXMMNo.'OK;'ol. .xWX:\n"); system("color 2");
	printf("  .,...    '0MNo:OMWk:xk'  .lONKo,.       cKWXKNMMMMMMMMWO;':x0,.kMMMMMMX0KNKxo:.     .dNWNk'.xKoxWMNo. .do.,Ox'  .xNc\n"); Sleep(100); system("color D");
	printf("            lXk:;l0WXc:KO, .xWMWKko,      .;OMMMMMMMMMMMMMXd::o;.oWMMMMMMMMMXkdl'      .oXNkcdXkl0MXl.  .'. .dO:   .xl\n"); system("color 7");
	printf("            'c;oX0okNx'oNKl,cOWWx.  .      .oNMMMMMMMMMMMMMWWKx:.cKMMMMMMMMMO,          lXWNNWXdkN0l..c,   :d;cl.   .'.\n"); Sleep(100); system("color D");
	printf("             .;KN0o:ok:,OMWNXXWMXd;'....,,:dKWMMMMMMMMMMMMMMMMWOc,dWMMMMMMMMNOxxxxxxxxxOXWMMMWkd0x,.,kK:  ,0X;.,.\n"); system("color C");
	printf("             .lNWXx;;;,.cKMMMMMMMMWNXXXNWWWMMMMMMMMMMMMMMMMMMMMMXxxXMMMMMMMMMMMMMMMMMMMMMMMMWOool;.:00: .;kW0'  '.\n"); Sleep(100); system("color C");
	printf("             .;KMXxoc;,..lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMM0,....,lloc.,0MNl.   ..\n"); system("color 5");
	printf("              .xWKkK0l:,..lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO,     .,dXKxxXMO. .   .'.\n"); Sleep(100); system("color 9");
	printf("               ,0X000KOc',l0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO' ';. .:OK000KWNl        .\n"); system("color 7");
	printf("                ;OXKO0WXd:dXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0KWWMMMMMMMMMMMMMMMMMMMMMMMMMMNx:cdKk.'xNMW0OKNWx.\n"); Sleep(100); system("color A");
	printf("                 ;ONkkWMNd:dXMMMMMMMMMMMMMMMMMMMMMMMMMMMMO;dNWMMMMMMMMMMMMMMMMMMMMMMMMMMX0XWMK;'kWNOxONW0c.\n"); system("color 8");
	printf("                 .cdkO000Oc;dXMMMMMMMMMMMMMMMMMMMMMMMMMMMKokNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc'xKkdkKKx:.\n"); Sleep(100); system("color B");
	printf("                 .'..lk0KOo,'oXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK: 'oxOOxo;\n"); system("color 5");
	printf("                       'lOOl..cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0;  ,od:..,.\n"); Sleep(100); system("color 9");
	printf("                         .;l,  cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:  .,;.\n"); system("color 1");
	printf("                           ..  .cKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0;..,co:.\n"); Sleep(100); system("color 3");
	printf("                              .. 'kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0; ;OXKd.\n"); system("color 5");
	printf("                              .,. .oNMMMMMMMMMMMMMMMMMMMMMMWNNNWWMMMMMMMMMMMMMMMMMMMMW0, ;0WK:\n"); Sleep(100); system("color 9");
	printf("                               'l:  :0WMMMMMMMMMMMMMMWKkxkkkkxxkO00OOXMMMMMMMMMMMMMMWO,.:KNk'\n"); system("color 4");
	printf("                                cx;  'l0WMMMMMMMMMMMMNOxkKXXXXNNWWWNKNMMMMMMMMMMMMMNx' ;00c.\n"); Sleep(100); system("color 9");
	printf("                                .,'... .:kNMMMMMMMMMMMMMMMMXKKXNWMMMMMMMMMMMMMMMMXx,   co.\n"); system("color 3");
	printf("                                 ';',.....,xXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKx,    .;.\n"); Sleep(100); system("color 1");
	printf("                                 ',...;o:,,,:o0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOc;:,.\n"); system("color 5");
	printf("                                 ..   .clcxkl'.:xXWMMMMMMMMMMMMMMMMMMMMMMWKx;':OKc\n"); Sleep(100); system("color 7");
	printf("                                        .,xWNk:..,lONMMMMMMMMMMMMMMMMMMNOl''l0WMK, .\n"); system("color A");
	printf("                                         .dWMMWKd;..,o0NMMMMMMMMMMMMN0xl;:dKWMMMk.\n"); Sleep(100); system("color A");
	printf("                                         .dWMMMMMW0d;..,oKWMMMMMWX0d::lk0XMMMMMNl\n"); system("color C");
	printf("                                         .kMMMMMMMMMWKxc,;ldxxxdoc:cdOKWMMMMMMMX; ....\n"); Sleep(100); system("color 7");
	printf("                                      .',lXMMMMMMMMMMMMMNKkollldkOXWMMMMMMMMMMMNdcOXK0Oxdc.\n"); system("color E");
	printf("                                      ;OKXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWMMMMMMW0,\n"); Sleep(100); system("color 1");
	printf("                                   .;oKNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd.\n"); system("color 7");
	printf("                                'lkXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk.\n"); Sleep(100); system("color 9");
	printf("                              ,xXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK;\n"); system("color 3");
	printf("                            .lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd.   ...\n"); Sleep(100); system("color 4");
	printf("                            :XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc .o0Okxo:'..\n"); system("color D");
	printf("                   .''....;oKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0'.xWMMWWNXOkdoc;.\n"); Sleep(100); system("color 9");
	printf("             .';ldOKNXK00XNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWo.,0WMMMMMMWWWNKko,\n"); system("color 8");
	printf("          .lOKNWMMMMMMMMMNO0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK; :KMMMMMMMMMMMWNk.\n"); Sleep(100); system("color A");
	printf("        .oKWMMMMMMMMMMMWKccKMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd..lXMMMMMMMMMMMMk.  ..\n"); system("color 4");
	printf("       'kWMMMMMMMMMMMMNx..xWMMMMMMMMMMMMNKKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0, .lXWWWWMMMMMMXc  .''.\n"); Sleep(100); system("color D");
	printf("     .:0WMMMMMMMMMMMMWd. cNMMMMMMMMMMMMMMW0kdkXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWx. .dK0OK0kk0XOc. ..',..\n"); system("color B");
	printf("    .c0MMMMMMMMMMMMMMX; .xMMMMMMMMMMMMMMMMMNxcd0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0'  ;OKOl'..,:.   'lkxcl\n"); Sleep(100); system("color C");
	printf("CopyRight@suyu\n"); system("color 9"); 
	PlaySound(TEXT("Canon.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Sleep(2400);
}