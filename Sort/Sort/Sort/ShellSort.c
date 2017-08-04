#include "ShellSort.h"

void ShellSort(Sqlist *L)
{
	int increament = L->length;
	int i, j;

	do {
		increament = increament / 3 + 1;
		//����������Ƕ����������ȶ��������ͬһλ�õ�Ԫ�ؽ��в��룬Ȼ���ٶ����������һ��Ԫ�طֱ�ֱ�Ӳ���
		for (i = increament; i<L->length; i++)
		{
			if (L->data[i] < L->data[i - increament])
			{
				int temp = L->data[i];
				for (j = i - increament; j > 0 && temp < L->data[j]; j -= increament)
					L->data[j + increament] = L->data[j];
				L->data[j + increament] = temp;
			}
		}

	} while (increament>1);
}