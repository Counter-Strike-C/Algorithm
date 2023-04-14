#pragma once
#include "Common.h"
class ALG_BaBMethod
{
#pragma region 01背包问题

	//问题表示
	int n = 3, W = 30;
	int w[4] = { 0,16,15,15 };				//重量，下标0不用
	int v[4] = { 0,45,25,25 };  				//价值，下标0不用
	//求解结果表示
	int maxv = -9999;						//存放最大价值,全局变量
	int bestx[MAXN];					//存放最优解,全局变量

	int total = 1;						//解空间中结点数累计,全局变量

	struct NodeType		//队列中的结点类型
	{
		int no;			//结点编号，从1开始
		int i;			//当前结点在搜索空间中的层次
		int w;			//当前结点的总重量
		int v;			//当前结点的总价值
		int x[MAXN];		//当前结点包含的解向量
		double ub;			//上界
		bool operator<(const NodeType& s) const	//重载<关系函数
		{
			return ub < s.ub;				//ub越大越优先出队
		}
	};

	//计算结点e的上界e.ub算法
	void bound(NodeType& e)
	{
		int i = e.i + 1;
		int sumw = e.w;
		double sumv = e.v;
		while (i<=n&&(sumw+w[i]<W))
		{
			sumw += w[i];
			sumv += v[i];
			i++;
		}
		if (i <= n)
			e.ub = sumv + (W - sumw) * v[i] / w[i];
		else
			e.ub = sumv;
	}

	void EnQueue(NodeType e, queue<NodeType>& qu)
	{
		if (e.i == n)  //到达叶子节点
		{
			if (e.v > maxv)   //找到价值更大的解
			{
				maxv = e.v;
				for (int j = 1; j <= n; j++)
					bestx[j] = e.x[j];
			}
		}
		else qu.push(e);        //非叶子节点进队
	}


	void bfs1()    //求01背包的最优解
	{
		int j;
		NodeType e, e1, e2;
		queue<NodeType> qu;

		e.i = 0;
		e.w = 0;
		e.v = 0;
		e.no = total++;
		for (j = 1; j <= n; j++)
			e.x[j] = 0;	
		bound(e);         //求根节点的上界
		qu.push(e);      //根节点进队

		while (!qu.empty())    //队不空循环
		{
			e = qu.front();
			qu.pop();   //出队节点

			if (e.w + w[e.i + 1] <= W)        //剪枝，检查左孩子节点
			{
				e1.no = total++;     //e1作为新的左孩子节点
				e1.i = e.i + 1; 
				e1.w = e.w + w[e1.i];
				e1.v = e.v + v[e1.i];    //
				for (j = 1; j <= n; j++)
					e1.x[j] = e.x[j];     //复制解向量
				e1.x[e1.i] = 1;  //设置当前解向量
				bound(e1);
				EnQueue(e1,qu);     //左孩子
			}
			e2.no = total++;       //建立右孩子节点
			e2.i = e.i++;
			e2.w = e.w;
			e2.v = e.v;
			for (j = 1; j <= n; j++)        //复制解向量
				e2.x[j] = e.x[j];
			e2.x[e2.i] = 0;	
			bound(e2);   //求右孩子节点的上界
			if (e2.ub > maxv)    //若右孩子节点可行	，则进队，否则被剪枝
				EnQueue(e2, qu);

				
		}
	}
#pragma endregion




};

