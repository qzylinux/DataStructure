#include "myheader.h"

//�������Ա��ڵ�����Ԫ��λ��
void swap(Sqlist *L, int i, int j)
{
	elemType temp;
	temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
}