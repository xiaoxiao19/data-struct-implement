//15.10.10
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 100

typedef struct tree 
{
	int data;
	struct tree *LChild;
	struct tree *RChild;
}Tree;

void createTree(Tree **t)
{
	int m = 0;
	
	scanf("%d",&m);

	if(m == 0)
		(*t) = NULL;
	else
	{
		(*t) = (Tree *)malloc(sizeof(Tree));
		(*t)->data = m;
		createTree(&((*t)->LChild));
		createTree(&((*t)->RChild));
	}
}

void preOrder(Tree *t)
{
	if(t)
	{
		printf("%d   ",t->data);
		preOrder(t->LChild);
		preOrder(t->RChild);
	}
}

void preOrderTree(Tree *t)
{
	Tree *stack[MAX_NODE] = {NULL};
	int top = 0;

	if(t == NULL)
		printf("the tree is null!\n");
	else
	{
		do
		{
			printf("%d   ",t->data);
			if(t->RChild)
				stack[++top] = t->RChild;
			t = t->LChild;
			if(t == NULL)
			{
				t = stack[top];
				top--;
			}
		}while(t);
	}
}

void inOrder(Tree *t)
{
	if(t)
	{
		inOrder(t->LChild);
		printf("%d   ",t->data);
		inOrder(t->RChild);
	}
}

void inOrderTree(Tree *t)
{
	Tree *stack[MAX_NODE] = {NULL};
	int top = 0;
	int i = 0;

	if(t == NULL)
		printf("the tree is null!\n");
	else
	{
		do
		{
			while(t)
			{
				stack[++top] = t;
				t = t->LChild;
			}
			if(top == 0)
				i = 1;
			else
			{
				t = stack[top];
				top--;
				printf("%d   ",t->data);
				t = t->RChild;
			}
		}
		while(i == 0);
	}
}

void postOrder(Tree *t)
{
	if(t)
	{
		postOrder(t->LChild);
		postOrder(t->RChild);
		printf("%d   ",t->data);
	}
}

void postOrderTree(Tree *t)
{
	Tree *stack1[MAX_NODE] = {NULL};
	int top = 0,i = 0;
	int stack2[MAX_NODE] = {0};
	
	if(t == NULL)
		printf("the tree is null!\n");
	else
	{
		do
		{
			while(t)
			{
				stack1[++top] = t;
				stack2[top] = 0;
				t =t->LChild;
			}
			if(top == 0)
				i = 1;
			else if(stack2[top] == 0)
			{
				t = stack1[top]->RChild;
				stack2[top] = 1;
			}
			else
			{
				t = stack1[top];
				printf("%d   ",t->data);
				top--;
				t = NULL;//!!!!
			}
		}
		while(i == 0);
	}
}

void levelOrder(Tree *t)
{
	Tree *queue[MAX_NODE] = {NULL};
	int front = 0,rear = 0;


	queue[++rear] = t;
	while(front < rear)
	{
		t = queue[++front];
		printf("%d   ",t->data);
		if(t->LChild)
			queue[++rear] = t->LChild;
		if(t->RChild)
			queue[++rear] = t->RChild;
	}

}

int main()
{
	Tree *t;

	createTree(&t);

	preOrder(t);
	printf("\n");
	preOrderTree(t);
	printf("\n");

	inOrder(t);
	printf("\n");
	inOrderTree(t);
	printf("\n");

	postOrder(t);
	printf("\n");
	postOrderTree(t);
	printf("\n");

	levelOrder(t);
	printf("\n");

	return 0;
}
