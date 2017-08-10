#include "2SubArraySumMax.h"
//#include <stdio.h>

ArrayElem TwoSubArraySumMax(ArrayElem *array, int length)
{
	ArrayElem max=-1000;
	ArrayElem * arr1 = (ArrayElem *)malloc(sizeof(ArrayElem)*length);
	//ArrayElem * arr2 = (ArrayElem *)malloc(sizeof(ArrayElem)*length);
	ArrayElem maxL = -1000;
	ArrayElem cur_maxL = 0;
	ArrayElem maxR = -1000;
	ArrayElem cur_maxR = 0;
	//正序求0-i序列子数组的最大和（包含i）
	//反序求length-1到0的子数组的最大和
	//第二次反序的时候可以省掉一个数组
	for (int i = length-1; i >=0; i--)
	{
		cur_maxR += array[i];
		maxR = maxer(cur_maxR, maxR);
		*(arr1 + i) = maxR;
		if (cur_maxR < 0)
			cur_maxR = 0;
	}
	for (int j =0; j < length-1; j++)
	{
		cur_maxL += array[j];
		maxL = maxer(cur_maxL, maxL);
		//因为arr1[j]存放的是length-1到j包含i的字数组最大值
		//maxL也包含j，所以不是不相交所以是arr1[j+1]
		max = maxer(max, maxL + arr1[j + 1]);
		if (cur_maxL < 0)
			cur_maxL = 0;
	}
	free(arr1);
	return max;
}

/*
int main(void)
{
	int a[10] = { 1,3,4,-9,1,2,2};
	int max;
	max = TwoSubArraySumMax(a,7);
	printf("sum=%d", max);
}
*/