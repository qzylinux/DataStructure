#include "SelectSort.h"

//�ü�ѡ��������д�С��������
void SelectSort(Sqlist * L)
{
	int i, j,temp;
	for (i = 0; i < L->length; i++)
	{
		temp = i;
		for(j=i+1;j<L->length;j++)
		{
			if (L->data[temp] > L->data[j])
				temp = j;
		}
		swap(L, i, temp);
	}
}