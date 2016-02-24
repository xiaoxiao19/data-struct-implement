
//栈的动态顺序存储实现

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct sqstack
{
    int *base;
    int *top;
    int stacksize;
}Sqstack;

void init_stack(Sqstack *s)
{
    (*s).top = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    s->base = s->top;
    s->stacksize = STACK_INIT_SIZE;
}

void push(Sqstack *s,int m)
{
    if(s->top - s->base >= s->stacksize)
    {
        s->base = (int *)realloc(s->base,(s->stacksize +                 STACKINCREMENT) * sizeof(int));
        s->top = s->base + s->stacksize;
        s->stacksize += STACKINCREMENT;
    }
    *s->top = m;
    s->top++;
}

void pop(Sqstack *s)
{
    if(s->top == s->base)
        return 0;
    s->top--;
}

void print_stack(Sqstack *s)
{
    int *q;
    q = s->top;//注意这里，是对s->top赋值，而不是对s
    while(q != s->base)//判断条件是top指针和base指针指向的不是同一个单元
    {
        printf("%d  ",*q);
        q--;
    }
    printf("%d  ",*q);
    printf("\n");    
}

int main()
{
    int data;
    Sqstack *s;
    s = (Sqstack *)malloc(sizeof(Sqstack));
    init_stack(s);
    
    scanf("%d",&data);
    while(data != 0)
    {
        push(s,data);
        scanf("%d",&data);
    }

    print_stack(s);
    
    pop(s);
    print_stack(s);

    return 0;    
}