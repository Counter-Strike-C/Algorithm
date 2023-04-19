#pragma once
#include "Common.h"
//动态规划
class ALG_BPMethod
{
public:
	int dp[MAX];
	int count = 1;       //累计调用的步骤
	int Fib1(int n);       //斐波那契数列求解
};

