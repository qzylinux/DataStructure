#include "MaxAbsBetweenLeftAndRight.h"
//#include <stdio.h>

ArrayElem MaxAbsBetweenLeftAndRight(ArrayElem *array, int length)
{
	ArrayElem max=-1000;
	for (int i = 0; i < length; i++)
		max=maxer(max, array[i]);
	max=maxer(max - array[length - 1], max-array[0]);
	return max;
}


/*
int main(void)
{
	int a[10] = { 2,7,3,1,1 };
	int max;
	max = MaxAbsBetweenLeftAndRight(a, 5);
	printf("abs=%d", max);
}
*/