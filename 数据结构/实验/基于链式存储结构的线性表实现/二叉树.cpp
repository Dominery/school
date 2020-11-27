#include "stdio.h"
#include "stdlib.h"
#include"string"
#include"BitTree.h"
#include<math.h>


status InitBiTree(BiTree& T);
status CreateBiTree(BiTree& T, TElemType definition[]);
status DestroyBiTree(BiTree& T);
status ClearBiTree(BiTree& T);
status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
BiTNode* LocateNode(BiTree T, KeyType e);
status Assign(BiTree& T, KeyType e, TElemType value);
BiTNode* GetSibling(BiTree T, KeyType e);
status InsertNode(BiTree& T, KeyType e, int LR, TElemType c);
status DeleteNode(BiTree& T, KeyType e);
status PreOrderTraverse(BiTree T, void (*visit)(BiTree));
status InOrderTraverse(BiTree T, void (*visit)(BiTree));
status PostOrderTraverse(BiTree T, void (*visit)(BiTree));
status LevelOrderTraverse(BiTree T, void (*visit)(BiTree));
status SaveBiTree(BiTree T, char FileName[]);
status LoadBiTree(BiTree& T, char FileName[]);

status AddBiTree(FOREST& forest, char ListName[]);
status RemoveBiTree(FOREST& forest, char ListName[]);
int LocateBiTree(FOREST forest, char ListName[]);
void ShowBiTree(FOREST forest);
status InitForest(FOREST& forest, char FileName[]);




