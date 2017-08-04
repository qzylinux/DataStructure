#include "SelectSort.h"

//用简单选择排序进行从小到大排序
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