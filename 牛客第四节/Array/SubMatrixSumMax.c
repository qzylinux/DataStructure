#include "SubMatrixSumMax.h"

ArrayElem SubMatrixSumMax(ArrayElem *array, int row_len, int col_len)
{
	if (array == NULL || row_len == 0 || col_len == 0)
		return 0;
	int max=-10000;
	for (int i = 0; i < row_len; i++)
	{
		
		for (int j = i; j < row_len; j++)
		{
			for (int k = 0; k < col_len; k++)
			{

			}
			
		}
	}
	return max;
}