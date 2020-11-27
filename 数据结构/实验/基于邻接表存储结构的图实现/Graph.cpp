# include <stdio.h>
# include <stdlib.h>
# include <string>
# include<cstdio>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")

# include"Graph.h"
using namespace std;
int visited[MAX_VERTEX_NUM];
void(*VisitFunc)(VertexType v);


status CreateGraph(ALGraph &G, VertexType V[], KeyType ** VR)
//根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR如果有相同的关键字，返回ERROR。
{
    if (isrepeat(V,G.vexnum))return ERROR;
    if (!isKeyTypeRight(V, VR,G.arcnum))return ERROR;
    if (G.vexnum > MAX_VERTEX_NUM)return ERROR;


    for (int i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].data.key = V[i].key;
        strcpy(G.vertices[i].data.others, V[i].others);
        G.vertices[i].firstarc = NULL;
      
    }
    for (int i = 0; i < G.arcnum; i++)
    InsertArcofGraph(G, VR[i]);
    return OK;
}

status ClearGraph(ALGraph& G)
/*销毁无向图G*/
{
    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode* p, * q;
        p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            q = p->nextarc;
            free(p);
            p = q;
        }
    }
    G.vexnum = 0;
    G.arcnum = 0;
    return OK;
}

status DestroyGraph(ALGraph*& G)
{
    if (G)
    {
        ClearGraph(*G);
        free(G);
        G = NULL;
        return OK;
    }
    return ERROR;
}

status PutVex(ALGraph& G, KeyType u, VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    if (LocateKey(G, value.key)>=0 && value.key != u)return ERROR;
    int index = LocateKey(G, u);
    if (index < 0)return ERROR;
    G.vertices[index].data.key = value.key;
    strcpy(G.vertices[index].data.others, value.others);
    return OK;

}

int FirstAdjVex(ALGraph G, KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    int index = LocateKey(G, u);
    if (index < 0)return INFEASIBLE;
    if (G.vertices[index].firstarc == NULL)return INFEASIBLE;
    int first_adj = G.vertices[index].firstarc->adjvex;
    return first_adj;
}

int NextAdjVex(ALGraph G, KeyType v, KeyType w)
//根据u在图G中查找顶点，查找成功返回顶点v的邻接顶点相对于w的下一邻接顶点的位序，查找失败返回-1；
{
    int index = LocateKey(G, v);
    if (index < 0)return INFEASIBLE;
    int currentindex = LocateKey(G, w);
    if (currentindex < 0)return INFEASIBLE;
    ArcNode* p = G.vertices[index].firstarc;
    while (p != NULL)
    {
        if (p->adjvex == currentindex)break;
        p = p->nextarc;
    }
    if (p == NULL)return INFEASIBLE;
    if (p->nextarc==NULL)return INFEASIBLE;
    int next_adj = p->nextarc->adjvex;
    return next_adj;
}

status InsertVex(ALGraph& G, VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    if (G.vexnum == MAX_VERTEX_NUM)return ERROR;
    if (LocateKey(G, v.key) >= 0 )return ERROR;
    G.vertices[G.vexnum].data.key = v.key;
    strcpy(G.vertices[G.vexnum].data.others, v.others);
    G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum++;
    return OK;
}

