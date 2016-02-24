#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
int heap[MAX_SIZE];

//最大堆的插入
void max_heap_insert(int *heap,int *n,int item)
{
	int i,parent;

	//堆为满
	if((*n) == MAX_SIZE)
	{
		printf("the heap is full\n");
		exit(1);
	}

	i = ++(*n);
	parent = i/2;

	//若堆为非空且插入的数据item大雨父节点的关键字值
	while(i != 1 && (item > heap[parent]))
	{
		heap[i] = heap[parent];
		i = parent;
		parent /= 2;
	}
	//插入到正确的位置
	heap[i] = item;
}


//在这个删除算法中，每次都删除堆顶元素，
//所以此程序中首先将堆中总元素值减一，然后弹出堆顶后比较堆的两个孩子节点，
//将较大的孩子节点作为父节点，然后依次调整两个孩子节点中较大孩子节点所处的分支，
//调整直到调整到最后一个孩子节点
int max_heap_delete(int *heap,int *n)
{
	int item,temp;
	int child,parent;

	//堆为空
	if(*n == 0)
	{
		printf("the heap is empty.\n");
		exit(1);
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2*parent;
	while(child <= (*n))
	{
		//找出堆中最大关键字值的节点
		if(child < *n && heap[child] < heap[child+1])
			child++;
		//把最大节点关键字值与最后节点关键字值比较
		if(temp >= heap[child])
			break;
		else
		{
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
	}
	heap[parent] = temp;
	return item;
}

int main()
{
	int item ,i;
	int n = 0;

	for(i=1;i<MAX_SIZE;i++)
	{
		scanf("%d",&item);
		max_heap_insert(heap,&n,item);
	}

	for(i=1;i<=n;i++)
		printf("%d  ", heap[i]);
	printf("\n");

	item = max_heap_delete(heap,&n);
	printf("the deleted data:%d\n",item);
	printf("\n");
	for(i=1;i<=n;i++)
		printf("%d ",heap[i]);
	return 0;
}