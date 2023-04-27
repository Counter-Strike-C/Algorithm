#include "ALG_BaBMethod.h"
int n = 6;
void ALG_BaBMethod::bfs_2()
{
	NodeType_M_1 e, e1;     //根节点和子节点
	queue<NodeType_M_1> pqu; 
	e.vno = v;
	e.length = 0;
	pqu.push(e);   //源节点进队
}
struct NodeType_1		//队列结点类型
{
	int no;			//结点编号
	int i;			//人员编号
	int x[MAXN];		//x[i]为人员i分配的任务编号
	bool worker[MAXN];		//worker[i]=true表示任务i已经分配
	int cost;			//已经分配任务所需要的成本
	int lb;			//下界
	bool operator<(const NodeType_1& s) const	//重载<关系函数
	{
		return lb > s.lb;
	}
};

int c[MAXN][MAXN] = { {0},{0,9,2,7,8},{0,6,4,3,7},
	{0,5,8,1,8},{0,7,6,9,4} };
//下标0的元素不用
int bestx[MAXN];		//最优分配方案
int mincost = INF;		//最小成本
int total = 1;			//结点个数累计

//分枝限界法求解任务分配问题
void debug_1()
{
	n = 4;

}

//求下界的函数
void bound(NodeType_1& e)
{
	
	int minsum = 0;
	for (int i1 = e.i + 1; i1 <= n; i1++)   //考虑未分配的人员
	{
		int minc = INF;
		for (int j1 = 1; j1 <= n; j1++)      //遍历某人的成本
		{
			if (e.worker[j1] == false && c[i1][j1] <= minc)  //如果任务没有分配,找到最小的成本
			{
				minc = c[i1][j1];
			}
			minsum += minc;
		}
	}
	e.lb = e.cost + minsum;
}

void bfs_3()          //求解任务分配
{
	int j;
	NodeType_1 e, e1;
	priority_queue<NodeType_1> qu;
	memset(e.x, 0, sizeof(e.x));
	memset(e.worker, 0, sizeof(e.worker));  //初始化根节点的worker

	e.i = 0;    //根节点指定人员为0
	e.no = total++;
	e.cost = 0;    
	bound(e);
	qu.push(e);       //根节点入队

	while (!qu.empty())  //
	{
		e = qu.top();
		qu.pop();      //出队节点e考虑当前人员i
		if (e.i == n)    //若达到叶子节点
		{
			if (e.cost < mincost)   //比较求最优解
			{
				mincost = e.cost;
				for (int i = 0; i <= n; i++) //找到最优解，复制解向量
					bestx[i] = e.x[i];
			}
		}
		e1.i = e.i + 1;  //分配下一个人员
		for (int j = 1; j <= n; j++)
		{
			if (e.worker[j] == 1)
				continue;
			for (int i = 1; i <= n; i++)
				e1.x[i] = e.x[i];   //复制解向量
			e1.x[e1.i] = j;      //分配任务j
			for (int i2 = 1; i2 <= n; i2++)
				e1.worker[i2] = e.worker[i2];
			e1.worker[j] = true;     //任务j已经分配
			e1.cost = e.cost + c[e1.i][j];
			bound(e1);      //求e1的边界
			e1.no = total++;
			if (e1.lb < mincost)      //剪枝
				qu.push(e1);
		}

	}
}

int a[MAX] = { 0,5,12,4,8 };	//M1上的执行时间,不用下标0的元素
int b[MAX] = { 0,6,2,14,7 };	//M2上的执行时间,不用下标0的元素

//求解结果表示
int bestf = INF;			//存放最优调度时间
//int bestx[MAX];		//存放当前作业最佳调度
//int total = 1;			//结点个数累计


int n = 4;			//作业数
int a[MAX] = { 0,5,12,4,8 };	//M1上的执行时间,不用下标0的元素
int b[MAX] = { 0,6,2,14,7 };	//M2上的执行时间,不用下标0的元素  在i=0时，b[0]用于判断f2
//求解结果表示
//int bestf = INF;			//存放最优调度时间
int bestx[MAX];		//存放当前作业最佳调度
int total = 1;			//结点个数累计

//求解流水线作业调度问题
void debug_2()
{
	n = 4;
	free(bestx);
	total = 1;
	bestf = INF;
}

struct NodeType_2		//队列结点类型
{
	int no;			//结点编号
	int x[MAX];			//x[i]表示第i步分配作业编号
	int y[MAX];			//y[i]=1表示编号为i的作业已经分配  //
	int i;			//步骤编号
	int f1;			//已经分配作业M1的执行时间
	int f2;			//已经分配作业M2的执行时间
	int lb;			//下界
	bool operator<(const NodeType_2& s) const	//重载<关系函数
	{
		return lb > s.lb;	//lb越小越优先出队
	}
};

//边界函数
void bound_2(NodeType_2 &e)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (e.y[i] == 0) sum += b[i];      //如果没有分配，则求剩余b时间总和
	e.lb = sum;     //求出边界
}

//求解
void bfs_2()
{
	NodeType_2 e, e1;
	priority_queue<NodeType_2> qu;
	e.i = 0;
	e.no = total++;
	e.f1 = 0;
	e.f2 = 0;
	bound_2(e);
	qu.push(e);   //根节点
	while (!qu.empty())
	{
		e = qu.top();
		qu.pop();
		//if (e.i == n)    //到叶子节点了
		//{
		//	if (e.f2 < bestf)
		//	{
		//		bestf = e.f2;
		//		for (int i = 0; i <= n; i++)
		//			bestx[i] = e.x[i];
		//	}
		//}
		e1.i = e.i + 1;
		for (int j = 1; j <= n; j++)
		{
			if (e.y[j] == 1)continue;
			for (int i1 = 1; i1 <= n; i1++)
				e1.x[i1] = e.x[i1];
			for (int i2 = 1; i2 <= n; i2++)
				e1.y[i2] = e.y[i2];
			e1.x[e1.i] = j;     //为第i步分配作业j
			e1.y[j] = 1;    //j已分配
			e1.f1 = e.f1 + a[j];      //求f1      f1=f1+a[j]
			e1.f2 = max(e1.f1, e.f2) + b[j];   //求f2        f[i+1]=max(f2[i],f1)+b[j]
			
			bound_2(e1);
			if (e1.i == n)  //如果到达叶子节点
			{
				if (e1.f2 < bestf)   //比较求最优解
				{
					bestf = e1.f2;
					for (int i = 0; i <= n; i++)
							bestx[i] = e.x[i];
				}
			}
			else if (e1.lb < bestf)      //减去不会得到最优解的解
			{
				e1.no = total++;    //节点编号+1
				qu.push(e1);
			}
		} 
	}
}