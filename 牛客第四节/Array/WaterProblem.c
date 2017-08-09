#include "WaterProblem.h"
#include <stdio.h>

//方法一：使用两个指针来减少空间占用
int WaterProblem(ArrayElem *array, int length)
{
	if (array == NULL || length <=2)
		return 0;
	ArrayElem water = 0;
	ArrayElem maxL = array[0];
	ArrayElem maxR = array[length - 1];
	ArrayElem L = 1;
	ArrayElem R = length-2;
	while (L <= R)
	{
		if (maxL < maxR)
		{
			if(array[L]<=maxL)
				water += maxL - array[L];
			else
				maxL = array[L];
			L = L + 1;
		}
		else
		{
			if (array[R] <= maxR)
				water += maxR - array[R];
			else
				maxR = array[R];
			R = R -1;
		}
	}
	return water;
}


//方法二：用两个数组保存第i个元素左边和右边的最大值
int WaterProblem2(ArrayElem *array, int length)
{
	return 0;
}

/*
int main(void)
{
	int a[10] = {3,2,2,4,1,7,2,7};
	int max;
	max = WaterProblem(a, 8);
	printf("water=%d", max);
}
*/