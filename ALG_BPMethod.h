#pragma once
#include "Common.h"
//��̬�滮

int dp[MAX];
int count = 1;       //�ۼƵ��õĲ���
int Fib1(int n);
int n = 6;
//��������n�����ֳ������Ϊk����Ϊn��k��֣��Ĳ�ַ���������
//Ҫ�����еĲ�ַ������ظ���
int dp1[MAXN][MAXN];         //��̬�滮����
void Split(int n, int k);       //����㷨

//���������������к�����, �����ʾ

int a[] = { 0, -2,11,-4,13, -5, -2 };	//a���鲻���±�Ϊ0��Ԫ��
int  dp2[MAXN];
void maxSubSum();

//�����������С·��������
//�����ʾ
int a3[MAXN][MAXN];
//�������ʾ
int ans = 0;
int dp3[MAXN][MAXN];
int pre[MAXN][MAXN];
int Search();   //����

void Plan();