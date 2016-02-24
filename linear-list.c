//此程序为线性表的顺序存储结构的实现

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define OK 1
#define ERROR -1
#define MAX_SIZE 100

typedef int Status;
typedef int ElemType;

typedef struct sqlist{
    int *elem_arry;
    int length;
}Sqlist;

//顺序表的初始化
Status init_sqlist(Sqlist *L)
{
    L->elem_arry = (int *)malloc(MAX_SIZE*sizeof(int));
    if(!L->elem_arry)
        return ERROR;
    else
    {
        L->length = 0;
        return OK;    
    }
}

//向顺序表中插入数据
void insert_sqlist(Sqlist *L,int s)
{
    if(L->length >MAX_SIZE)
        printf("该顺序表空间不足！\n");
    else
        L->elem_arry[L->length++] = s;
}

//向顺序表中删除数据
void delete_list(Sqlist *L,int local)
{
    int i = 0;
    if(local < 0|| local>L->length)
        printf("不存在这个数据！\n");
    else
    {
        for(i=local;i<L->length;i++)
            L->elem_arry[i] = L->elem_arry[i+1];
    }
    L->length--;
}

//向顺序表中的某一个位置的数值修改成指定值
void modify_list(Sqlist *L,int local,int s)
{
    L->elem_arry[local] = s;
}
//输出数组中的数值
void print_list(Sqlist *L)
{
    int i = 0;
    printf("顺序表中的数据为：\n");
    for(i = 0;i<L->length;i++)
    {
        printf("%d  ",L->elem_arry[i]);
    }
    printf("\n");
}

int main()
{
    Sqlist L;
    int a;
    int number;
    int i;
    init_sqlist(&L); 
    
    printf("请输入要插入的数值数目：\n");
    scanf("%d",&number);
    printf("请输入要插入的数值：\n");
    for(i=0;i<number;i++)
    {
        setbuf(stdin,NULL);
        scanf("%d",&a);
        insert_sqlist(&L,a);
    }
    print_list(&L);

    delete_list(&L,1);
    print_list(&L);

    modify_list(&L,1,2);
    print_list(&L);

    return 0;
}