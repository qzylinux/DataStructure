#include "SubArraySumMax.h"
//#include <stdio.h>

//������ֵ�еĽ�Сֵ
ArrayElem maxer(ArrayElem a, ArrayElem b)
{
	return a > b ? a : b;
}

ArrayElem SubArraySumMax(ArrayElem *array, int length)
{
	if (array == NULL || length == 0)
		return 0;
	//max���array����������,��ʼֵΪϵͳ��Сֵ
	//cur_max��ŵ�ǰ������ĺ�
	ArrayElem max = -100;
	ArrayElem cur_max = 0;

	for (int i = 0; i != length; i++)
	{
		cur_max += array[i];
		//max����Ŀǰ������������е����ֵ
		max=maxer(max, cur_max);
		//�����ǰ���ֵΪ0��ô���������鲻��Ҫ��ǰ��μ�һ������ʹ�Լ��ĺͱ�С
		//Ҳ��������Ѱ�Һ��������������
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