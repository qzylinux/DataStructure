#include "myheader.h"

//交换线性表内的两个元素位置
void swap(Sqlist *L, int i, int j)
{
	elemType temp;
	temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
}