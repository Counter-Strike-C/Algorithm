#pragma once
#include "Common.h"
//��̬�滮

int dp[MAX];
int count = 1;       //�ۼƵ��õĲ���
int Fib1(int n);

//��������n�����ֳ������Ϊk����Ϊn��k��֣��Ĳ�ַ���������
//Ҫ�����еĲ�ַ������ظ���
int dp1[MAXN][MAXN];         //��̬�滮����
void Split(int n, int k);       //����㷨