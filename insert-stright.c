//15.10.23
//排序-插入排序-直接插入排序

#include <stdio.h>
#include <stdlib.h>

void straight_insert_sort(int *a,int n)
{
	int i,j,tmp;

	for(i=1;i<n;i++)
	{
		j = i-1;
		tmp = a[i];
		while(j >= 0 && a[j] > tmp)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
}

int main()
{
	int a[5] = {0};
	int i = 0;

	for(i = 0;i<6;i++)
		scanf("%d",&a[i]);
	for(i=0;i<6;i++)
		printf("%d   ",a[i]);
	printf("\n");

	straight_insert_sort(a,6);

	return 0;
}
