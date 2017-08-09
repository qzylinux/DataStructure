#include "2SubArraySumMax.h"
#include <stdio.h>

ArrayElem TwoSubArraySumMax(ArrayElem *array, int length)
{
	ArrayElem max=-1000;
	ArrayElem * arr1 = (ArrayElem *)malloc(sizeof(ArrayElem)*length);
	//ArrayElem * arr2 = (ArrayElem *)malloc(sizeof(ArrayElem)*length);
	ArrayElem maxL = -1000;
	ArrayElem cur_maxL = 0;
	for (int i = 0; i < length-1; i++)
	{
		cur_maxL += array[i];
		maxL=maxer(cur_maxL, maxL);
		*(arr1 + i) = maxL;
		if (cur_maxL < 0)
			cur_maxL = 0;
	}
	ArrayElem maxR = -1000;
	ArrayElem cur_maxR = 0;
	for (int i = length-1; i >0; i--)
	{
		cur_maxR += array[i];
		maxR = maxer(cur_maxR, maxR);
		max = maxer(max, maxR + *(arr1 + i));
		if (cur_maxR < 0)
			cur_maxR = 0;
	}
	return max;
}


int main(void)
{
	int a[6] = { -1,3,4,-9,1,-2};
	int max;
	max = TwoSubArraySumMax(a,6);
	printf("sum=%d", max);
}