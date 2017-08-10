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
	//������0-i��������������ͣ�����i��
	//������length-1��0�������������
	//�ڶ��η����ʱ�����ʡ��һ������
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
		//��Ϊarr1[j]��ŵ���length-1��j����i�����������ֵ
		//maxLҲ����j�����Բ��ǲ��ཻ������arr1[j+1]
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