# include<Windows.h>

typedef int status;
typedef int KeyType;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
int num = -1;

typedef struct {
	KeyType  key;
	char others[20];
} TElemType; //二叉树结点类型定义


typedef struct BiTNode {  //二叉链表结点的定义
	TElemType  data;
	struct BiTNode* lchild, * rchild, *next;
} BiTNode, * BiTree;

typedef struct {  //二叉链表的管理表定义
	struct {
		char name[30];
		BiTree T;
	} elem[10];
	int length;
	int listsize;
}FOREST;



status BuildTree(TElemType definition[],BiTree &T)
{
	if (definition[num].key == -1)T= NULL;
	if (definition[++num].key == 0)
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data.key = definition[num].key;
		strcpy(T->data.others, definition[num].others);
		BuildTree(definition,T->lchild);
		BuildTree(definition,T->rchild);
	}
	return OK;
}
status isrepeat(TElemType definition[])
{//判断是否有重复元素
	int length = 0;
	while (definition[length].key != -1)length++;

	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (definition[i].key == definition[j].key && definition[i].key != 0)
				return TRUE;

		}

	}
	return FALSE;
}

void visit(BiTree T)
{
	printf("%4d,%-3s", T->data.key, T->data.others);
}

BiTNode* LocateParentNode(BiTree T, KeyType e)
//查找结点
{
	BiTree result = NULL;
	if (T)
	{
		if (T->lchild && T->lchild->data.key == e) result = T;
		else if (T->rchild && T->rchild->data.key == e) result = T;
		else
		{
			if (!result)result = LocateParentNode(T->lchild, e);
			if (!result)result = LocateParentNode(T->rchild, e);
		}
	}
	return result;
}

status Destroyhelper(BiTree& T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
	if (T)
	{
		Destroyhelper(T->lchild);
		Destroyhelper(T->rchild);
		free(T);
	}
	T = NULL;
	return OK;

}

status helper1(BiTree T, FILE*& fp) {
	int i = 0;
	char ch[100] = "null";
	if (T)
	{
		fprintf(fp, "%d %s ", T->data.key, T->data.others);
		if (helper1(T->lchild, fp))
			if (helper1(T->rchild, fp)) return OK;
			else return ERROR;
	}
	else
	{
		fprintf(fp, "%d %s ", i, ch);
		return OK;
	}
	//fprintf(fp,"%d %s",-1,"null");
}
status helper2(BiTree& T, FILE*& fp) {
	int i;
	char ch[5];

	fscanf(fp, "%d", &i);
	fscanf(fp, "%s", ch);
	if (i==-1&& !strcmp(ch, "null"))
	{
		T = NULL;
		return OK;
	}
	if (!strcmp(ch, "null"))
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data.key = i;
		strcpy(T->data.others, ch);
		helper2(T->lchild, fp);
		helper2(T->rchild, fp);
	}
	return OK;
}

