#include "KMPSubStr.h"

void KMP_next(char * str, int length, int * next)
{
	int j = 0;
	*next = 0;

	for (int i = 1; i < length; i++)
	{
		if (*(str + i) == *(str + j))
		{
			*(next + i) = j + 1;
			j++;
		}
		else
		{
			j = 0;
			*(next + i) = 0;
		}

	}
}

int KMP_SubStr(char * text, int text_length, char * pattern, int pattern_length)
{
	int local = -1;
	//定位pattern内的位置
	int j = 0;
	//next数组
	int* next = (int *)malloc(sizeof(int)*pattern_length);
	//初始化Next数组
	memset(next, pattern_length, sizeof(int));
	//生成Next数组的值
	KMP_next(pattern, pattern_length, next);
	for (int j = 0; j < pattern_length; j++)
		printf("%d ", *(next+j));
	for (int i = 0; i < text_length; i++)
	{
		if (text[i] == pattern[j])
		{
			j++;
			if (j == pattern_length)
			{
				local = i - j + 1;
			}
		}
		else
		{
			if (j != 0)
				j = *(next + j - 1);
			else
				j = 0;
		}
	}
	return local;
}

int KMP_SubStr_Num(char * text, int text_length, char * pattern, int pattern_length)
{
	return 0;
}




int main(void)
{
	char text[18] = { 'e','a','b','c','a','f','a','b','c','a','f','d','a','a','b','c','a','b' };
	char pattern[9] = { 'a','b','c','a','b' };
	int a =KMP_SubStr(text, 18, pattern, 5);
	printf("%d ",a);
}
