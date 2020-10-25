#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct {  //˳���˳��ṹ���Ķ���
	ElemType* elem;
	int length;
	int listsize;
}SqList;

typedef struct {  //���Ա�Ĺ������
    struct {
        char name[30];
        SqList L;
    } elem[10];
    int length;
    int listsize;
}LISTS;

status InitList(SqList& L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{

    if (L.elem != NULL)
        return INFEASIBLE;
   // L.elem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;

}

status DestroyList(SqList& L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        L.listsize = 0;
        return OK;
    }

}

status ClearList(SqList& L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        L.length = 0;
        return OK;
    }

}

status ListEmpty(SqList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{

    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        if (L.length == 0)
            return TRUE;
        else
            return FALSE;
    }

}

status ListLength(SqList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{

    if (L.elem == NULL)
        return INFEASIBLE;
    else
        return L.length;

}


status  SaveList(SqList L, char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{

    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        FILE* fp;
        fp = fopen(FileName,"w");
        for (int i = 0; i < L.length; i++)
        {
            fprintf(fp, "%d ", L.elem[i]);
        }
        fclose(fp);
        return OK;
    }

}

status GetElem(SqList L, int i, ElemType& e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        if (i > L.length || i <= 0)
            return ERROR;
        else
        {
            e = L.elem[i - 1];
            return OK;
        }
    }

}

status LocateElem(SqList L, ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų�����OK�����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{

    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        int i;
        for (i = 0; i < L.length; i++)
        {
            if (L.elem[i] == e)
                return i + 1;
        }
        return ERROR;
    }

}

status PriorElem(SqList L, ElemType e, ElemType& pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        int i;
        for (i = 0; i < L.length; i++)
        {
            if (L.elem[i] == e)
                break;
        }
        if (i > 0 && i < L.length)
        {
            pre = L.elem[i - 1];
            return OK;
        }
        else
            return ERROR;
    }

}


status NextElem(SqList L, ElemType e, ElemType& next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        int i;
        for (i = 0; i < L.length; i++)
        {
            if (L.elem[i] == e)
                break;
        }
        if (i < L.length - 1)
        {
            next = L.elem[i + 1];
            return OK;
        }
        else
            return ERROR;
    }

}

status  LoadList(SqList& L, char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    if (L.elem != NULL)
        return INFEASIBLE;
    else
    {
        FILE* fp;
        fp = fopen(FileName, "r");
        int i = 0;
        L.elem = (ElemType*)malloc((LIST_INIT_SIZE) * sizeof(ElemType));
        while (fscanf(fp, "%d", L.elem + i) != EOF)
        {
              i++;
              L.length++;
        }
           
        fclose(fp);
        return OK;
        
    }
}

status ListInsert(SqList& L, int i, ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
 
    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        if (L.length >= L.listsize)
        {
            ElemType* newelem;
            newelem = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
            L.elem = newelem;
            L.listsize += LISTINCREMENT;
        }
        if (i<1 || i>L.length + 1)
            return ERROR;
        else
        {
            if (i < L.length)
            {
                for (int j = L.length - 1; j >= i - 1; j--)
                    L.elem[j + 1] = L.elem[j];

            }
            L.elem[i - 1] = e;
            L.length++;
            return OK;
        }
    }

}

