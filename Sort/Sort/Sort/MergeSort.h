#pragma once
#include "myheader.h"
#include "stdlib.h"
#include "string.h"

void Merge(int * SR, int *TR, int st, int mid, int end);
void MergePass(int * SR, int *TR, int step, int length);
void MergeSort(Sqlist *L);