int main()
{
    BiTree T = NULL;  int op = 1;
    FOREST forest;
    forest.length = 0;

    int i, j, e;
    int bitree_num = 0;
    int count = 0;
    char FileName[30], ListName[30];
    printf("\n\n");
    while (op) {
        system("cls");
        system("color F");
        printf("\t             Menu for BiTree Forest      \n");
        printf("\t-------------------------------------------------\n");
        printf("\t      1.AddBiTree            2.RemoveBiTree\n");
        printf("\t      3.LocateBiTree         4.ShowForest\n");
        printf("\t      5.enterBiTree          6.InitLists\n");
        printf("\t      7.CopyRight            0.exit\n");
        printf("\t    请选择你的操作[0~6]:");
        scanf("%d", &op);
        switch (op) {
        case 1:
            system("color A");
            printf("\t"); printf("\t"); scanf("%s", ListName);
            j = AddBiTree(forest, ListName);
            if (j)printf("\n\t\tsuccess!\n");
           system("pause"); 
            break;
        case 2:
            system("color 2");
            printf("\t"); printf("\t"); scanf("%s", ListName);
            j = RemoveBiTree(forest, ListName);
            if (j)printf("\n\t\tsuccess!\n");
            else printf("\n\t\tthe tree not exists!\n");
           system("pause"); 
            break;
        case 3:
            system("color 1");
            printf("\t"); printf("\t"); scanf("%s", ListName);
            j = LocateBiTree(forest, ListName);
            if (j)printf("\n\t\tit is %d tree!\n", j);
            else printf("\n\t\tthe tree not exits!\n");
           system("pause"); 
            break;
        case 4:
            system("color D");
            if (forest.length == 0)printf("\n\t\tno tree exists\n");
            else ShowBiTree(forest);
           system("pause"); 
            break;
        case 6:
            strcpy(FileName, "data.txt");
            InitForest(forest,FileName);
            printf("\n\t\tsuccess!\n");
            system("pause"); 
            break;          
        case 7:
            system("cls");
            ShowCopyRight();
            system("pause");
            break;

        case 5:
            system("color 3");
            if (forest.length == 0)
            {
                printf("\t\tthere is no BiTree in lists\n");
                break;
            }
            printf(" \t\tchoose a BiTree to operate!\n");
            while (bitree_num == 0)
            {
                printf("\t"); printf("\t"); scanf("%s", ListName);
                bitree_num = LocateBiTree(forest, ListName);
                if (bitree_num)T = forest.elem[bitree_num - 1].T;
                else printf("\t\tnot found!\n");
            }
            while (op) {
                system("cls");
                printf("operate list %s\n", forest.elem[bitree_num - 1].name);
                printf("\t      Menu for Linear Table On BiTree Structure \n");
                printf("\t-------------------------------------------------\n");
                printf("\t    	  1. InitBiTree           7. LocateNode\n");
                printf("\t    	  2. DestroyBiTree        8. GetSibling\n");
                printf("\t    	  3. ClearBiTree          9. InsertNode \n");
                printf("\t    	  4. BiTreeEmpty         10. DeleteNode\n");
                printf("\t    	  5. BiTreeDength        11. PreOrderTraverse\n");
                printf("\t    	  6. AssignNode          12. InOrderTraverse\n");
                printf("\t    	 13. PostOrderTraverse   14. LevelOrderTraverse\n");
                printf("\t    	 15. SaveBiTree          16. LoadList\n");
                printf("\t    	 17. CreateBiTree         0. Exit\n");
                printf("\t-------------------------------------------------\n");

                printf("\t    请选择你的操作[0~14]:");
                scanf("%d", &op);
                status temp;  KeyType e; BiTree node; int LR=0; int ans, i = 0; TElemType definition[100];
                TElemType value;
                switch (op) {
                case 1:
                    if (InitBiTree(forest.elem[bitree_num - 1].T) == OK)
                    {
                        printf("\t\tsuccess to init！\n");
                        T = forest.elem[bitree_num - 1].T;
                    }
                    else printf("\t\tfailed！\n");
                    system("pause"); break;
                case 2:
                    temp = DestroyBiTree(forest.elem[bitree_num - 1].T);
                    if (temp == OK)
                    {
                        printf("\n\t\tsuccess！\n");
                        T = NULL;
                    }
                    else if (temp == INFEASIBLE) printf("\n\t\tnot exits!\n");
                    else printf("\n\t\tfailed!\n");

                    system("pause"); break;
                case 3:
                    temp = ClearBiTree(T);
                    if (temp == OK)
                        printf("\n\t\tsuccess！\n");
                    else if (temp == INFEASIBLE)
                        printf("\n\t\tBiTree not exist\n");
                    else printf("\n\t\tfailed\n");
                    system("pause"); break;
                case 4:
                    temp = BiTreeEmpty(T);
                    if (temp == OK)
                        printf("\n\t\tempty！\n");
                    else if(temp == INFEASIBLE)
                        printf("\n\t\tBiTree not exist\n");
                    else printf("\n\t\tnot empty\n");

                    system("pause"); break;
                case 5:
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
                    printf("\t\tthe depth is %d\n", BiTreeDepth(T->next));

                    system("pause"); break;
                case 6:
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
                    printf("\t"); printf("\tthe key to change is "); scanf("%d", &e);
                    printf("\t"); printf("\tthe new key is "); scanf("%d", &value.key);
                    printf("\t"); printf("\tthe new value  is "); scanf("%s", value.others);
                    temp = Assign(T->next, e, value);
                    if (temp == OK)
                        printf("\t\tsuccess!\n");
                    else printf("\t\tfailed!\n");
                     

                    system("pause"); break;
                case 7:
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
                    printf("\t\tthe key is "); scanf("%d", &e);
                    node = LocateNode(T->next, e);
                    if (node == NULL)
                        printf("\n\t\tnot found！\n");
                    else
                    {
                        printf("\n\t\tthe key is %d\n", node->data.key);
                        printf("\t\tthe value is %s\n", node->data.others);
                    }

                    system("pause"); break;
                case 8:
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
    
                    printf("\t\tthe key is "); scanf("%d", &e);
                    node = GetSibling(T->next, e);
                    if (node == NULL)
                        printf("\n\t\tnot found！\n");
                    else
                    {
                        printf("\n\t\tthe sibling key is %d\n", node->data.key);
                        printf("\t\tthe sibling value is %s\n", node->data.others);
                    }

                    system("pause"); break;
                case 9:  
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
                    printf("\t\tthe parent key  is "); scanf("%d", &e);
                    printf("\t\twhich child want to be 0 for lchid 1 for rchild -1 for parent "); scanf("%d", &LR);
                    printf("\t\tthe new key is "); scanf("%d", &value.key);
                    printf("\t\tthe new value  is "); scanf("%s", value.others);
                    temp = InsertNode(T->next, e, LR,value);
                    if (temp == OK)
                        printf("\t\tsuccess!\n");
                    else printf("\t\tfailed!\n");


                    system("pause"); break;
                case 10:
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
                    printf("\t\tthe key for delete node is "); scanf("%d", &e);
                    temp  = DeleteNode(T->next, e);
                    if (temp == OK)
                        printf("\n\t\tsuccess to delete！\n");
                    else
                        printf("\t\tfailed\n");

                    system("pause"); break;
                case 11:
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
                    printf("\t\t");
                    PreOrderTraverse(T->next, visit);
                    printf("\n");
                    system("pause"); break;
                case 12:
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
                    printf("\t\t");
                    InOrderTraverse(T->next, visit);
                    printf("\n");
                    system("pause"); break;

                case 13:
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
                    printf("\t\t");
                    PostOrderTraverse(T->next, visit);
                    printf("\n");
                    system("pause"); break;

                case 14:
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
                    //printf("\t\t");
                    LevelOrderTraverse(T->next, visit);
                    printf("\n");
                    system("pause"); break;

                case 15:

                    strcpy(FileName, "save.txt");
                    temp = SaveBiTree(T, FileName);
                    if (temp == OK)printf("\n\t\tsuccess!\n");
                    else printf("\t\tfailed!\n");
                    system("pause"); break;


                case 16:
                    strcpy(FileName, "load.txt");
                    temp = LoadBiTree(forest.elem[bitree_num - 1].T, FileName);
                    if (temp == OK)
                    {
                        printf("\n\t\tsuccess!\n");
                        T = forest.elem[bitree_num - 1].T;
                    }
                    else printf("\t\tfailed!\n");
                    system("pause"); break;

                case 17:
                    
                    if (T == NULL)
                    {
                        printf("\t\tBiTree not exist!\n");
                        system("pause"); break;
                    }
                    
                    do {
                        printf("\t\t");
                        scanf("%d%s", &definition[i].key, definition[i].others);
                    } while (definition[i++].key != -1);
                    ans = CreateBiTree(T, definition);
                    if (ans == OK) printf("\n\t\t success!\n");
                    else printf("\n\t\t failed!\n");
                    system("pause"); break;

                case 0:
                    system("pause"); break;

                default:
                    system("pause"); break;
                }
            }
            op = 1;
            bitree_num = 0;
            break;
        case 0:
            break;
        }

    }


    printf("\t欢迎下次再使用本系统！\n");
}

