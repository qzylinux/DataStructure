#include <math.h>
#include <stdio.h>
#include "myheader.h"
#include "BulleSort.h"	//ð������
#include "SelectSort.h"	//ѡ������
#include "InsertSort.h"	//��������
#include "ShellSort.h"	//ϣ������
#include "HeapSort.h"	//������
#include "QuickSort.h"	//��������
#include "MergeSort.h"	//�鲢����


int main(void)
{
	//��ʼ���ṹ��
	Sqlist L = { { 1,9,2,6,8,3,12,4,5,7 },10 };
	//�������򷽷�
	MergeSort(&L);
	//��ӡ����������
	for(int i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
}