#include "HeapSort.h"
//如果建立的是大顶堆，那么序列最后的排序是从小到大，应为堆顶元素放在了序列最后
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