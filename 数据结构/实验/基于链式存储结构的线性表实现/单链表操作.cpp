#include"linklist.h"



status InitList(LinkList& L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{

    if (L != NULL)
        return INFEASIBLE;
    else
    {
        L = (LNode*)malloc(sizeof(LNode));
        L->next = NULL;
        return OK;
    }


}

status DestroyList(LinkList& L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{

    LinkList p = L;
    if (L == NULL)
        return INFEASIBLE;
    else
    {
        while (L != NULL)
        {
            p = p->next;
            free(L);
            L = p;
        }
        return OK;
    }

}



status ClearList(LinkList& L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{

    LinkList p = L, q;
    if (L == NULL)
        return -1;
    else
    {
        q = L->next;
        while (q != NULL)
        {
            p = q->next;
            free(q);
            q = p;
        }
        L->next = NULL;
        return OK;
    }


}

status ListEmpty(LinkList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{

    if (L == NULL)
        return INFEASIBLE;
    else
    {
        if (L->next == NULL)
            return OK;
        else
            return ERROR;
    }

}
int ListLength(LinkList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{

    LinkList p;
    int i = 0;
    if (L == NULL)
        return INFEASIBLE;
    else
    {
        p = L->next;
        while (p != NULL)
        {
            i++;
            p = p->next;
        }
        return i;
    }


}

status GetElem(LinkList L, int i, ElemType& e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    LinkList p;
    int j = 0;
    if (L == NULL)
        return INFEASIBLE;
    else
    {
        p = L->next;
        while (p != NULL)
        {
            j++;

            if (j == i)
            {
                e = p->data;
                break;
            }
            p = p->next;
        }
        if (j < i || i < 1)return ERROR;
        return OK;
    }


}

status LocateElem(LinkList L, ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{

    LinkList p;
    int j = 0;
    if (L == NULL)
        return INFEASIBLE;
    else
    {
        p = L->next;
        while (p != NULL)
        {
            j++;
            if (e == p->data)break;
            p = p->next;
        }
        if (p == NULL)return ERROR;
        return j;
    }

}
status PriorElem(LinkList L, ElemType e, ElemType& pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    LinkList p, q;
    if (L == NULL)
        return INFEASIBLE;
    else
    {
        p = L->next;
        q = L;
        while (p != NULL)
        {
            if (e == p->data)
            {
                pre = q->data;
                break;
            }
            p = p->next;
            q = q->next;
        }
        if (p == NULL || q == L)return ERROR;
        return OK;
    }

}

status NextElem(LinkList L, ElemType e, ElemType& next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    LinkList p;
    if (L == NULL)
        return INFEASIBLE;
    else
    {
        p = L->next;
        while (p != NULL)
        {
            if (e == p->data && p->next != NULL)
            {
                next = p->next->data;
                break;
            }
            p = p->next;
        }
        if (p == NULL)return ERROR;
        return OK;
    }

}
status ListInsert(LinkList& L, int i, ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    LinkList p, newnode;
    int j = 0;
    if (L == NULL)
        return INFEASIBLE;
    else
    {
        p = L;
        while (p != NULL && j < i - 1)
        {
            j++;
            p = p->next;
        }
        if (p == NULL || i < 0)return ERROR;
        newnode = (LNode*)malloc(sizeof(LNode));
        newnode->data = e;
        newnode->next = p->next;
        p->next = newnode;
        return OK;
    }

}
status ListDelete(LinkList& L, int i, ElemType& e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    LinkList p, q;
    int j = 0;
    if (L == NULL)
        return INFEASIBLE;
    else
    {
        p = L;
        while (p != NULL && j < i - 1)
        {
            j++;
            p = p->next;
        }
        if (p == NULL || i < 1)return ERROR;
        e = p->next->data;
        q = p->next;
        p->next = p->next->next;
        free(q);
        return OK;
    }

}
status ListTraverse(LinkList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{

    LinkList p;
    if (L == NULL)
        return INFEASIBLE;
    else
    {
        p = L->next;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        return OK;
    }

}
status SaveList(LinkList L, char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{

    if (L == NULL)
        return INFEASIBLE;
    else
    {
        FILE* fp;
        LinkList p;
        fp = fopen(FileName, "w");
        for (p = L->next; p != NULL; p = p->next)
        {
            fprintf(fp, "%d ", p->data);
        }
        fclose(fp);
        return OK;
    }

}
status LoadList(LinkList& L, char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{

    if (L != NULL)
        return INFEASIBLE;
    else
    {
        FILE* fp;
        fp = fopen(FileName, "r");
        LinkList p=NULL, q = NULL;
        int i;
        L = (LNode*)malloc(sizeof(LNode));
        q = L;
        q->next = p;
        printf("\t");
        while (fscanf(fp, "%d", &i) != EOF)
        {
            p = (LNode*)malloc(sizeof(LNode));
            p->data = i;
            p->next = NULL;
            q->next = p;
            q = p;
            printf("\t");
        }
        fclose(fp);
        return OK;

    }

}

status AddList(LISTS& Lists, char ListName[])
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
{

    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.elem[Lists.length].L = NULL;
    Lists.length++;
    return OK;
}

status RemoveList(LISTS& Lists, char ListName[])
// Lists��ɾ��һ������ΪListName�����Ա�
{

    int i = 0;
    while (strcmp(Lists.elem[i].name, ListName) && i < Lists.length)
    {
        i++;
    }
    if (i == Lists.length - 1)
    {
        DestroyList(Lists.elem[i].L);

    }
    else if (i < Lists.length - 1)
    {
        LISTS p;
        p.elem[0] = Lists.elem[i];
        for (int j = Lists.length - 1; j > i; j--)
        {
            Lists.elem[j - 1] = Lists.elem[j];
        }
        Lists.elem[Lists.length - 1] = p.elem[0];
        DestroyList(Lists.elem[Lists.length - 1].L);
        strcpy(Lists.elem[Lists.length - 1].name, " ");

    }
    else
        return ERROR;

    Lists.length--;
    return OK;


}
int LocateList(LISTS Lists, char ListName[])
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{

    int i = 0;
    while (strcmp(Lists.elem[i].name, ListName) && i < Lists.length)
    {
        i++;
    }
    if (i == Lists.length)
        return 0;
    else
        return i + 1;

}

void show_lists(LISTS Lists)
{
    for (int i = 0; i < Lists.length; i++)
    {
        printf("\t\t%s  ", Lists.elem[i].name);
        printf("\n");
    }
}


int main() {
    LinkList L=NULL;  int op = 1;
    LISTS Lists;
    Lists.length = 0;
   
    int i, j, e;
    int list_num=0;
    int count = 0;
    char FileName[30], ListName[30];
    printf("\n\n");
    ifstream in("C:/Users/Dominery/source/repos/������/data1.txt");
    while (op) {
        system("cls");
        system("color F");
        printf("\t             Menu for Assembled lists      \n");
        printf("\t-------------------------------------------------\n");
        printf("\t      1.AddList              2.RemoveLists\n");
        printf("\t      3.LocateList           4.ShowList\n");
        printf("\t      5.enterList            6.InistLists\n");
        printf("\t      0.exit\n");
        printf("\t    ��ѡ����Ĳ���[0~6]:");
        scanf("%d", &op);
        switch (op) {
        case 1:
            system("color 3");
            printf("\t");printf("\t");scanf("%s", ListName);
            j = AddList(Lists, ListName);
            if (j)printf("\n\t\tsuccess!\n");
            getchar(); getchar();
            break;
        case 2:
            system("color 2");
            printf("\t");printf("\t");scanf("%s", ListName);
            j = RemoveList(Lists, ListName);
            if (j)printf("\n\t\tsuccess!\n");
            else printf("\n\t\tthe list not exits!\n");
            getchar(); getchar();
            break;
        case 3:
            system("color 1");
            printf("\t");printf("\t");scanf("%s", ListName);
            j = LocateList(Lists, ListName);
            if (j)printf("\n\t\tit is %d list!\n", j);
            else printf("\n\t\tthe list not exits!\n");
            getchar(); getchar();
            break;
        case 4:
            system("color D");
            if (Lists.length == 0)printf("\n\t\tno lists exit\n");
            else show_lists(Lists);
            getchar(); getchar();
            break;
        case 6:
            int n;
            in >> n;
            while (n-- != 0) {
                in >> Lists.elem[Lists.length++].name;
                InitList(Lists.elem[Lists.length - 1].L);
                LinkList q = nullptr;              int t;
                while (in >> t && t != 0) {
                    Lists.elem[Lists.length - 1].len++;
                    auto p = (LinkList)malloc(sizeof(LNode));
                    if (q) {
                        p->data = t;
                        p->next = q->next;
                        q->next = p;
                        q = p;
                    }
                    else {
                        Lists.elem[Lists.length - 1].L = p;
                        q = p;
                        q->next = nullptr;
                    }
                }
            }
            getchar();
            break;
        case 5: 
            system("color A");
            if (Lists.length == 0)
            {
                printf("\t\tthere is no list in lists\n");
                break;
            }
            printf(" \t\tchoose a list to operate!\n");
            while (list_num == 0)
            {
                printf("\t");printf("\t");scanf("%s", ListName);
                list_num = LocateList(Lists, ListName);
                if (list_num)L = Lists.elem[list_num - 1].L;
                else printf("\t\tnot found!\n");
            }
            while (op) {
                system("cls");
                printf("operate list %s\n", Lists.elem[list_num - 1].name);
                printf("\t      Menu for Linear Table On Linked Structure \n");
                printf("\t-------------------------------------------------\n");
                printf("\t    	  1. InitList       7. LocateElem\n");
                printf("\t    	  2. DestroyList    8. PriorElem\n");
                printf("\t    	  3. ClearList      9. NextElem \n");
                printf("\t    	  4. ListEmpty      10. ListInsert\n");
                printf("\t    	  5. ListLength     11. ListDelete\n");
                printf("\t    	  6. GetElem        12. ListTrabverse\n");
                printf("\t    	  13. SaveList      14. LoadList\n");
                printf("\t    	  0. Exit\n");
                printf("\t-------------------------------------------------\n");
           
                printf("\t    ��ѡ����Ĳ���[0~14]:");
                scanf("%d", &op);
                switch (op) {
                case 1:
                    //printf("\n----IntiList���ܴ�ʵ�֣�\n");
                    if (InitList(L) == OK) printf("\t\t���Ա����ɹ���\n");
                    else printf("\t\t���Ա���ʧ�ܣ�\n");
                    getchar(); getchar(); break;
                case 2:
                    if (DestroyList(L) == OK) printf("\n\t\tsuccess��\n");
                    else printf("\n\t\tfailed!\n");
                    getchar(); getchar();break;
                case 3:
                    if (ClearList(L) == OK) printf("\n\t\tsuccess��\n");
                    else printf("\n\t\tfailed!\n");
                    getchar(); getchar();break;
                case 4:
                    if (ListEmpty(L))
                        printf("\n\t\tempty��\n");
                    else printf("\n\t\tnot empty\n");

                    getchar(); getchar();break;
                case 5:
                    i = ListLength(L);
                    if (i < 0)
                        printf("\n\t\tnot exits��\n");
                    else
                        printf("\t\t%d\n", i);

                    getchar(); getchar();break;
                case 6:

                    printf("\t");printf("\t");scanf("%d", &i);
                    j = GetElem(L, i, e);
                    if (j < 0)
                        printf("\n\t\tList not exits��\n");
                    else
                    {
                        if (j == 0)
                            printf("\n\t\tout of range\n");
                        else
                            printf("\n\t\t%d\n", e);
                    }

                    getchar(); getchar();break;
                case 7:
                    printf("\t\t");scanf("%d", &e);
                    j = LocateElem(L, e);
                    if (j < 0)
                        printf("\n\t\tList not exits��\n");
                    else
                    {
                        if (j == 0)
                            printf("\n\t\tdata out of range\n");
                        else
                            printf("\n\t\tthe location is %d\n", j);
                    }

                    getchar(); getchar();break;
                case 8:
                    int pre;
                    printf("\t\t");scanf("%d", &e);
                    j = PriorElem(L, e, pre);
                    if (j < 0)
                        printf("\n\t\tList not exits��\n");
                    else
                    {
                        if (j == 0)
                            printf("\n\t\tthere is no prior elem\n");
                        else
                            printf("\n\t\tthe prior is %d\n", pre);
                    }

                    getchar(); getchar();break;
                case 9:
                    int  next;
                    printf("\t\t");scanf("%d", &e);
                    j = NextElem(L, e, next);
                    if (j < 0)
                        printf("\n\t\tList not exits��\n");
                    else
                    {
                        if (j == 0)
                            printf("\n\t\tthere is no next elem\n");
                        else
                            printf("\n\t\tthe next is %d\n", next);
                    }

                    getchar(); getchar();break;
                case 10:

                    printf("\t\tplease enter the index:");scanf("%d", &i);
                    printf("\t\tplease enter the number");scanf("%d", &e);
                    j = ListInsert(L, i, e);
                    if (j < 0)
                        printf("\n\t\tList not exits��\n");
                    else
                    {
                        if (j == 0)
                            printf("\n\t\twrong index!\n");
                        else
                            printf("\n\t\tsuccess!\n");
                    }

                    getchar(); getchar();break;
                case 11:

                    printf("\t\t");scanf("%d", &i);
                    j = ListDelete(L, i, e);
                    if (j < 0)
                        printf("\n\t\tList not exits��\n");
                    else
                    {
                        if (j == 0)
                            printf("\n\t\twrong index!\n");
                        else
                            printf("\n\t\tsuccess!\n");
                    }

                    getchar(); getchar();break;
                case 12:
                    printf("\t\t");
                    j = ListTraverse(L);
                    if (!j) printf("\t\t���Ա��ǿձ�\n");
                    if (j < 0)printf("\n\t\tlist not exits!\n");
                    printf("\n");

                    getchar(); getchar();break;
                case 13:

                    strcpy(FileName, "lst.txt");
                    j = SaveList(L, FileName);
                    if (j == INFEASIBLE)printf("\n\t\tList not exits!\n");
                    else printf("\n\t\tsuccess!\n");
                    getchar(); getchar();break;


                case 14:

                    int j;
                    strcpy(FileName, "list.txt");
                    j = LoadList(L, FileName);
                    if (j == INFEASIBLE) printf("\n\t\tINFEASIBLE��\n");
                    else printf("\n\t\tsuccess\n");
                    getchar(); getchar();break;
                case 0:
                    getchar(); getchar();break;
                default:
                    getchar(); getchar();break;
                }
            }
            op = 1;
            list_num = 0;
            break;
        case 0:
            break;
        }
        
    }

    
    printf("\t��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()