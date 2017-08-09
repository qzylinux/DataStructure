#include "SubArraySumMax.h"
//#include <stdio.h>

//求两个值中的较小值
ArrayElem maxer(ArrayElem a, ArrayElem b)
{
	return a > b ? a : b;
}

ArrayElem SubArraySumMax(ArrayElem *array, int length)
{
	if (array == NULL || length == 0)
		return 0;
	//max存放array子数组最大和,初始值为系统最小值
	//cur_max存放当前子数组的和
	ArrayElem max = -100;
	ArrayElem cur_max = 0;

	for (int i = 0; i != length; i++)
	{
		cur_max += array[i];
		//max保存目前所有子数组和中的最大值
		max=maxer(max, cur_max);
		//如果当前最大值为0那么后续的数组不需要在前半段加一个负数使自己的和变小
		//也就是重新寻找后面的子数组最大和
		if (cur_max < 0)
			cur_max = 0;
	}
	return max;
}


/*
int main(void)
{
	int a[10] = { -2,-3,-4,-1,-5,-6 };
	int max;
	max=SubArraySumMax(a, 6);
	printf("SubMatrixSumMax=%d", max);
}
*/