#include "HeapSort.h"
//����������Ǵ󶥶ѣ���ô�������������Ǵ�С����ӦΪ�Ѷ�Ԫ�ط������������
HeapAdjust(Sqlist *L, int s, int m)
{
	int temp=L->data[s];
	for (int i = s * 2+1; i <= m; i = i * 2+1)
	{
		if (i<m&&L->data[i] > L->data[i + 1])
		{
			i++;
		}
		if (L->data[i] >= temp)
			break;
		L->data[s] = L->data[i];
		s = i;
	}
	L->data[s] = temp;
}

void HeapSort(Sqlist *L)
{
	int i;
	for (i = L->length / 2-1; i >=0; i--)
	{
		HeapAdjust(L,i,L->length);
	}
	for (int j = L->length-1; j>=0; j--)
	{
		swap(L, 0, j);
		HeapAdjust(L, 0, j - 1);
	}
}