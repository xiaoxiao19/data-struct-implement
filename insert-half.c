//15.10.23
//排序-插入排序-二分（折半）插入排序

#include <stdio.h>
#include <stdlib.h>

void binary_insert_sort(int *a,int n)
{
	int i,j,tmp,low,mid,high;
	
	for(i=1;i<8;i++)
	{
		tmp = a[i];
		low = 0;
		high = i-1;

		while(low <= high)
		{
			mid = (low + high)/2;
			if(a[mid] > tmp)
				high = mid - 1;
			else
				low = mid + 1;
		}

		for(j=i-1;j>high;j--)
			a[j+1] = a[j];
		a[high+1] = tmp;
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

	binary_insert_sort(a,8);

	for(i=0;i<8;i++)
		printf("%d   ",a[i]);
	printf("\n");	

	return 0;
}
