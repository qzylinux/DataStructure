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
	if (i <=st)
	{
		int m;
		for(m=i;m<mid;m++)
			TR[k++] = SR[i];
	}
	if (j <=end)
	{
		int m;
		for(m=j;m<end;j++)
			TR[k++] = SR[j];
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
}
//�ǵݹ鷽ʽ���ռ临�ӶȽ���
void MergeSort(Sqlist *L)
{
	int * TR = (int*)malloc(L->length * sizeof(int));
	int i = 1;
	while (i<L->length)
	{
		MergePass(L,TR,i,L->length);
		i = i * 2;
		MergePass(TR, L, i, L->length);
		i = i * 2;
	}
}