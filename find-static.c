#include <stdio.h> 
#include <stdlib.h> 

#define MAX_SIZE 100 

typedef struct Seq 
{ 
    int *ele; 
    int length; 
}Seq; 

/* 
int init_Seq(Seq s) 
{ 
    s.ele = (int *)malloc(MAX_SIZE*sizeof(int)); 
    if(!s.ele) 
        return 0; 
    else 
    { 
        s.length = 0; 
        return 1; 
    } 
} 

int find_Seq(Seq s,int key) 
{ 
    int i = 0; 
    for(i = s.length;i >= 0;i--) 
        if(s.ele[i] == key) 
            return i; 
    return -1; 
}*/ 

int main() 
{ 
    Seq s; 
    int data; 
    int key; 
    int r; 

    //1.线性表的初始化 
    s.ele = (int *)malloc(MAX_SIZE*sizeof(int)); 
    if(!s.ele) 
        return 0; 
    else 
        s.length = 0; 

     
    //2.向线性表中插入数据 
    printf("请输入线性表中的数值：\n"); 
    scanf("%d",&data); 
    while(data != 0) 
    { 
        s.ele[s.length] = data; 
        scanf("%d",&data); 
        s.length++; 
    } 
     
    //打印出线性表的数值 
    printf("线性表中的值有：\n"); 
    while(s.length >= 0) 
    { 
        printf("%d",s.ele[s.length]); 
        s.length--; 
    } 
    printf("\n"); 
    //3.在线性表中查找相应的值 
    printf("请输入要查找的数值：\n"); 
    scanf("%d",&key); 
    int i = 0; 
    for(i = s.length;i >= 0;i--) 
        if(s.ele[i] == key) 
            r = i; 

    if(r > -1) 
        printf("在顺序表中查找成功,第%d个数是！\n",r+1); 
    else 
        printf("在顺序表中未查找道该数值！\n"); 

    return 0; 
} 



//折半查找 

#include <stdio.h> 
#include <stdlib.h> 

#define MAX_SIZE 100 

typedef struct Seq 
{ 
    int *elem; 
    int length; 
}Seq; 

int init_seq(Seq *s) 
{ 
    s->elem = (int *)malloc(MAX_SIZE * sizeof(int)); 
    if(!s->elem) 
        return 0; 
    else 
    { 
        s->length = 0; 
        return 1; 
    } 
} 

int search(Seq *s,int key) 
{ 
    int low = 0; 
    int mid = 0; 
    int high = s->length+1;//开始时high值设置错误，所以很多值不能查看成功！ 

    while(low < high) 
    { 
        mid = (low + high)/2; 
        if(s->elem[mid] == key) 
            return mid; 
        else if(s->elem[mid] < key) 
            low = mid + 1; 
        else 
            high = mid -1; 
    } 
    return 0; 
} 

int main() 
{ 
    Seq s; 
    init_seq(&s); 
    int data; 
    int key; 
    int r; 

    printf("请输入线性表中的数据:\n"); 
    scanf("%d",&data); 
    while(data != 1) 
    { 
        setbuf(stdin,NULL);         
        s.elem[s.length] = data; 
        s.length++; 
        scanf("%d",&data); 
    } 

    printf("线性表中的数据为:\n"); 
    printf("线性表中有%d个数据！\n",s.length); 
    for(r = 0;r < s.length ;r++) 
        printf("%d  ",s.elem[r]); 
    printf("\n"); 

    printf("请输入要查找的数值：\n"); 
    scanf("%d",&key); 
    r = search(&s,key); 

    if(r > 0) 
        printf("查找到了该数值，在位置%d\n",r); 
    else 
        printf("未找到数值!\n"); 

    return 0; 
}






//分块查找的实现 

#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
#include <math.h> 

#define N 30 

int *add[N]; 

//定义单链表节点类型 
typedef struct Node 
{ 
    int id; 
    struct Node *next; 
}list; 

list *creat(list *head) 
{ 
    int i = 0; 
    list *p1; 
    list *p2; 
    p1 = p2 = (struct Node *)malloc(sizeof(struct Node)); 

    if(p1 == NULL || p2 == NULL) 
    { 
        printf("内存分配失败!\n"); 
        exit(0); 
    } 
    scanf("%d",&p1->id); 
    p1->next = NULL; 

    while(p1->id > 0) 
    { 
        add[++i] = (struct Node *)p1; 
        if(head == NULL) 
            head = p1; 
        else 
            p2->next = p1; 
        p2 = p1; 
        p1 = (struct Node *)malloc(sizeof(struct Node)); 
        if(p1 == NULL || p2 == NULL) 
        { 
            printf("内存分配失败!\n"); 
            exit(0); 
        } 
        scanf("%d",&p1->id); 
        p1->next = NULL; 
    } 
    printf("链表创建成功!\n"); 
    return head; 
} 

void display(struct Node *pHead) 
{ 
    int i = 0; 
    if(NULL == pHead) 
        printf("链表为空!\n"); 
    else 
    { 
        while(pHead != NULL) 
        { 
            printf("%d",pHead->id); 
            printf("地址：%d]   ",add[++i]); 
            pHead = pHead->next; 
        } 
        printf("\n"); 
    } 
} 

int sizeList(struct Node * pHead) 
{ 
    int size = 0; 
    while(pHead != NULL) 
    { 
        size++; 
        pHead = pHead->next; 
    } 
    printf("链表长度%d\n",size); 
    return size; 
} 

void BlkSearch(list *pHead,int key,int block,int BLK) 
{ 
    int i; 
    struct Node *t; 

    if(NULL == pHead) 
        printf("链表为空!\n"); 
    else 
    { 
        for(i = block*BLK;i<(block+1)*BLK&& add[i]!=0;i++) 
        { 
            t = add[i]; 
            if(t->id == key) 
                printf("找到第%d个数是%d\n",i,key); 
            return 0; 
        } 
        printf("\n"); 
    } 
    printf("查找结束\n"); 
} 

int main() 
{ 
    int len; 
    int key,block,blk; 
    struct Node *mylist = NULL; 
    struct Node *p; 
    puts("输入数字开始创建链表，以小于零的数结束创建:"); 
    p = creat(mylist); 
    len = sizeList(p); 
    add[0] = (int *)p; 
    display(p); 
    puts("输入需要查找的数字:\n"); 
    scanf("%d",&blk); 
    puts("输入块的大小:\n"); 
    scanf("%d",&blk); 
    puts("输入需要查找的块:\n"); 
    scanf("%d",&block); 
    BlkSearch(p,key,block,blk); 
    return 0; 
} 





