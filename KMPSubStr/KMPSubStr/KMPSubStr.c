#include "KMPSubStr.h"

void KMP_next(char  *str, int length, int *next)
{
	int i = 0, j = 1;
	next[0] = 0;

	while(j<length)
	{
		if (str[i] == str[j])
		{
			next[j]=i+1;
			j++;
			i++;
		}
		else
		{
			if (i != 0)
			{
				i =next[ i - 1];
			}
			else
			{
				next[j] = 0;
				j++;
			}
		}
	}
}

void KMP_SubStr(char * text, int text_length, char * pattern, int pattern_length,int *local)
{
	int i = 0,j=0,l=0;
	int * next = (int*)malloc(sizeof(int)*pattern_length);
	KMP_next(pattern, pattern_length, next);
	while ((i<text_length)&&(j<pattern_length))
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
			if (j == pattern_length)
			{
				local[l++]=i-pattern_length;
				j = 0;
			}
		}
		else
		{
			if (j == 0)
			{
				i++;
			}
			else
			{
				j = next[j - 1];
			}
		}
	}
}

int KMP_SubStr_Num(char * text, int text_length, char * pattern, int pattern_length)
{
	int num = 0;
	int i = 0;
	int j = 0;
	int * next = (int*)malloc(sizeof(int)*pattern_length);
	KMP_next(pattern, pattern_length, next);
	while ((i<text_length) && (j<pattern_length))
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
			if (j == pattern_length)
			{
				num++;
				j = 0;
			}
		}
		else
		{
			if (j == 0)
			{
				i++;
			}
			else
			{
				j = next[j - 1];
			}
		}
	}
	free(next);
	next = NULL;
	return num;
}




int main(void)
{
	char text[20];
	char pattern[10];
	int text_len, pattern_len;
	int subnum=0;
	scanf("%s", text);
	scanf("%s", pattern);
	text_len=strlen(text);
	pattern_len = strlen(pattern);
	int* next = (int*)malloc(sizeof(int)*pattern_len);
	if (next != NULL)
	{
		KMP_next(pattern, pattern_len, next);
		for (int i = 0; i < pattern_len; i++)
			printf("%d", next[i]);
		free(next);
		next = NULL;
	}
	printf("\n");
	//申请一个内存空间存放子字符串开始位置
	int* local = (int*)malloc(sizeof(int)*text_len);
	if (local != NULL)
	{
		//malloc申请的内存默认不初试化
		memset(local, 0, sizeof(int)*text_len);
		//统计子字符串开始的位置
		KMP_SubStr(text, text_len, pattern, pattern_len, local);
		for (int i = 0; i < text_len; i++)
			printf("%d", local[i]);
		free(local);
		local = NULL;
	}
	//统计出现了几个子字符串
	subnum = KMP_SubStr_Num(text, text_len, pattern, pattern_len);
	printf("\n%d", subnum);
}
