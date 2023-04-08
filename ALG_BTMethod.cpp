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


const int num = 5;
int q[num];

bool place(int i)   //测试第i行的q[i]列上能否摆放皇后
{
	int j = 1;
	if (i == 1) return true;
	while (j < i)    //j = 1~i是已经放置了皇后的行
	{
		if ((q[j] == q[i] || abs(q[j] - q[i]) == abs(j - i)))
			//该皇后是否与以前皇后同列，位置（j、q[j])与(i、q[i])是否同对角线
			return false;
	}
	return true;
}

void disp1(int n)
{
	for (int i = 0; i < n; i++)
		cout << q[i] << endl;
}

//求解n皇后的问题，使用回溯法非递归方法

void Queens(int n)
{
	int i = 1;         //i表示当前行,放置第i个皇后
	q[i] = 0;         //q[i]表示当前列，每个新考虑的皇后初始位置置为0列
	while (i >= 1)      //尚未回溯到头，循环
	{
		q[i]++;         //原位置向后移动一列
		while (q[i] <= n && !place(i))  //试探一个位置,如果不能放置则
			q[i]++;  //向后移动一列

		if (q[i] < n)//为第i个皇后找到了一个合适位置(i,q[i])
		{
			if (i == n)  //若放置了所有皇后,输出一个解
				disp1(n);
			else        //皇后没有放置完
			{
				i++;        //开始下一行的放置
				q[i] = 0;       //每一个新的皇后初始位置为0列
			}
		}
		else i--;        //若第i个皇后找不到合适的位置，则回溯到上一个皇后
	}
}


//求解图的m着色问题
const int n2 = 5;
int a[5][5];
int count1 = 0;       //解的数量
int m = 4;   //颜色的数量
int k = 8;     //边的数量
bool Same(int i)        //判断顶点i是否与相邻顶点存在相同的着色
{
	for (int j = 1; j <= n; j++)
		if (a[i][j] == 1 && x[i] == x[j])
			return false;
	return true;

}

void mDfs(int i)        //求解图的m着色问题
{
	if (i > n)
		count1++;
	else
	{
		for (int j= 1; j < m; i++)    //m叉树，试探每一种颜色
		{
			x[i] = j;      //试探着色j
			if(Same(i))   //可以着色j
				mDfs(i + 1);   //下一个顶点着色
			x[i] = 0;       //不着色j，继续着色下一个颜色（回溯到兄弟节点)
		}
	}
}

//求解任务分配的问题,(0,0)不用
int x3[MAXN];     //临时解
int n4 = 4;
int  c2[MAXN][MAXN] = { {0},{0,9,2,7,8},{0,6,4,3,7},
				   {0,5,8,1,8},{0,7,6,9,4} };   //任务成本矩阵
int cost = 0;     //临时解的成本
int bestx[MAXN];       //最优解
int mincost = INF;      //最优解成本
bool worker[MAXN];          //worker[j]表示任务j是否已经分配人员

void dfs3(int i)        //为第i个人分配任务
{
	const int m = i;
	if (i > n4)      //到达叶子节点后
	{
		if (cost < mincost)          //比较求最优解
		{
			mincost =cost;
			for (int j = 1; j <= n4; j++)
				bestx[j] = x3[j];
		}
	}
	else
	{
		for (int j = 1; j < n4; j++)
		{
			worker[j] = true;
			x3[j] = 1;
			cost += c2[&m][&j];  //人物i分配任务j的花费
			dfs3(i + 1);
			worker[j] = false;    //回溯
			x3[j] = 0;
			cost -= c2[&m][&j];

		}
	}
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//5、求解活动安排问题
struct Action
{
	int b;				//活动起始时间
	int e;				//活动结束时间
};
int n5 = 4;
Action A5[] = { {0,0},{1,3},{2,5},{4,8},{6,10} }; //下标0不用

int x5[MAX];     //临时解向量
int bestx[MAX];       //最优解向量，保存的是各个活动的编号
int laste = 0;        //一个调度方案中最后兼容活动的结束时间,初值为0
int sum = 0;		//一个调度方案中所有兼容活动个数,初值为0
int maxsum = 0;    //最大的调度方案中所有兼容活动的个数，初值为0
void dfs5(int i)
{
	if (i > n5)
	{
		if (sum > maxsum)
		{
			maxsum = sum;
			for (int k = 1; k < n; k++)
				bestx[k] = x5[k];   //保存最优向量
		}
	}
	else
	{
		for (int j = 1; j < n; j++)
		{
			swap(a[i], a[j]);   //交换，避免选中重复
			int sum1 = sum;
			int laste1 = laste;
			if (A5[x5[j]].b >= laste)     //如果满足条件
			{
				sum++;  //活动数量加1
				laste = A5[x5[j]].e;
			}
			swap(a[i], a[j]);   //回溯
			int sum = sum1;
			int laste = laste1;
		}
	}
}

//6、求解流水作业调度问题
