//15.10.23
//排序-希尔排序

#include <stdio.h>
#include <stdlib.h>

void shell_sort(int *a,int n)
{
	int j,gap;
		
	for(gap = n/2;gap>0;gap /= 2)
		for(j=gap;gap<n;j++)
			if(a[j] < a[j-gap])
			{
				int tmp = a[j];
				int k = j-gap;
				while(k>=0 && a[k] > tmp)
				{
					a[k+gap] = a[k];
					k-=gap;
				}
				a[k+gap] = tmp;
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

	shell_sort(a,8);

	for(i=0;i<8;i++)
		printf("%d   ",a[i]);
	printf("\n");	

	return 0;
}
