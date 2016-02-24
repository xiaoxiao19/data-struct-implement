//循环队列的实现 
#include <stdio.h> 
#include <stdlib.h> 

#define MAXSIZE 20//队列的最大长度 

typedef struct node 
{ 
    int data[MAXSIZE]; 
    int front; 
    int rear; 
}Queuenode; 

void init_queue(Queuenode *q) 
{ 
    q->front = q->rear = 0; 
} 

void insert_queue(Queuenode *q,int e) 
{ 
    //首先判断队列是否已满 
    if((q->rear+1) % MAXSIZE == q->front) 
        return; 
    q->data[q->rear] = e; 
    //rear向前进一位，如果已经到达最后，就移到最前面 
    q->rear = (q->rear + 1) % MAXSIZE; 
} 

void delete_queue(Queuenode *q,int *e) 
{ 
    //如果队列空则返回 
    if(q->rear == q->front) 
        return; 
    *e = q->data[q->front]; 
    //front向前移动一位，如果是队列的末尾移动最前面 
    q->front = (q->front +1) % MAXSIZE; 
} 

int is_empty(Queuenode *q) 
{ 
    return q->front == q->rear ? 1 : 0; 
} 

int get_queuelength(Queuenode *q) 
{ 
    return (q->rear - q->front +MAXSIZE) % MAXSIZE; 
} 

void clear(Queuenode *q) 
{ 
    q->front = q->rear = 0; 
} 

void print_queue(Queuenode *q) 
{ 
    if(q->front == q->rear) 
        return; 
    else if(q->rear < q->front) 
    { 
        for(int i = q->front;i<MAXSIZE;++i) 
            printf("%d  ",q->data[i]); 
        for(int i = 0;i < q->rear;++i) 
            printf("%d  ",q->data[i]); 
        printf("\n"); 
    } 
    else 
    { 
        for(int i=q->front;i<q->rear;++i) 
            printf("%d  ",q->data[i]); 
        printf("\n"); 
    } 
} 

int main() 
{ 
    Queuenode q; 
    init_queue(&q); 

    for(int i=1;i<20;++i) 
        insert_queue(&q,i); 
    print_queue(&q); 
    int k; 
    delete_queue(&q,&k); 
    insert_queue(&q,30); 
    print_queue(&q); 
    return 0; 
} 