status InitBiTree(BiTree& T)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{

    if (T != NULL)
        return INFEASIBLE;
    else
    {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->lchild = NULL;
        T->rchild = NULL;
        T->next = NULL;
        return OK;
    }


}

status CreateBiTree(BiTree& T, TElemType definition[])

/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。*/
{
    num = -1;
    if (T == NULL) return ERROR;
	if (isrepeat(definition))return ERROR;
	if (BuildTree(definition, T->next))return OK;
    return ERROR;
	
}

status DestroyBiTree(BiTree& T)
//将二叉树头结点设置成空，释放结点空间
{
    if (T)
    {
        Destroyhelper(T->next);
	    T = NULL;
	    return OK;
    }
    return INFEASIBLE;
}

status ClearBiTree(BiTree& T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    if (T)
    {
        Destroyhelper(T->next);
        T->next = NULL;
        return OK;
    }
    else
    {
        return INFEASIBLE;

    }
}

status BiTreeEmpty(BiTree T)
// 如果二叉链表存在，判断是否为空，空就返回TRUE，否则返回FALSE；如果不存在，返回INFEASIBLE。
{

    if (T == NULL)
        return INFEASIBLE;
    else
    {
        if (T->next== NULL)
            return OK;
        else
            return ERROR;
    }

}

int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
	int count_left = 0;
	int count_right = 0;
    int count = 0;
	if (T)
	{
		count_left = BiTreeDepth(T->lchild);
		count_right = BiTreeDepth(T->rchild);
		count = (count_left > count_right) ? count_left+1 : count_right+1;
	}
    return count;

}

