#include "ALG_BTMethod.h"
#define MAXN 20
int w[] = { 0,10,40,40 };      //各集装箱的重量
int n = 3;
int c1 = 50, c2 = 50;
int maxw = 0;			//存放第一艘轮船最优解的总重量
int x[MAXN];			//存放第一艘轮船最优解向量

/// <summary>
/// 
/// </summary>
/// <param name="i">第i个集装箱</param>
/// <param name="tw">当前集装箱重量</param>
/// <param name="rw">剩余集装箱重量</param>
/// <param name="op">暂时存储解向量</param>
void clDfs(int i, int tw, int rw, int op[])
{
	if (i > n)
	{
		if (tw > maxw)    //判断是否是更优解
		{
			maxw = tw;
			for (int i = 0; i < n; i++)
				x[i] = op[i];          //复制更优解
		}
	}
	else
	{
		if (tw + w[i] <= c1)
		{
			op[i] = 1;
			clDfs(i+1, tw + w[i], rw - w[i], op);
		}
		if (tw + rw - w[i] > maxw)    //加上剩余质量能完成装载条件
		{
			op[i] = 0;
			clDfs(i+1, tw, rw - w[i], op);
		}

	}
}

bool solve()    //求解复杂装载问题
{
	int sum = 0;  //累计第一艘轮船装完后剩余的集装箱重量
	for (int i = 0; i <= n; i++)
		if (x[i] == 0)
			sum += w[i];
	if (sum <= c2)
		return true;
	else
		return false;
}


//求解子集和问题
//给定n个不同的正整数集合w=（w1，w2，…，wn）和一个正整数W，要求找出w的子集s，使该子集中所有元素的和为W。
//例如，当n = 4时，w = （11，13，24，7），W = 31，则满足要求的子集为（11，13，7）和（24，7）。

int W1 = 31;
void dfs1(int i, int tw, int rw, int x[])
{
	if (i > n)
	{
		if (tw == W1)
		{
			for (int i = 0; i < n; i++)       //输出结果
				cout << x[i];
		}
	}
	else
	{
		if (tw + w[i] <= W1)
		{
			x[i] = 1;
			dfs1(i + 1, tw + w[i], rw - w[i], x);
		}
		if (tw + rw - w[i] >= maxv)
		{
			x[i] = 0;
			dfs1(i + 1, tw, rw - w[i], x);
		}
	}
}


//求解n皇后的问题，使用回溯法非递归方法
const int num = 5;
int q[num];
void Queens(int n)
{
	int i = 1;         //i表示当前行,放置第i个皇后
	q[i] = 0;         //q[i]表示当前列，每个新考虑的皇后初始位置置为0列
	while (i > 1)
	{
		q[i]++;
		while(q[i]<=n && !)
	}

}

bool place(int i)   //测试第i行的q[i]列上能否摆放皇后
{
	int j = 1;
	if (i == 1) return true;
	while (j<i)
	{
		if((q[j]==q[i] || abs(q[j]-q[i])==abs(j-i))))
	}
}