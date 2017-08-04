#include "QuickSort.h"

void QuickSort(Sqlist *L,int s,int e)
{
	int pivot;
	if (s < e)
	{
		pivot = Partition(L, s, e);
		QuickSort(L, s, pivot-1);
		QuickSort(L, pivot + 1,e);
	}

}

int Partition(Sqlist  *L, int low, int high)
{
	//优化初始分组值，放在low处
	int m = (low + high) / 2;
	if (L->data[low] > L->data[m])
		swap(L, low, m);
	if (L->data[m] > L->data[high])
		swap(L, m, high);
	if (L->data[low] <L->data[m])
		swap(L, low, m);
	int pivotkey = L->data[low];
	while (low < high)
	{
		while (low < high&&L->data[high] >= pivotkey)
			high--;
		swap(L, low, high);
		while (low < high&&L->data[low] <= pivotkey)
			low++;
		swap(L, low, high);
	}
	return low;
}