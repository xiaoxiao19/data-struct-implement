//15.10.23
//快速排序-冒泡排序

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a,int n)
{
	int i,j;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
	}
}

int main()
{
	int a[7] = {0};
	int i = 0;

	for(i=0;i<8;i++)
		scanf("%d",&a[i]);

	for(i=0;i<8;i++)
		printf("%d   ",a[i]);
	printf("\n");

	bubble_sort(a,8);

	for(i=0;i<8;i++)
		printf("%d   ",a[i]);
	printf("\n");	

	return 0;
}