BiTNode* LocateNode(BiTree T, KeyType e)
//查找结点
{
	BiTree result = NULL;
	if (T)
	{
		if (T->data.key == e) result = T;
		else
		{
			if (!result)result = LocateNode(T->lchild, e);
			if (!result)result = LocateNode(T->rchild, e);
		}
	}
	return result;
}


status Assign(BiTree& T, KeyType e, TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{

	BiTree p = NULL,node;
	p = LocateNode(T, e);
	node = LocateNode(T, value.key);
	if (p && (node == NULL || value.key == e))
	{
		p->data.key = value.key;
		strcpy(p->data.others, value.others);
		return OK;
	}
	return ERROR;

}

BiTNode* GetSibling(BiTree T, KeyType e)
//实现获得兄弟结点
{
	BiTree result = NULL;
	if (T->lchild || T->rchild)
	{
		if (T->lchild && T->lchild->data.key == e) result = T->rchild;
		else if (T->rchild && T->rchild->data.key == e) result = T->lchild;
		else
		{
			if (!result)result = GetSibling(T->lchild, e);
			if (!result)result = GetSibling(T->rchild, e);
		}
	}
	return result;

}

status InsertNode(BiTree& T, KeyType e, int LR, TElemType c)
//插入结点。此题允许通过增加其它函数辅助实现本关任务
{
	BiTree p,is_exist;
	p = LocateNode(T, e);
	if (!p || !c.key || e == c.key)
	{
		return ERROR;
	}
    is_exist = LocateNode(T, c.key);
    if (is_exist)
        return ERROR;
	BiTree new_node=NULL;
    InitBiTree(new_node);
	new_node->data.key = c.key;
	strcpy(new_node->data.others, c.others);
	if (LR == -1)
	{
		new_node->rchild = T;
		T = new_node;
	}
	else if (LR == 0)
	{
		new_node->rchild = p->lchild;
		p->lchild = new_node;
	}
	else if (LR == 1)
	{
		new_node->rchild = p->rchild;
		p->rchild = new_node;
	}
	else return ERROR;
	return OK;

}


status DeleteNode(BiTree& T, KeyType e)
{

	BiTree delete_node,parent,right_node;
	delete_node = LocateNode(T, e);
	if (!delete_node )return ERROR;
	parent = LocateParentNode(T, e);
	right_node = delete_node->lchild;
	if (right_node) {
		while (right_node->rchild)right_node = right_node->rchild;
	}

	if (T->data.key == e)
	{
		right_node->rchild=T->rchild;
		T = delete_node->lchild;
		free(delete_node);
		return OK;
	}
	if (delete_node->lchild && delete_node->rchild)
	{
		(delete_node == parent->lchild) ? parent->lchild = delete_node->lchild : parent->rchild = delete_node->lchild;
		right_node->rchild=delete_node->rchild;
		free(delete_node);
	}
	else if (!delete_node->lchild && !delete_node->rchild)
	{
		(delete_node == parent->lchild) ? parent->lchild = NULL : parent->rchild = NULL;
		free(delete_node);
	}
	else if (delete_node->lchild)
	{
		(delete_node == parent->lchild) ? parent->lchild = delete_node->lchild : parent->rchild = delete_node->lchild;
		free(delete_node);

	}
	else
	{
		(delete_node == parent->lchild) ? parent->lchild = delete_node->rchild : parent->rchild = delete_node->rchild;
		free(delete_node);
	}
	return OK;


}

status PreOrderTraverse(BiTree T, void (*visit)(BiTree))
//先序遍历二叉树T
{

	if (T)
	{
		visit(T);
		PreOrderTraverse(T->lchild, visit);
		PreOrderTraverse(T->rchild, visit);
	}
    return OK;
}

status InOrderTraverse(BiTree T, void (*visit)(BiTree))
//中序遍历二叉树T
{

	if (T)
	{

		InOrderTraverse(T->lchild, visit);
		visit(T);
		InOrderTraverse(T->rchild, visit);
	}
    return OK;
}


status PostOrderTraverse(BiTree T, void (*visit)(BiTree))
//后序遍历二叉树T
{

	if (T)
	{

		PostOrderTraverse(T->lchild, visit);
		PostOrderTraverse(T->rchild, visit);
		visit(T);
	}
    return OK;
}

status IsTwo(int num)
{

    while (num)
    {

        if (((num) & (num - 1)) == 0)
            return TRUE;
        break;
    }
    return FALSE;
}

status LevelOrderTraverse(BiTree T, void (*visit)(BiTree))
//按层遍历二叉树T
{

	BiTree temp[100];
	int i = 0, j = 0;
	temp[i++] = T;
    int depth = BiTreeDepth(T);
    int row = 1;
    int length = 8;
    for (int i = 1; i <= (pow(2,depth-row)-1)*length/2 ; i++)
        printf(" ");
	while (i > j)
	{
		if (temp[j])
		{
			visit(temp[j]);
			temp[i++] = temp[j]->lchild;
			temp[i++] = temp[j]->rchild;
		}
        else
        {
            for (int i = 1; i <= length; i++)
                printf(" ");
        }
        
        if (IsTwo(j + 2))
        {
            row++;
            printf("\n");
            for (int i = 1;  i <= (pow(2, depth - row) - 1) * length / 2; i++)
                printf(" ");
        }
        else
        {
           
            for (int i = 1;  i <= (pow(2, depth - row) - 1) * length ; i++)
                printf(" ");
        }
        
		j++;
	}

    return OK;
}


status SaveBiTree(BiTree T, char FileName[])
{
    if (T == NULL)
    {
        printf("\t\tBiTree not exist!\n");
        return ERROR;
    }
	FILE* fp;
	fp = fopen(FileName, "w");
	helper1(T->next, fp);
	fclose(fp);
	return 1;

}


status LoadBiTree(BiTree& T, char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
    if (T != NULL)
    {
        printf("\t\tBiTree exist!\n");
        return 0;
    }
    InitBiTree(T);
	FILE* fp;
	fp = fopen(FileName, "r");
	helper2(T->next, fp);
	fclose(fp);
	return 1;
}

status AddBiTree(FOREST& forest, char ListName[])
// 只需要在FOREST中增加一个名称为ListName的空二叉链表
{

    strcpy(forest.elem[forest.length].name, ListName);
    forest.elem[forest.length].T = NULL;
    forest.length++;
    return OK;
}

status RemoveBiTree(FOREST& forest, char ListName[])
// FOREST中删除一个名称为ListName的二叉链表
{

    int i = 0;
    while (strcmp(forest.elem[i].name, ListName) && i < forest.length)
    {
        i++;
    }
    if (i == forest.length - 1)
    {
        ClearBiTree(forest.elem[i].T);

    }
    else if (i < forest.length - 1)
    {
        FOREST p;
        p.elem[0] = forest.elem[i];
        for (int j = forest.length - 1; j > i; j--)
        {
            forest.elem[j - 1] = forest.elem[j];
        }
        forest.elem[forest.length - 1] = p.elem[0];
        ClearBiTree(forest.elem[forest.length - 1].T);
        strcpy(forest.elem[forest.length - 1].name, " ");

    }
    else
        return ERROR;

    forest.length--;
    return OK;


}

int LocateBiTree(FOREST forest, char ListName[])
// 在FOREST中查找一个名称为ListName的二叉链表，成功返回逻辑序号，否则返回0
{

    int i = 0;
    while (strcmp(forest.elem[i].name, ListName) && i < forest.length)
    {
        i++;
    }
    if (i == forest.length)
        return 0;
    else
        return i + 1;

}

void ShowBiTree(FOREST forest)
{
    for (int i = 0; i < forest.length; i++)
    {
        printf("\t\t%s  ", forest.elem[i].name);
        printf("\n");
    }
}
status InitForest(FOREST& forest,char FileName[])
{
    int num = 0; char ch[10];
    FILE* fp;
    fp = fopen(FileName, "r");
    fscanf(fp, "%d", &num);
    forest.length = num;
    for (int i = 0; i < forest.length; i++)
    {
        forest.elem[i].T = NULL;
        fscanf(fp, "%s", forest.elem[i].name);
        InitBiTree(forest.elem[i].T);
        helper2(forest.elem[i].T->next, fp);
        fscanf(fp, "%d", &num);
        fscanf(fp, "%s", ch);
    }
    
    fclose(fp);
    return 1;
}