status ListDelete(SqList& L, int i, ElemType& e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{

    if (L.elem == NULL || L.length == 0)
        return INFEASIBLE;
    else
    {
        if (i<1 || i>L.length)
            return ERROR;
        e = L.elem[i - 1];
        if (i < L.length)
        {
            for (int k = i; k < L.length; k++)
            {
                L.elem[k - 1] = L.elem[k];
            }
        }
        L.length--;
        return OK;
    }


}

status ListTraverse(SqList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    if (L.elem == NULL)
        return INFEASIBLE;
    else
    {
        if (L.length == 0)
            return FALSE;
        else
        {
            int i;
            for (i = 0; i < L.length - 1; i++)
            {
                printf("%d ", L.elem[i]);
            }
            printf("%d", L.elem[i]);
            return OK;
        }

    }


}

status AddList(LISTS& Lists, char ListName[])
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
{
  
    strcpy(Lists.elem[Lists.length].name,ListName);
    Lists.elem[Lists.length].L.elem = NULL;
    InitList(Lists.elem[Lists.length].L);
    Lists.length++;
    return OK;
}


status RemoveList(LISTS& Lists, char ListName[])
// Lists��ɾ��һ������ΪListName�����Ա�
{

    int i=0;
    while (strcmp(Lists.elem[i].name,ListName) &&i<Lists.length)
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
            Lists.elem[j - 1]= Lists.elem[j];
        }
        Lists.elem[Lists.length - 1] = p.elem[0];
        DestroyList(Lists.elem[Lists.length - 1].L);

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

int main() {
    SqList L;  int op = 1;
    LISTS Lists;
    L.elem = NULL;
    L.length = 0;
    Lists.length = 0;
    int i, j, e;
    int num;
    char FileName[30],ListName[30];
    system("cls");	printf("\n\n");
    while (op) {
        
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitList       7. LocateElem\n");
        printf("    	  2. DestroyList    8. PriorElem\n");
        printf("    	  3. ClearList      9. NextElem \n");
        printf("    	  4. ListEmpty      10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem        12. ListTrabverse\n");
        printf("    	  13. SaveList      14. LoadList\n");
        printf("    	  15. AddList       16. RemoveList\n");
        printf("    	  17. LocateList    0. Exit\n");
        printf("-------------------------------------------------\n");
        if (Lists.length > 0)
        {
            printf("�Եڼ������Ա���в�����");
            scanf("%d", &num);
        }
        printf("    ��ѡ����Ĳ���[0~17]:");
        scanf("%d", &op);
        switch (op) {
        case 1:
            //printf("\n----IntiList���ܴ�ʵ�֣�\n");
            if (InitList(Lists.elem[num - 1].L) == OK) printf("���Ա����ɹ���\n");
            else printf("���Ա���ʧ�ܣ�\n");
            break;
        case 2:
            DestroyList(Lists.elem[num - 1].L);
            printf("\nsuccess��\n");
            
            break;
        case 3:
            ClearList(Lists.elem[num - 1].L);
            printf("\nsuccess��\n");
           
            break;
        case 4:
            if (ListEmpty(Lists.elem[num - 1].L))
                printf("\nempty��\n");
            else printf("\nnot empty\n");
           
            break;
        case 5:
             i = ListLength(Lists.elem[num - 1].L);
            if (i < 0)
                printf("\nnot exits��\n");
            else
                printf("%d", i);
            
            break;
        case 6:
          
            scanf("%d", &i);
            j = GetElem(Lists.elem[num - 1].L, i, e);
            if(j<0)
            printf("\nList not exits��\n");
            else
            {
                if (j == 0)
                    printf("\n out of range\n");
                else
                    printf("\n %d\n", e);
            }
           
            break;
        case 7:
            scanf("%d", &e);
            j = LocateElem(Lists.elem[num - 1].L, e);
            if (j < 0)
                printf("\nList not exits��\n");
            else
            {
                if (j == 0)
                    printf("\ndata out of range\n");
                else
                    printf("\nthe location is %d\n", e);
            }
           
            break;
        case 8:
            int pre;
            scanf("%d", &e);
            j = PriorElem(Lists.elem[num - 1].L, e,pre);
            if (j < 0)
                printf("\nList not exits��\n");
            else
            {
                if (j == 0)
                    printf("\nthere is no prior elem\n");
                else
                    printf("\nthe prior is %d\n", pre);
            }
            
            break;
        case 9:
            int  next;
            scanf("%d", &e);
            j = NextElem(Lists.elem[num - 1].L, e, next);
            if (j < 0)
                printf("\nList not exits��\n");
            else
            {
                if (j == 0)
                    printf("\nthere is no next elem\n");
                else
                    printf("\nthe next is %d\n", next);
            }
           
            break;
        case 10:
          
            scanf("%d", &i);
            scanf("%d", &e);
            j = ListInsert(Lists.elem[num - 1].L, i, e);
            if (j < 0)
                printf("\nList not exits��\n");
            else
            {
                if (j == 0)
                    printf("\nwrong index!\n");
                else
                    printf("\nsuccess!\n");
            }
          
            break;
        case 11:
            
            scanf("%d", &i);
            j = ListDelete(Lists.elem[num - 1].L, i, e);
            if (j < 0)
                printf("\nList not exits��\n");
            else
            {
                if (j == 0)
                    printf("\nwrong index!\n");
                else
                    printf("\nsuccess!\n");
            }
           
            break;
        case 12:
            j=ListTraverse(Lists.elem[num - 1].L);
            if (!j) printf("���Ա��ǿձ�\n");
            if (j < 0)printf("\nlist not exits!\n");
           
            break;
        case 13:
            
            strcpy(FileName, "lst.txt");
             j = SaveList(Lists.elem[num-1].L, FileName);
            if (j == INFEASIBLE)printf("\nList not exits!\n");
            else printf("\nsuccess!\n");
            break;
           

        case 14:
            
            int j;
            strcpy(FileName, "list.txt");
            j = LoadList(Lists.elem[num - 1].L, FileName);
            if (j == INFEASIBLE) printf("\nINFEASIBLE\n��");
            else printf("\nsuccess\n");
            break;

        case 15:
            scanf("%s", ListName);
            j=AddList(Lists, ListName);
            if (j)printf("\nsuccess!\n");
            break;

        case 16:
            scanf("%s", ListName);
            j = RemoveList(Lists, ListName);
            if (j)printf("\nsuccess!\n");
            else printf("\nthe list not exits!\n");
            break;

        case 17:
            scanf("%s", ListName);
            j = LocateList(Lists, ListName);
            if (j)printf("\nit is %d list!\n",j);
            else printf("\nthe list not exits!\n");
            break;

        case 0:
            break;

        }//end of switch
    }//end of while
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()