void ShowCopyRight()
{
	printf("CopyRight@suyu\n"); system("color 3"); Sleep(100);
	printf("  ,0W0OXNXKOko,.;kXXNNNXK0KNWMMMMMMMMMMMMNl ;XMK; .',,cd0NMMMMMMMMMMk.,0MMMMMXkxodXMMMMMW0kkkOKXX0O0OdoodkKXXNxckXX0Okl.\n"); system("color A");
	printf(" .kWklO0dlc::cloxO0XNWWWMMMMMMMMMMMMMMMMM0, lNMO' :Okdc;;oKWMMMMWWMMk.,KMMMMWko;.oWMMMMMMMWX0O000xlll:;;:ldOXWWOoxOKWWWk\n"); Sleep(100); system("color C");
	printf(" oNk;oNNXKXXNWWWWWWMMMWWMMMMMMMMMMMMNNMMWx..kMWk..dWMMWXkl:ldxOKOKWNd.cNMMMWKkd'.xWMMMMMMMMMMMMMWKO0XXXKXXKKKKNNOodllONW\n"); system("color B");
	printf(",Od.'kMMMMMMMMMMMMMMMNKXMMMMMMMMMMMXxOMMNl '0WK: .xMMMMMMWKkxkOkkXWK:.kMMMW00XX:.l0WMMMMMMMMMMMMMMN00NMMMMNXWWNWN0Kk,,xW\n"); Sleep(100); system("color 8");
	printf("',  :XMMMMMMMMMMMMMMN0KWMWNWMMMMMMXl,kWMKo',ONx' .xMMMMMMMMMMMNkkWNd.cXMMNK0NM0;;dk0WMMMMMMMMMMMMMMW0xOWMMWKKWMMMMMW0;'o\n"); system("color D");
	printf("   .OMMMMMMMMMMMMMMNOOWMWXKWMMMMMWk,;kWW0Ol,OXl. .xWMMMMMMMMMMKdONd.,0MWKokWMNl'xxcdXMMMMMMMMMMMMMMMWKdxXMMN0XMMMMMMMKl,\n"); Sleep(100); system("color 1");
	printf("   lNMMMMMMMMMMMMMNOONMWKOKWMMMMMXdllkWWXKo,xk'.. :XMMMMMMMMMMklOk'.xWNd,;xXMK,;Kk''xWMMMMXKWMMMMMMMMMNkdKMM0ONMMMXkONXd\n"); system("color 1");
	printf("  .xMMMMMMMMMMMMMXk0WMMMkckNMMMMWOcxkOWWNNk;:;..  .kMMMMMMMMMWd....l0kl..cx0Mx.cNXc.;KMMMWolNMMMMMMMMMMWOd0WNk0MMMWKdlkK\n"); Sleep(100); system("color 9");
	printf("  .xMMMNNMMMMMMWKk0WMMMMk'lXMMMMXl;kOOWWWW0;.....',oXMMMMMMMMNc   'clox:,xOKWd.oWWk'.xMMMNc:XMMMMMMMMMMMMKdkXkxXMMMMWd';\n"); system("color 5");
	printf("  .OMMMXXMMMMMN0OXMMMMMWx.,0MMMWk,c0xdO0KN0;.. .ldclkWMMMMMMMX: ...c0Nx,cOOKXo,dWMKl'cNMMX;.xWWWWMMMMMMMMMXxxkd0MMMMM0'\n"); Sleep(100); system("color A");
	printf("  :XMMN0XMMWX00XWMMMMMW0l..xNKOo..;c,',;coo,   .ox::oXMMMMMNKo.  .:KWk'.:c;;;..:ddo;..d0Kk' lNWXNMMMMMMMMMMNOxoxNMMMMk.\n"); system("color 5");
	printf("  oWMWKOXXOkkKWMMMMMMMNk;  ,dxdc'oKXd:o0XNNd;,..o0ccx0WMMWKc'. .,oxKO' ...'..:xxOOkd:..;c;  cNNk0MMMMMMMMMMMW0l:kNMMWo\n"); Sleep(100); system("color E");
	printf(" '0MWXd:ccdKWMMMMMMWWMN0;..;0WNxoKWW0lxWMMMNd:,.dN0dxO0XKd'    ,kOk0l.:Okxl,:0WWMMMWK:.ox,..cNXdOMWWMMMMMMMMMWx:xXWMNc\n"); system("color D");
	printf(".oWW0l';xXWMMMMMMMWKKWWWd;c:dNNkOMMMNxkWMMMMKol:oWW0dc;cc'':c:..x0xl',0WNKc,kWMMMMMMWd.;d,coc0OoKMNNMMMMMMMMMWkdKWWMNc\n"); Sleep(100); system("color 4");
	printf(";KNo..,kWMMMMMMMMMNxlOKNk;do;ddlkOkOd::xO0000kxlc0MWk'.':dOXMK;.x0c..dWW0l..ckKXNNX00d....xXdl:lXWKKMMMMMMMMNkkKWMMMX;\n"); system("color 4");
	printf("OKc  ';OMWNWMWMMMMNk:l0N0:xO;..'oddxxookK0OxooxxlxNMNd,,oKMMMX:.oK:.cXMWO;,lkXWWWWWWNO'  :KMk'.oWNKNMMMWNWMWd'oNMMMMX;\n"); Sleep(100); system("color F");
	printf("k,  .,cXXOxKWXXMMMWOc:dKXloXd. ,xkdlc;;loooxkO000OKWMNd,,dNMMWl.l0l:OMWN0xxdolc;;;:ll;  .:OKk,.xW00WMMMXOXMX:.cx0WMMN:\n"); system("color 2");
	printf(".  .:ckNo..xWXOXMMMKololc'.:'                'oKWWWWMMNo..xNMWd.;XOkWWNX0:.               ..,..kXkKMMMNocKWk,,;..xWMX:\n"); Sleep(100); system("color E");
	printf("   ,cokc.  :XW0kXMMWxcd, .   .'.          .';,ckNMMMMMMNd..xNWk.,KNWMMMWKc.'.          .::;. .:0kdXMMNo.'OK;'ol. .xWX:\n"); system("color D");
	printf("  .,...    '0MNo:OMWk:xk'  .lONKo,.       cKWXKNMMMMMMMMWO;':x0,.kMMMMMMX0KNKxo:.     .dNWNk'.xKoxWMNo. .do.,Ox'  .xNc\n"); Sleep(100); system("color 7");
	printf("            lXk:;l0WXc:KO, .xWMWKko,      .;OMMMMMMMMMMMMMXd::o;.oWMMMMMMMMMXkdl'      .oXNkcdXkl0MXl.  .'. .dO:   .xl\n"); system("color D");
	printf("            'c;oX0okNx'oNKl,cOWWx.  .      .oNMMMMMMMMMMMMMWWKx:.cKMMMMMMMMMO,          lXWNNWXdkN0l..c,   :d;cl.   .'.\n"); Sleep(100); system("color 4");
	printf("             .;KN0o:ok:,OMWNXXWMXd;'....,,:dKWMMMMMMMMMMMMMMMMWOc,dWMMMMMMMMNOxxxxxxxxxOXWMMMWkd0x,.,kK:  ,0X;.,.\n"); system("color 7");
	printf("             .lNWXx;;;,.cKMMMMMMMMWNXXXNWWWMMMMMMMMMMMMMMMMMMMMMXxxXMMMMMMMMMMMMMMMMMMMMMMMMWOool;.:00: .;kW0'  '.\n"); Sleep(100); system("color 6");
	printf("             .;KMXxoc;,..lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMM0,....,lloc.,0MNl.   ..\n"); system("color 1");
	printf("              .xWKkK0l:,..lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO,     .,dXKxxXMO. .   .'.\n"); Sleep(100); system("color 8");
	printf("               ,0X000KOc',l0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO' ';. .:OK000KWNl        .\n"); system("color A");
	printf("                ;OXKO0WXd:dXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0KWWMMMMMMMMMMMMMMMMMMMMMMMMMMNx:cdKk.'xNMW0OKNWx.\n"); Sleep(100); system("color 9");
	printf("                 ;ONkkWMNd:dXMMMMMMMMMMMMMMMMMMMMMMMMMMMMO;dNWMMMMMMMMMMMMMMMMMMMMMMMMMMX0XWMK;'kWNOxONW0c.\n"); system("color 1");
	printf("                 .cdkO000Oc;dXMMMMMMMMMMMMMMMMMMMMMMMMMMMKokNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc'xKkdkKKx:.\n"); Sleep(100); system("color 7");
	printf("                 .'..lk0KOo,'oXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK: 'oxOOxo;\n"); system("color B");
	printf("                       'lOOl..cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0;  ,od:..,.\n"); Sleep(100); system("color 9");
	printf("                         .;l,  cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:  .,;.\n"); system("color A");
	printf("                           ..  .cKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0;..,co:.\n"); Sleep(100); system("color 3");
	printf("                              .. 'kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0; ;OXKd.\n"); system("color D");
	printf("                              .,. .oNMMMMMMMMMMMMMMMMMMMMMMWNNNWWMMMMMMMMMMMMMMMMMMMMW0, ;0WK:\n"); Sleep(100); system("color 6");
	printf("                               'l:  :0WMMMMMMMMMMMMMMWKkxkkkkxxkO00OOXMMMMMMMMMMMMMMWO,.:KNk'\n"); system("color C");
	printf("                                cx;  'l0WMMMMMMMMMMMMNOxkKXXXXNNWWWNKNMMMMMMMMMMMMMNx' ;00c.\n"); Sleep(100); system("color B");
	printf("                                .,'... .:kNMMMMMMMMMMMMMMMMXKKXNWMMMMMMMMMMMMMMMMXx,   co.\n"); system("color 9");
	printf("                                 ';',.....,xXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKx,    .;.\n"); Sleep(100); system("color 8");
	printf("                                 ',...;o:,,,:o0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOc;:,.\n"); system("color 8");
	printf("                                 ..   .clcxkl'.:xXWMMMMMMMMMMMMMMMMMMMMMMWKx;':OKc\n"); Sleep(100); system("color 9");
	printf("                                        .,xWNk:..,lONMMMMMMMMMMMMMMMMMMNOl''l0WMK, .\n"); system("color A");
	printf("                                         .dWMMWKd;..,o0NMMMMMMMMMMMMN0xl;:dKWMMMk.\n"); Sleep(100); system("color C");
	printf("                                         .dWMMMMMW0d;..,oKWMMMMMWX0d::lk0XMMMMMNl\n"); system("color 8");
	printf("                                         .kMMMMMMMMMWKxc,;ldxxxdoc:cdOKWMMMMMMMX; ....\n"); Sleep(100); system("color 6");
	printf("                                      .',lXMMMMMMMMMMMMMNKkollldkOXWMMMMMMMMMMMNdcOXK0Oxdc.\n"); system("color B");
	printf("                                      ;OKXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWMMMMMMW0,\n"); Sleep(100); system("color 2");
	printf("                                   .;oKNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd.\n"); system("color C");
	printf("                                'lkXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk.\n"); Sleep(100); system("color 8");
	printf("                              ,xXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK;\n"); system("color 7");
	printf("                            .lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd.   ...\n"); Sleep(100); system("color 7");
	printf("                            :XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc .o0Okxo:'..\n"); system("color 2");
	printf("                   .''....;oKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0'.xWMMWWNXOkdoc;.\n"); Sleep(100); system("color 4");
	printf("             .';ldOKNXK00XNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWo.,0WMMMMMMWWWNKko,\n"); system("color 9");
	printf("          .lOKNWMMMMMMMMMNO0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK; :KMMMMMMMMMMMWNk.\n"); Sleep(100); system("color 8");
	printf("        .oKWMMMMMMMMMMMWKccKMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd..lXMMMMMMMMMMMMk.  ..\n"); system("color E");
	printf("       'kWMMMMMMMMMMMMNx..xWMMMMMMMMMMMMNKKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0, .lXWWWWMMMMMMXc  .''.\n"); Sleep(100); system("color 7");
	printf("     .:0WMMMMMMMMMMMMWd. cNMMMMMMMMMMMMMMW0kdkXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWx. .dK0OK0kk0XOc. ..',..\n"); system("color D");
	printf("    .c0MMMMMMMMMMMMMMX; .xMMMMMMMMMMMMMMMMMNxcd0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0'  ;OKOl'..,:.   'lkxcl\n"); Sleep(100); system("color F");
	printf("CopyRight@suyu\n"); system("color 3"); Sleep(100);
}