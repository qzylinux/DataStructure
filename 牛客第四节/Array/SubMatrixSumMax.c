#include "SubMatrixSumMax.h"
#include <stdio.h>

ArrayElem SubMatrixSumMax(ArrayElem *array, int row_len, int col_len)
{
	if (array == NULL || row_len == 0 || col_len == 0)
		return 0;
	ArrayElem *s = (ArrayElem *)malloc(sizeof(ArrayElem)*col_len);
	int max=-10000;
	int cur_lin_max;
	for (int i = 0; i < row_len; i++)
	{
		memset(s, 0, col_len * sizeof(ArrayElem));
		for (int j = i; j < row_len; j++)
		{
			cur_lin_max = 0;
			for (int k = 0; k < col_len; k++)
			{
				*(s + k) += array[j*col_len+k];
				cur_lin_max += *(s + k);
				max=maxer(cur_lin_max, max);
				if (cur_lin_max < 0)
					cur_lin_max = 0;
			}
		}
	}
	free(s);
	return max;
}


/*
int main(void)
{
	int a[10] = { -90,48,78,64,-40,64,-81,-7,66};
	int max;
	max = SubMatrixSumMax(a,3,3);
	printf("max=%d", max);
}
*/