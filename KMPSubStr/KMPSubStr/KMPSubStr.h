#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void KMP_next(char *str, int length,int *next);
void KMP_SubStr(char* text,int text_length,char* pattern,int pattern_length,int *local);	//返回匹配的模板字符串的位置
int KMP_SubStr_Num(char* text, int text_length, char* pattern, int pattern_length);//(拓展：返回匹配的个数)