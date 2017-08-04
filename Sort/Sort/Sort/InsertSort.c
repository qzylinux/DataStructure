#include "InsertSort.h"
//≤Â»Î∑Ω Ω≈≈–Ú
void InsertSort(Sqlist *L)
{
	int i,j,temp;
	for (i = 1; i < L->length; i++)
	{
		if (L->data[i] < L->data[i - 1])
		{
			temp = L->data[i];
			for (j = i - 1; L->data[j] > temp; j--)
			{
				L->data[j + 1] = L->data[j];
			}
			L->data[j + 1] = temp;
		}
	}
}