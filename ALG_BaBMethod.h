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
			e.ub = sumv + (W - sumw) * v[i] / w[i]; //不能装满
		else
			e.ub = sumv;    //可以装满
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

#pragma region 01背包问题，采用优先队列式分枝限界法求解
	//采用优先队列式分枝限界法求解就是将一般的队列改为优先队列，但必须设计限界函数，
	// 因为优先级是以限界函数值为基础的。
	//限界函数的设计方法与前面的相同。
	//这里用大根堆表示活结点表，取优先级为活结点所获得的价值。

void bfs_1()  //01背包问题求解
{
	int j;
	NodeType e, e1, e2;  //根节点，左孩子节点，右孩子节点
	priority_queue<NodeType> qu;   //定义优先队列
	e.i = 0;
	e.w = 0;
	e.v = 0;
	e.no = total++;
	for (j = 1; j <= n; j++)
		e.x[j] = 0;   //初始化解向量
	bound(e);   //计算出节点e的上界
	qu.push(e);       //根节点进队

	while (!qu.empty())   //队不空的时候循环     每一层表示一个循环，使用队列完成二叉排列树，而不使用递归
	{
		e = qu.top();
		qu.pop(); //节点e出队
		if (e.w + w[e.i + 1] <= W)   //生成左孩子节点
		{
			e1.no = total++;
			e1.i = e.i = 1 + 1;
			e1.w = e.w + w[e1.i];
			e1.v = e.v + v[e1.i];
			for (j = 1; j <= n; j++)
				e1.x[j] = e.x[j];   //复制解向量
			bound(e1); 
			qu.push(e1);
		}

		e2.no = total++;     //建立右孩子节点
		e2.i = e.i + 1;
		e2.w = e.w;
		e2.v = e.v;
		for (j = 1; j <= n; j++)
			e2.x[j] = e.x[j];
		e2.x[e2.i] = 0;
		bound(e2);
		if (e2.ub > maxv)       //若右孩子节点可行则进队否则被剪枝
			qu.push(e2);
	}
}
#pragma endregion

#pragma region 6.3 求解图的单源最短路径，采用队列式分枝限界法求解
//【问题描述】给定一个带权有向图G = （V，E），其中每条边的权是一个正整数。
//另外，还给定V中的一个顶点v，称为源点。计算从源点到其他所有顶点的最短路径长度。
//这里的长度是指路上各边权之和。
int a[MAXN][MAXN];	//图的邻接矩阵
int v;			//源点

//求解结果表示
int dist[MAXN];	//dist[i]源点到顶点i的最短路径长度
int prev[MAXN];	//prev[i]表示源点到j的最短路径中顶点j的前驱顶点


typedef struct NodeType_M_1		//队列结点类型
{
	int vno;			//顶点编号
	int length;			//路径长度
} NodeType_M_1;

void bfs_2();
#pragma endregion



};

