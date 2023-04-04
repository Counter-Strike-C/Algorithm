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
const int N = 9;
void fun(char op[], int sum, int prevadd, int a[], int i)
{
	if (i == N)
	{
		if (sum == 100)
		{
			cout << a[0];
			for (int j = 1; j < N; j++)
			{
				if (op[j] != ' ')
					cout << op[j];
				cout << a[j];
			}
			cout << "=100" << endl;
		}
		return;
	}

	op[i] = '+';
	sum += a[i];
	fun(op, sum, a[i], a, i + 1);
	sum -= a[i];        //回溯，以便进行减号的递归

	op[i] = '-';
	sum -= a[i];
	fun(op, sum, -a[i], a, i + 1);
	sum += a[i];

	op[i] = ' ';
	sum -= prevadd;      //先减去前面的元素，以便合成一个数
	int tmp;
	if (prevadd > 0)  //判断是否是正负
		tmp = prevadd * 10 + a[i];     //如prevadd=5,a[i]=6,结果为56
	else
		tmp = prevadd * 10 - a[i];
	sum += tmp;   //计算合并结果
	fun(op, sum, tmp, a, i + 1);
	sum -= tmp;       //回溯
	sum += prevadd;
}

//有一个含n个整数的数组a，所有元素均不相同，求其所有元素的全排列。
//例如，a[] = { 1，2，3 }，得到结果是（1，2，3）、（1，3，2）、（2，3，1）、（2，1，3）、（3，1，2）、（3，2，1）。

void dispacdfssolution(int a[],int  n)
{
	cout << "{";
	for (int  i = 0; i < n; i++)
	{
		cout << a[i] << ", ";
	}
	cout << "} ";
}
void cdfs(int a[], int n, int i)
{
	if (i >= n)
		dispacdfssolution(a, n);
	else
	{
		for (int j = i; j < n; j++)
		{
			swap(a[i], a[j]);  //三次交换使得第一个分别为1、2、3，通过递归形成解空间树
			cdfs(a, n, i + 1);
			swap(a[i], a[j]);
		}
	}
}


//01背包问题
int n2 = 4;  //4种物品
int W = 6;     //限制重量为6
int w[] = { 0,5,3,2,1 };      //重量
int v[] = { 0,4,4,3,1 };       //价值
//求解结果展示
int x1[5];       //存放最终解
int maxv;      //存放最优解的总价值
void dfs01(int i, int tw, int tv, int rw,int op[])
{
	if (i > n2)      //找到一个叶子节点
	{
		if (tw == W && tv > maxv)        //找到一个满足条件的更优解，保存
		{
			maxv = tv;
			for (int j = 1; j < n; j++)
				x1[j] = op[j];       //保存结果
		}
	}
	else       //尚未找完所有物品
	{
		if (tw + w[i] <= W)       //左剪枝减去重量大于6的叶子节点
		{
			op[i] = 1;
			dfs01(i + 1, tw + w[i], tv + v[i],rw-w[i], op);      //选取第i个物品
		}
		
		if (tw + rw-w[i] >= W)      //右剪枝减去重量小于6的叶子节点
		{
			op[i] = 0;
			dfs01(i + 1, tw, tv, rw-w[i],op);      //不选取第i个物品
		}
		
	}
}

//轮船装载问题
int w1[] = { 0,5,2,6,4,3 };    //各集装箱的重量
int n1 = 5;
int W1 = 10;  //剩余轮船承载重量

int maxw = 0;       //存放最优解的重量
int x2[5];       //存放最优解向量

//tw：选择的重量和，rw表示剩余集装箱的重量和（初始时为全部集装箱重量和）
void loadDfs(int i, int tw, int rw, int op[])
{
	if (i>n1)
	{
		if (tw > maxw)
		{
			maxw = tw;
			for (int j = 1; j < n1; j++)
				x2[j] = op[j];
		}
	}
	else
	{
		if (tw + w1[i] <= W1)  //左剪枝
		{
			op[i] = 1;
			loadDfs(i + 1, tw + w[i], rw - w[i], op);
		}

		if (tw + rw - w1[i] > maxw)    //tw加上剩余集装箱重量大于最大的价值
		{
			op[i] = 0;   //不选取第i个节点
			loadDfs(i + 1, tw, rw-w[i], op);     //减去不选的，因为rw是剩余集装箱重量
		}
	}
}

//求解复杂装载问题
//有一批共n个集装箱要装上两艘载重量分别为c1和c2的轮船，其中集装箱i的重量为wi，且w1+w2+…+wn≤c1+c2。  
//装载问题要求确定是否有一个合理的装载方案可将这些集装箱装上这两艘轮船。如果有，找出一种装载方案。
void clDfs(int i, int tw, int rw, int op[]);