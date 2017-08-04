#include "ShellSort.h"

void ShellSort(Sqlist *L)
{
	int increament = L->length;
	int i, j;

	do {
		increament = increament / 3 + 1;
		//下面的流程是对组轮流，先对所有组的同一位置的元素进行插入，然后再对所有组的下一个元素分别直接插入
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