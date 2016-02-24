//栈的链式存储实现：入栈，出栈，判空，取栈顶元素

#include <stdio.h>
#include <stdlib.h>

typedef struct sqstack
{
    int data;
    struct sqstack *next;
}Sqstack;

Sqstack *init_stack(Sqstack *top)
{
    top = NULL;
    return top;
}

//元素进栈:返回栈顶元素(入栈和出栈操作都是在栈顶进行的:新插入的元素为栈顶元素)
//也就相当于在线性表的前边插入
Sqstack *push(Sqstack *top,int m)
{
    Sqstack *s;
    s = (Sqstack *)malloc(sizeof(Sqstack));
    s->data = m;
    s->next = top;
    top = s;
    return top;
}

//元素出栈:重新设置栈顶指针
Sqstack *pop(Sqstack *top)
{
    Sqstack *s;
    s = top;
    printf("出栈元素为：\n");
    printf("%d\n",s->data);
    top = top->next;
    free(s);
    return top;
}

//打印栈中的元素，这里的*s是为了不改变top指针指向的位置
void print_stack(Sqstack *top)
{
    Sqstack *s;
    s = top;
    printf("栈中元素为：\n");
    while(s->next != NULL)
    {
        printf("%d",s->data);
        s = s->next;
    }
    printf("%d  ",s->data);
    printf("\n");
}

void print_stacktop(Sqstack *top)
{
    printf("栈顶元素为：\n");
    printf("%d  ",top->data);
    printf("\n");
}

int main()
{
    int m = 1;
    Sqstack *top;
    top = (Sqstack *)malloc(sizeof(Sqstack));
    top = init_stack(top);

    scanf("%d",&m);
    while(m != 0)
    {
        top = push(top,m);
        scanf("%d",&m);
    }


    print_stack(top);
    print_stacktop(top);

    top = pop(top);
    print_stack(top);
    print_stacktop(top);
    return 0;
}