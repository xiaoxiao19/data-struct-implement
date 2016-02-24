//双向链表：实现双向链表的增删改查

#include <stdio.h>
#include <stdlib.h>

typedef struct sqlist
{
    int data;
    struct sqlist *prior;
    struct sqlist *next;
}Sqlist;

void init_list(Sqlist *L)
{
    L = (Sqlist *)malloc(sizeof(Sqlist));
    L->prior = NULL;
    L->next = NULL;
}

//向链表中插入数据，插入值为0时则停止
void insert_list(Sqlist *L)
{
    int i;
    printf("请输入链表中的数据：\n");
    scanf("%d",&i);

    while(i != 0)
    {
        if(i != 0)
        {
            L->data = i;
            L->next = (Sqlist *)malloc(sizeof(Sqlist));
            L->next->prior = L;
            L->next->next = NULL;
            L = L->next;
        }
        scanf("%d",&i);
    }
}

//向链表中的任一位置插入数据
void insert_list_1(Sqlist *L,int local)
{

}

//???
void delete_list(Sqlist *L,int local)
{
    
}

void print_list(Sqlist *L)
{
    printf("链表中的数据为：\n");
    while(L->next != NULL)
    {
        printf("%d  ",L->data);
        L = L->next;//陷入死循环
    }
    printf("\n");
}

int main()
{
    Sqlist L;
    init_list(&L);
    insert_list(&L);
    print_list(&L);

    return 0;
}