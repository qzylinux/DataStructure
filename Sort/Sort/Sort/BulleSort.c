#include "BulleSort.h"


void BulleSort(Sqlist * L)
{
	for (int i = 0; i < L->length; i++)
	{
		for (int j = i+1; j < L->length; j++) {
			if (L->data[i] > L->data[j])
				swap(L, i, j);
		}
	}
}