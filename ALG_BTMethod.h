#pragma once
#define MAX 1025
#include "Common.h"
//回溯法算法分析与设计


//1、有一个含n个整数的数组a，所有元素均不相同，设计一个算法求其所有子集（幂集）。
void dispaSSsolution(int a[], int n, int x[])
{
	cout << "{";
	for (int i = 0; i < n; i++)
	{
		if (x[i] == 1)
			cout << a[i] << " ";
	}
	cout << "}  ";
}
void dfsSubSet(int a[], int n, int i, int x[])
{
	if (i >= n)
		dispaSSsolution(a, n, x);
	else
	{
		x[i] = 0;
		dfsSubSet(a, n, i + 1, x);
		x[i] = 1;
		dfsSubSet(a, n, i + 1, x);
	}
}

//设计一个算法在1，2，…，9（顺序不能变）数字之间插入+或-或什么都不插入，
//使得计算结果总是100的程序，并输出所有的可能性。
//例如：1 + 2 + 34–5 + 67–8 + 9 = 100。
void fun(char op[], int sum, int prevadd, int a[], int i)
{

}