//栈的静态顺序存储实现

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct sqstack
{
    int *stack_arry;
    int top;
}Sqstack;

void init_stack(Sqstack *s)
{
    s->stack_arry = (int *)malloc(MAXSIZE * sizeof(int));
    s->top = 0;
}

int push(Sqstack *s,int m)
{
    if(s->top > MAXSIZE)
        return 0;
    s->stack_arry[s->top] = m;
    s->top++;
}

int pop(Sqstack *s)
{
    if(s->top < 0)
        return 0;
    //s->stack_arry--;
    s->top--;
}

void print_stack(Sqstack *s)
{
    int i;
    for(i=0;i<s->top;i++)
    {
        printf("%d  ",s->stack_arry[i]);
    }
    printf("\n");
}


int main()
{
    int data;
    Sqstack s;
    init_stack(&s);

    scanf("%d",&data);
    while(data != 0)
    {
        push(&s,data);
        scanf("%d",&data);
    }

    print_stack(&s);

    pop(&s);
    print_stack(&s);

    return 0;
}