#pragma once
#include "Common.h"
//动态规划

int dp[MAX];
int count = 1;       //累计调用的步骤
int Fib1(int n);

//求将正整数n无序拆分成最大数为k（称为n的k拆分）的拆分方案个数，
//要求所有的拆分方案不重复。
int dp1[MAXN][MAXN];         //动态规划数组
void Split(int n, int k);       //求解算法