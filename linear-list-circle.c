//此程序为线性链表

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct sqlist
{
    int data;
    struct sqlist *next;
}Sqlist; 

//链表的初始化
void init_list(Sqlist *L)
{
    L = (Sqlist *)malloc(sizeof(Sqlist));
    L->next = L;
}

//向链表中插入数据,末尾插入，当插入数据为0时停止插入数据
void insert_list(Sqlist *L)
{
    int data;
    Sqlist *p;
    p = L;
    data = 1;
    while(data != 0)
    {
        scanf("%d",&data);
        if(data != 0)
        {
            L->next = (Sqlist *)malloc(sizeof(Sqlist));
            L = L->next;
            L->data = data;
        }
        else
        {
            L->next = p;
        }
    }
}

//删除链表中某一位置的数据:在使用链表插入和删除数据时，要首先查找位置
void delete_list(Sqlist *L,int local)
{
    int j = 1;
    L = L->next;
    Sqlist *q = L;
    while(j < local)
    {
        q = q->next;
        j++;
    }
    L->next = q->next;
    free(q);
}

//向链表中的某一个位置前插入一个数据
void insert(Sqlist *L,int local,int e)
{
    int j = 1;
    L = L->next;
    Sqlist *q = L;
    Sqlist *p;
    while(j < local)
    {
        q = q->next;
        j++;
    }
    p = (Sqlist *)malloc(sizeof(Sqlist));
    p->data = e;
    
    L->next = p;
    p->next = q;
}

//打印链表中的数据
void print_list(Sqlist *L)
{
    Sqlist *p;
    p = L;
    L = L->next;
    printf("链表中包含的数据有：\n");

    while(L != p)
    {
        printf("%d  ",L->data);
        L = L->next;
    }
    printf("\n");
}

int main()
{
    Sqlist L1;
    init_list(&L1);
    insert_list(&L1);
    print_list(&L1);

    delete_list(&L1,2);
    print_list(&L1);

    insert(&L1,2,2);
    print_list(&L1);

    return 0;
}