#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void KMP_next(char * str, int length,int *next);
int KMP_SubStr(char* text,int text_length,char* pattern,int pattern_length);	//����ƥ���ģ���ַ�����λ��
int KMP_SubStr_Num(char* text, int text_length, char* pattern, int pattern_length);//(��չ������ƥ��ĸ���)