status DeleteVex(ALGraph& G, KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    int index_of_deletevex = LocateKey(G, v);
    if (index_of_deletevex < 0)return ERROR;
    if (G.vexnum == 1)return ERROR;
    ArcNode* p,*q;
    
    p = G.vertices[index_of_deletevex].firstarc; //删除关键字顶点的临接边
    while (p != NULL)
    {
        q = p->nextarc;
        free(p);
        p = q;
        G.arcnum--;
    }
    G.vertices[index_of_deletevex].firstarc = NULL;
    for (int i = 0; i < G.vexnum; i++)//删除其他顶点与需要删除顶点关联的边
    {
        p = G.vertices[i].firstarc;
        q = G.vertices[i].firstarc;
        while (p != NULL)
        {
            if (p->adjvex == index_of_deletevex)
            {
                if (p == G.vertices[i].firstarc)
                {
                    G.vertices[i].firstarc = p->nextarc;
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
            }
            else
            {
                if (p->adjvex > index_of_deletevex)p->adjvex--;//考虑到需要删除的顶点之后的顶点要前移，位置序号要改变
                q = p;
                p = p->nextarc;
            }
        }
    }
    if (index_of_deletevex == G.vexnum - 1)G.vexnum--;//如果顶点位置序号是最后一个直接删除否则后面的顶点逐个前移
    else
    {
        for (int i = index_of_deletevex + 1; i < G.vexnum; i++)
            G.vertices[i - 1] = G.vertices[i];
        G.vertices[G.vexnum - 1].firstarc = NULL;
        G.vexnum--;

    }
    return OK;
}

status InsertArc(ALGraph& G, KeyType v, KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    int first_index = LocateKey(G, v);
    int second_index = LocateKey(G, w);
    if (first_index < 0 || second_index < 0)return ERROR;
    //判断是否已经存在这条边
    ArcNode* p=G.vertices[first_index].firstarc;
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
    //插入边
    p = (ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex = second_index;
    p->nextarc = G.vertices[first_index].firstarc;
    G.vertices[first_index].firstarc = p;
    p = (ArcNode*)malloc(sizeof(ArcNode));
    p->adjvex = first_index;
    p->nextarc = G.vertices[second_index].firstarc;
    G.vertices[second_index].firstarc = p;
    return OK;
}

status DeleteArc(ALGraph& G, KeyType v, KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    int first_index = LocateKey(G, v);
    int second_index = LocateKey(G, w);
    if (first_index < 0 || second_index < 0)return ERROR;
    if (!DeleteArcofVex(G, first_index, second_index))return ERROR;
    if (G.kind>1)
        if (!DeleteArcofVex(G, second_index, first_index))return ERROR;
    G.arcnum--;
    return OK;

}

void DFS(ALGraph G, int i)
{
    int w;
    VisitFunc(G.vertices[i].data);
    visited[i] = TRUE;
    ArcNode* p=G.vertices[i].firstarc;
    while (p)
    {
        w = p->adjvex;
        if (!visited[w])DFS(G, w);
        p = p->nextarc;
    }
}

void DFSTraverse(ALGraph G, void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    VisitFunc = visit;
    for (int i = 0; i < G.vexnum; i++)visited[i] = false;
    for (int i = 0; i < G.vexnum; i++)
        if (!visited[i])DFS(G, i);

}

/*
void BFS(ALGraph G, int i)
{
    int u, v;
    ArcNode* p;
    queue<int>Q;
    VisitFunc(G.vertices[i].data);
    visited[i] = TRUE;
    Q.push(i);
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        p = G.vertices[u].firstarc;
        while (p)
        {
            v = p->adjvex;
            if (!visited[v])
            {
                VisitFunc(G.vertices[v].data);
                Q.push(v);
                visited[v] = TRUE;
            }
            p->nextarc;
        }
    }

}*/

void BFS(ALGraph G, int index)
{
    int j = 0,i=0;
    int Que[MAX_VERTEX_NUM];
    ArcNode* p;
    VisitFunc(G.vertices[index].data);
    visited[index] = TRUE;
    Que[i++] = index;
    while (i >j)
    {
        p = G.vertices[Que[j]].firstarc;
        while (p)
        {
            if (!visited[p->adjvex])
            {
                Que[i++] = p->adjvex;
                VisitFunc(G.vertices[p->adjvex].data);
                visited[p->adjvex] = TRUE;
             }
            p = p->nextarc;
        }
       
        j++;
    }
}

void BFSTraverse(ALGraph G, void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    VisitFunc = visit;
    for (int i = 0; i < G.vexnum; i++)visited[i] = FALSE;
    for (int i = 0; i < G.vexnum; i++)
        if (!visited[i])BFS(G, i);
}

status IsArcinKeylist(KeyType first, KeyType second, KeyType** p,int length)
{
    for (int i = 0; i < length && p[i][0] != -1; i++)
    {
        if (p[i][0] == second && p[i][1] == first)
            return TRUE;
    }
    return FALSE;
}

status SaveArcofGraph(ALGraph G,KeyType** p)
{
    int first_key, second_key,j=0;
    ArcNode* q;
    for (int i = 0; i < G.vexnum; i++)
    {
        q = G.vertices[i].firstarc;
        first_key = G.vertices[i].data.key;
        while (q)
        {
            second_key = G.vertices[q->adjvex].data.key;
            if (!IsArcinKeylist(first_key, second_key, p,j))
            {
                p[j][0] = first_key;
                p[j][1] = second_key;
                if (G.kind % 2)p[j][2] = q->info;
                j++;
            }
            q = q->nextarc;
        }
    }
    return OK;
}

status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    KeyType** VR=NULL;
    FILE* fp = fopen(FileName, "w");
    fprintf(fp, "%d %d %d\n", G.kind, G.arcnum, G.vexnum);//存储图类型、图边数、图顶点数
    for (int i = 0; i < G.vexnum; i++)//存储图的各个顶点和顶点的关键字
        fprintf(fp, "%d %s ", G.vertices[i].data.key, G.vertices[i].data.others);
    fprintf(fp, "\n");

    CreateSpaceforVR(VR, G);
    SaveArcofGraph(G, VR);//将图的边信息保存在VR数组中
    for (int i = 0; i < G.arcnum; i++)//存储图的边信息
    {
        if (G.kind % 2)fprintf(fp, "%d %d %d ", VR[i][0], VR[i][1], VR[i][2]);
        else
            fprintf(fp, "%d %d ", VR[i][0], VR[i][1]);
    }
    fclose(fp);
    return OK;
}

status LoadGraph(ALGraph*& G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    if (G)return ERROR;
    InitGraph(G);
    FILE* fp = fopen(FileName, "r");
    LoadHelper(fp, *G);
    fclose(fp);
    return OK;
}

status AddGraph(GRAPHLIST& GraphList, char GraphName[])
{
    strcpy(GraphList.elem[GraphList.length].name, GraphName);
    GraphList.elem[GraphList.length].G = NULL;
    GraphList.length++;
    return OK;
}

status RemoveGraph(GRAPHLIST& GraphList, char GraphName[])
{
    int i = 0;
    while (strcmp(GraphList.elem[i].name, GraphName) && i < GraphList.length)
    {
        i++;
    }
    if (i == GraphList.length - 1)
    {
        DestroyGraph(GraphList.elem[i].G);

    }
    else if (i < GraphList.length - 1)
    {
        GRAPHLIST p;
        p.elem[0] = GraphList.elem[i];
        for (int j = GraphList.length - 1; j > i; j--)
        {
            GraphList.elem[j - 1] = GraphList.elem[j];
        }
        GraphList.elem[GraphList.length - 1] = p.elem[0];
        DestroyGraph(GraphList.elem[GraphList.length - 1].G);
        strcpy(GraphList.elem[GraphList.length - 1].name, " ");

    }
    else
        return ERROR;

    GraphList.length--;
    return OK;
}

status LocateGraph(GRAPHLIST GraphList, char GraphName[])
{
    int i = 0;
    while (strcmp(GraphList.elem[i].name, GraphName) && i < GraphList.length)
    {
        i++;
    }
    if (i == GraphList.length)
        return 0;
    else
        return i + 1;
}

void ShowGraphList(GRAPHLIST GraphList)
{
    for (int i = 0; i < GraphList.length; i++)
    {
        printf("\t\t%s  ", GraphList.elem[i].name);
        printf("\n");
    }
}

status InitGraphList(GRAPHLIST& GraphList,char FileName[])
{
    FILE* fp = fopen(FileName, "r");
    fscanf(fp, "%d", &GraphList.length);
    for (int i = 0; i < GraphList.length; i++)
    {
        fscanf(fp, "%s", GraphList.elem[i].name);
        GraphList.elem[i].G = NULL;
        InitGraph(GraphList.elem[i].G);
        LoadHelper(fp, *GraphList.elem[i].G);
    }
    fclose(fp);
    return OK;
}

status IsGraphExits(ALGraph* G)
{
    if (G)
        return TRUE;
    return FALSE;
}

status ShowGraph(ALGraph G)
{
    if (! G.vexnum)return ERROR;
    ArcNode* p = NULL;
    int index;
    for (int i = 0; i < G.vexnum; i++)
    {
        printf("\t\t");
        visit(G.vertices[i].data);
        p = G.vertices[i].firstarc;    
        while (p)
        {
            index = p->adjvex;
            if (G.kind%2)printf(" %d %d", G.vertices[index].data.key,p->info);
            else printf(" %d", G.vertices[index].data.key);
            p = p->nextarc;
        }
        printf("\n");

    }
    return OK;
}

//1 A 2 B 3 C 7 R 4 D 5 E 6 F -1 nil 1 2 1 3 2 3 4 6 5 6 2 7 -1 -1

int main()
{
    ALGraph *G = NULL;  int op = 1;
    GRAPHLIST GraphList;
    GraphList.length = 0;
    int  j;
    int graph_num = 0;
    int count = 0;
    char FileName[30], GraphName[30];
    PlaySound(TEXT("Canon.wav"), NULL, SND_FILENAME | SND_ASYNC|SND_LOOP|SND_SYSTEM);
    Sleep(2000);
    while (op) {  
        system("cls");
        system("color 3");
        printf("\t             Menu for Graph Lists      \n");
        printf("\t-------------------------------------------------\n");
        printf("\t      1.AddGraph             2.RemoveGraph\n");
        printf("\t      3.LocateGraph          4.ShowGraphList\n");
        printf("\t      5.EnterGraph           6.InistLists\n");
        printf("\t      0.exit                 7.CopyRight\n");
        printf("\t    请选择你的操作[0~7]:");
        scanf("%d", &op);
        switch (op) {
        case 1:
            system("color 5");
            printf("\t"); printf("\t"); scanf("%s", GraphName);
            j = AddGraph(GraphList, GraphName);
            if (j)success();

            system("pause");
            break;
        case 2:
            system("color 8");
            printf("\t"); printf("\t"); scanf("%s", GraphName);
            j = RemoveGraph(GraphList, GraphName);
            if (j)success();
            else printf("\n\t\tthe Graph not exists!\n");
            system("pause");
            break;
        case 3:
            system("color 1");
            printf("\t"); printf("\t"); scanf("%s", GraphName);
            j = LocateGraph(GraphList, GraphName);
            if (j)printf("\n\t\tit is %d Graph!\n", j);
            else printf("\n\t\tthe Graph not have space for it!\n");
            system("pause");
            break;
        case 4:
            system("color D");
            if (GraphList.length == 0)printf("\n\t\tno Graph exists\n");
            else ShowGraphList(GraphList);
            system("pause");
            break;
        case 6:
            system("color C");
            strcpy(FileName, "data.txt");
            InitGraphList(GraphList, FileName);
            success();
            system("pause");
            break;
        case 7:
            system("cls");
            ShowCopyRight();
            system("pause");
            break;
        case 5:
            system("color 9");
            if (GraphList.length == 0)
            {
                printf("\t\tthere is no Graph in lists\n");
                system("pause");
                break;
            }
            printf(" \t\tchoose a Graph to operate!\n");
            while (graph_num == 0)
            {
                printf("\t"); printf("\t"); scanf("%s", GraphName);
                graph_num = LocateGraph(GraphList, GraphName);
                if (graph_num)G = GraphList.elem[graph_num - 1].G;
                else printf("\t\tnot found!\n");
            }
            while (op) {
                system("cls");
                printf("operate Graph %s\n", GraphList.elem[graph_num - 1].name);
                printf("\t      Menu for Linear Table On Graph Structure \n");
                printf("\t-------------------------------------------------\n");
                printf("\t    	  1. InitGraph           9. DeleteVex\n");
                printf("\t    	  2. DestroyGraph       10. InsertArc\n");
                printf("\t    	  3. ClearGraph         11. DeleteArc \n");
                printf("\t    	  4. PutVex             12. LocateKey\n");
                printf("\t    	  5. CreateGraph        13. BFSTraverse\n");
                printf("\t    	  6. FirstAdjVex        14. DFSTraverse\n");
                printf("\t    	  7. NextAdjVex         15. SaveGraph\n");
                printf("\t    	  8. InsertVex          16. LoadGraph\n");
                printf("\t    	  0. Exit               17. ShowGraph\n");
                printf("\t-------------------------------------------------\n");

                printf("\t    请选择你的操作[0~16]:");
                scanf("%d", &op);
                status temp;  KeyType e,v, ** VR,VR_1[3];
                VertexType value, V[MAX_VERTEX_NUM];
                switch (op) {
                case 1:
                    if (InitGraph(GraphList.elem[graph_num - 1].G) == OK)//输入最初首节点使节点被初始化，而非指向节点的指针被初始化
                    {
                        success();
                        G = GraphList.elem[graph_num - 1].G;
                    }
                    else failed();
                    system("pause"); break;
                case 2:
                    temp = DestroyGraph(GraphList.elem[graph_num - 1].G);
                    if (temp == OK)
                    {
                        success();
                        G = NULL;
                    }
                    else  printf("\n\t\tnot have space for it!\n");

                    system("pause"); break;
                case 3:                   
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        ClearGraph(*G);
                        success();
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");           

                    system("pause"); break;
                case 4:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        printf("\t"); printf("\tthe key to change is "); scanf("%d", &e);
                        printf("\t"); printf("\tthe new key is "); scanf("%d", &value.key);
                        printf("\t"); printf("\tthe new value  is "); scanf("%s", value.others);
                        temp = PutVex(*G,e,value);
                        if(temp)
                            success();
                        else failed();
                    }
                    else printf("\n\t\tnot have space for it!\n");

                    system("pause"); break;
                case 5:
                   temp = IsGraphExits(G);
                    if (temp)
                    {
                        if (G->vexnum==0)
                        {
                            printf("\t\twhich type of Graph(有向图:0,有向网:1,无向图:2,无向网:3): ");
                            scanf("%d", &G->kind);
                            printf("\t\tHow many vexs are there in Graph? ");
                            scanf("%d", &G->vexnum);
                            printf("\t\tHow many arcs are there in Graph? ");
                            scanf("%d", &G->arcnum);
                            CreateSpaceforVR(VR, *G);
                            printf("\t\tplease enter the key and value of vex with blank\n");
                            printf("\t\t");
                            for (int i = 0; i < G->vexnum; i++)scanf("%d %s", &V[i].key, V[i].others);
                            if (G->arcnum)printf("\t\tplease enter two keys and weight if have of arcs with blank\n\t\t");
                            
                            for (int i = 0; i < G->arcnum; i++)
                            {
                                if (G->kind % 2)scanf("%d %d %d", &VR[i][0], &VR[i][1], &VR[i][2]);
                                else scanf("%d %d", &VR[i][0], &VR[i][1]);
                            }
                            temp = CreateGraph(*G, V, VR);
                            if (temp == OK)success();
                            else failed();
                        }
                        else printf("\t\tyou can not create already exsited Graph!\n");
                                               
                    }
                    else printf("\t\tnot have space for it!please init it!\n");      


                    system("pause"); break;
                case 6:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        printf("\t\tthe key is "); scanf("%d", &e);
                        temp = FirstAdjVex(*G,e);
                        if (temp < 0)printf("\t\tnot found\n");
                        else printf("\t\tthe first adj index of the vex is:%d %s\n", G->vertices[temp].data.key,G->vertices[temp].data.others);
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");


                    system("pause"); break;
                case 7:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        printf("\t\tthe vex want to search is "); scanf("%d", &e);
                        printf("\t\tthe vex before is "); scanf("%d", &v);
                        temp = NextAdjVex(*G, e,v);
                        if (temp < 0)printf("\t\tnot found\n");
                        else printf("\t\tthe next adj index of the vex is:%d %s\n", G->vertices[temp].data.key, G->vertices[temp].data.others);
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");

                    system("pause"); break;
                case 8:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        printf("\t\tthe new key is "); scanf("%d", &value.key);
                        printf("\t\tthe new value is "); scanf("%s", &value.others);
                        temp = InsertVex(*G, value);
                        if (temp )success();
                        else failed();
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");

                    system("pause"); break;
                case 9:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        printf("\t\tthe key of vex want to delete is "); scanf("%d", &e);           
                        temp = DeleteVex(*G, e);
                        if (temp )success();
                        else failed();
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");


                    system("pause"); break;
                case 10:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        printf("\t\tthe first vex key is "); scanf("%d", &VR_1[0]);
                        printf("\t\tthe second vex key is "); scanf("%d", &VR_1[1]);
                        if (G->kind % 2)
                        {
                            printf("\t\tthe weight of arc is "); scanf("%d", &VR_1[2]);
                        }
                        temp = InsertArcofGraph(*G, VR_1);
                        if (temp)
                        {
                            success();
                            G->arcnum++;
                        }
                        else failed();
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");

                    system("pause"); break;
                case 11:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        printf("\t\tthe first vex key is "); scanf("%d", &e);
                        printf("\t\tthe second vex key is "); scanf("%d", &v);
                        temp = DeleteArc(*G, e, v);
                        if (temp)success();
                        else failed();
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");

                    system("pause"); break;
                case 12:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        printf("\t\tthe key is "); scanf("%d", &e);
                        temp = LocateKey(*G, e);
                        if (temp < 0)printf("\t\tnot found\n");
                        else printf("\t\tthe index of the vex is:%d %s\n", G->vertices[temp].data.key, G->vertices[temp].data.others);
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");

                    system("pause"); break;
                case 13:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        printf("\t\t");
                        BFSTraverse(*G,visit);    
                        printf("\n");
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");

                    system("pause"); break;
                case 14:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        printf("\t\t");
                        DFSTraverse(*G, visit);
                        printf("\n");
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");

                    system("pause"); break;
                case 15:
                    temp = IsGraphExits(G);
                    if (temp)
                    {
                        strcpy(FileName, "save.txt");
                        temp = SaveGraph(*G,FileName);
                        if (temp)success();
                        else failed();
                    }
                    else printf("\n\t\tnot have space for it!please init it!\n");

                    system("pause"); break;
                case 16:
                    strcpy(FileName, "save.txt");
                    temp = LoadGraph(GraphList.elem[graph_num - 1].G, FileName);
                    if (temp)
                    {
                        success();
                        G = GraphList.elem[graph_num - 1].G;
                    }
                    else failed();

                    system("pause"); break;
                case 17:
                    temp = ShowGraph(*G);
                    if (temp)success();
                    else failed();

                    system("pause"); break;
                case 0:
                    break;
                default:
                    system("pause"); break;
                }
            }
            op = 1;
            graph_num = 0;
            break;
        case 0:
            break;
        }

    }

    ShowCopyRight();
    printf("\t欢迎下次再使用本系统！\n");
}