/*
位移转换
（1） 求十进制数0-N对应的在数组a中的下标

index_loc = N / 32即可，index_loc即为n对应的数组下标。例如n = 76, 则loc = 76 / 32 = 2,因此76在a[2]中。

（2）求十进制数0-N对应的bit位

bit_loc = N % 32即可，例如 n = 76, bit_loc = 76 % 32 = 12

（3）利用移位0-31使得对应的32bit位为1
*/


//代码示例(c语言)
#include <stdio.h>
#include <stdlib.h>

#define SHIFT 5
#define MASK 0x1F

/**
 * 设置所在的bit位为1
 *
 * T = O(1)
 *
 */
void set(int n, int *arr)
{
	int index_loc, bit_loc;

	index_loc = n >> SHIFT; // 等价于n / 32
	bit_loc = n & MASK;	// 等价于n % 32

	arr[index_loc] |= 1 << bit_loc;
}

/**
 * 初始化arr[index_loc]所有bit位为0
 *
 * T = O(1)
 *
 */
void clr(int n, int *arr)
{
	int index_loc;

	index_loc = n >> SHIFT;

	arr[index_loc] &= 0;
}

/**
 * 测试n所在的bit位是否为1
 *
 * T = O(1)
 *
 */
int test(int n, int *arr)
{
	int i, flag;

	i = 1 << (n & MASK);

	flag = arr[n >> SHIFT] & i;

	return flag;
}

int main(void)
{
	int i, num, space, *arr;

	while (scanf("%d", &num) != EOF) {
		// 确定大小&&动态申请数组
		space = num / 32 + 1;
		arr = (int *)malloc(sizeof(int) * space);

		// 初始化bit位为0
		for (i = 0; i <= num; i ++)
			clr(i, arr);

		// 设置num的比特位为1
		set(num, arr);
		
		// 测试
		if (test(num, arr)) {
			printf("成功！\n");
		} else {
			printf("失败!\n");
		}
	}

	return 0;
}