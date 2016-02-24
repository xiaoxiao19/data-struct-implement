//15.10.31
//选择排序--简单选择排序

#include <stdio.h>
#include <stdlib.h>

void simple_select_sort(int *a,int n)
{
	int i,j,min,tmp;

	for(i=0;i<n-1;i++)
	{
		j = i+1;
		min = i;
		while(j < n)
		{
			if(a[j] < a[min])
				min = j;
			j++;
		}
		if(j != min)
		{
			tmp = a[min];
			a[min] = a[j];
			a[j] = tmp;
		}
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

	simple_select_sort(a,6);

	for(i=0;i<6;i++)
		printf("%d   ",a[i]);
	printf("\n");
	return 0;
}
