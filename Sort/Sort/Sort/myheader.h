#pragma once
#define MAXSIZE 20

typedef int elemType;
typedef struct S{
	elemType data[MAXSIZE];
	int length;
}Sqlist;

void swap(Sqlist *L, int i, int j);

