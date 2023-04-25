#pragma once
#include "Common.h"
//动态规划

int dp[MAX];
int count = 1;       //累计调用的步骤
int Fib1(int n);
int n = 6;
//求将正整数n无序拆分成最大数为k（称为n的k拆分）的拆分方案个数，
//要求所有的拆分方案不重复。
int dp1[MAXN][MAXN];         //动态规划数组
void Split(int n, int k);       //求解算法

//求解最大连续子序列和问题, 问题表示

int a[] = { 0, -2,11,-4,13, -5, -2 };	//a数组不用下标为0的元素
int  dp2[MAXN];
void maxSubSum();

//求解三角形最小路径和问题
//问题表示
int a3[MAXN][MAXN];
//求解结果表示
int ans = 0;
int dp3[MAXN][MAXN];
int pre[MAXN][MAXN];
int Search();   //搜索

void Plan();