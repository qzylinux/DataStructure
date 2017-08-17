#include <math.h>
#include <stdio.h>
#include "myheader.h"
#include "BulleSort.h"	//冒泡排序
#include "SelectSort.h"	//选择排序
#include "InsertSort.h"	//插入排序
#include "ShellSort.h"	//希尔排序
#include "HeapSort.h"	//堆排序
#include "QuickSort.h"	//快速排序
#include "MergeSort.h"	//归并排序


int main(void)
{
	//初始化结构体
	Sqlist L = { { 1,9,2,6,8,3,12,4,5,7 },10 };
	//调用排序方法
	MergeSort(&L);
	//打印排序后的序列
	for(int i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
}