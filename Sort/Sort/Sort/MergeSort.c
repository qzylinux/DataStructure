#include "MergeSort.h"

//�ϲ�������������
void Merge(int * SR, int *TR, int st, int mid, int end)
{
	int i=st, j=mid+1,k;
	for (k=st; i <= mid && j <=end; k++)
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= mid)
	{
		int m;
		for(m=i;m<=mid;m++)
			TR[k++] = SR[m];
	}
	if (j <=end)
	{
		int m;
		for(m=j;m<=end;m++)
			TR[k++] = SR[m];
	}
}

//��SRÿ��������step���ȵ�������鲢��TR�У������ܳ���Ϊlength
void MergePass(int * SR, int *TR, int step, int length)
{
	int i = 0;
	while (i <= length - step * 2)
	{
		Merge(SR, TR, i, i + step - 1, i + step * 2 -1);
		i += 2 * step;
	}
	if (i < length - step+1)
	{
		Merge(SR, TR, i, i + step - 1, length-1);
	}
	else
	{
		int j;
		for (j = i; j < length; j++)
			TR[j] = SR[j];
	}
	for (i = 0; i < length; i++)
		SR[i] = TR[i];
}
//�ǵݹ鷽ʽ���ռ临�ӶȽ���
void MergeSort(Sqlist *L)
{
	int * TR = (int*)malloc(L->length * sizeof(int));
	memset(TR, 0, sizeof(int)*L->length);
	int i = 1;
	while (i<L->length)
	{
		MergePass(L->data,TR,i,L->length);
		i = i * 2;
	}
}