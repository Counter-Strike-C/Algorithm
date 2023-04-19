#pragma once
#include "Common.h"
#define N 4
//贪心算法设计

//求解活动安排问题
//问题表示
struct Action     //活动的类型声明
{
	int b;   //活动开始和结束时间
	int e;
	bool operator< (const Action& s) const
	{
		return e < s.e;
	}
};

int n = 11;
Action A[] = { {0},{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},
	 {8,12},{2,13},{12,15} };	//下标0不用
//求解结果表示
bool flag[MAXN];		//标记选择的活动
int Count = 0;			//选取的兼容活动个数

void solve()
{
	memset(flag, 0, sizeof(flag));     //初始化为false
	sort(A + 1, A + n + 1);    //对A活动结束时间进行递增排序
	int preend = 0;    //前一个兼容活动的结束时间
	for (int i = 1; i <= n; i++)
	{
		if (A[i].b > preend)
		{
			flag[i] = true;
			preend = A[i].e;  //更新活动结束时间
		}
	}
}

struct Cow
{
	int no;       //牛编号
	int b;
	int e;
	bool operator< (const Cow& s) const
	{
		if (e == s.e)
			return b < s.b;
		else
			return e < s.e;
	}
};

int n1 = 5;
Cow A[] = { {0},{1,1,10},	{2,2,4},{3,3,6},{4,5,8},{5,4,7} };
//下标0不用
//求解结果表示
int ans[MAXN];			//ans[i]表示第A[i].no头牛的蓄栏编号

void solve_1()
{
	sort(A + 1, A + n + 1);     //按指定方式排序
	memset(ans, 0, sizeof(ans));     //编号初始化
	int num = 1;
	for (int i = 1; i <= n1; i++)
	{
		if (ans[i] == 0)   //如果第i头牛还没有安排蓄栏
		{
			ans[i] = num;
			int preend = A[i].e;
			for (int j = i+1; j <= n; j++)
			{
				if (A[j].b > preend && ans[j] == 0)   //如果没有安排蓄栏和满足条件
				{
					ans[j] = num;  //安排蓄栏
					preend = A[j].e;   //更新兼容活动时间
				}

			}
		}
		num++; //下一个蓄栏
	}


}


//求解背包问题
int n2 = 50;
double W = 100;    //限重
struct NodeType
{
	double w;
	double v;
	double p;
	bool operator<(const NodeType& s) const
	{
		return p > s.p;			//按p递减排序
	}



};
NodeType A2[] = { {0},{10,20},{20,30},{30,66},{40,40},{50,60} };
//求解结果表示
double V;				//大价值
double x_2[MAXN];

void Knap_2()
{
	for (int i = 1; i <= n; i++)		//求v/w
		A2[i].p = A2[i].v / A2[i].w;
	sort(A + 1, A + n + 1);

	V = 0;
	double weight = W;       //背包剩余能装入的重量
	memset(x_2, 0, sizeof(x_2));
	int i = 1;

	while (A2[i++].w < weight)        //物品i能够全部装入时循环
	{
		x_2[i] = 1;  //装入
		weight -= A2[i].w;
		V += A2[i].v;
	}

	if (weight > 0)
	{
		x_2[i] = weight / A2[i].w;       //将物品i的一部分放入
		V += A2[i].v * x_2[i];      //累计总价值
	}
}


//求解最优装载问题
int w_3[] = { 0,5,2,6,4,3 };
//求解结果表示
int maxw;        //存放最优解
int x_3[MAXN];        //存放最优解向量

void solve_3()
{
	n = 5;
	W = 10;

	memset(x_3, 0, sizeof(x_3));
	sort(w_3 + 1, w_3 + n + 1);
	maxw = 0;
	int restw = W;
	for (int i = 1; i <= n && w_3[i]<=restw; i++)
	{
		x_3[i] = 1;
		restw -= w_3[i];
		maxw += w_3[i];
	}
}

//4、求解多机调度问题
int m_4 = 3;
struct NodeType_4				//优先队列结点类型
{
	int no;					//作业序号
	int t;					//执行时间
	int mno;					//机器序号
	bool operator<(const NodeType_4& s) const      //按t越小越优先出队
	{
		return t > s.t;
	}			
};
struct NodeType_4 A4[] = { {1,2},{2,14},{3,4},{4,16},{5,6},{6,5},{7,3} };

//求解多机调度问题
void solve_4()
{
	n = 7;
	NodeType_4 e;
	if (n < m_4)
	{
		cout << "为每一个作业分配一台机器。" << endl;
		return;
	}
	sort(A4 , A4 + n );
	priority_queue<NodeType_4>qu;       //建立小根堆
	for (int i = 0; i < m_4; i++)     //先按时间由大到小分配
	{
		A4[i].mno = i;
		qu.push(A4[i]);    //进入小根堆
	}

	for (int j = m_4; j < n; j++)   //分配余下的作业
	{
		e = qu.top();
		qu.pop();
		e.t += A4[j].t;
		qu.push(e);     //t进队
	}
}


//求解哈夫曼编码问题
struct HTreeNode			//哈夫曼树结点类型
{
	char data;				//字符
	int weight;				//权值
	int parent;				//双亲的位置
	int lchild;				//左孩子的位置
	int rchild;				//右孩子的位置
};
HTreeNode ht[MAXN];			//存放哈夫曼树
map<char, string> htcode;		//存放哈夫曼编码

struct NodeType_5			//优先队列结点类型
{
	int no;				//对应哈夫曼树ht中的位置
	char data;				//字符
	int  weight;			//权值
	bool operator<(const NodeType_5& s) const
	{					//用于创建小根堆
		return s.weight < weight;
	}
};

void CreateHTree()       //构造哈夫曼编码
{
	n = sizeof(ht);
	NodeType_5 e, e1, e2;
	priority_queue<NodeType_5> qu;      //建立小根堆
	for (int k = 0; k < 2 * n - 1 ;k++)   //初始化所有节点的指针域
		ht[k].lchild = ht[k].rchild = ht[k].parent = -1;

	for (int i = 0; i < n; i++)      //将所有节点进队
	{
		e.no = i;
		e.data = ht[i].data;
		e.weight = ht[i].weight;
		qu.push(e);
	}

	for (int j = n; j < 2 * n - 1; j++)      //构造哈夫曼树的n-1个非叶子节点
	{
		e1 = qu.top(); qu.pop();   //出队权值最小的节点

		e2 = qu.top();     //次小节点出列
		qu.pop();

		ht[j].weight = e1.weight + e2.weight;       //构造非叶子节点
		ht[j].lchild = e1.no;
		ht[j].rchild = e2.no;
		ht[e1.no].parent = j;   //修改e1.no的双亲为节点j
		ht[e2.no].parent = j;
		e.no = j;    //构造队列节点e
		e.weight = e1.weight + e2.weight;
		qu.push(e);
	}
}

void CreateHCode()
{
	string code;
	code.reserve(MAXN);

	for (int i = 0; i < n; i++)      //构造叶子节点i的哈夫曼编码
	{
		code = "";
		int curno = i;//遍历每一个节点并输出编码
		int f = ht[curno].parent;
		while (f != -1)
		{
			if (ht[f].lchild == curno)  //curno为双亲f的左孩子
				code = '0' + code;
			else
				code = '1' + code;      //curno为双亲f的右孩子
			curno = f;
			f = ht[curno].parent;
		}
		htcode[ht[i].data] = code;    //保存相应字符的哈夫曼编码
	}
}

struct Action_6
{
	int d;			//完成期限
	int p;			//效益
	bool operator< (const Action_6 t) const
	{
		return p > t.p;		//按效益递减排序
	}
};
Action_6 A6[] = { {0},{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15} };	//下标0不用
Action_6 flag[MAXN];		//求解结果表示

void solve()
{
	memset(flag, 0, sizeof(flag));
	sort(A6, A6 + 1);
	int sum = 0;     //累计做过作业时间
	for (int i = 1; i <= sizeof(A6); i++)
	{
		if (A6[i].d > sum)
		{
			flag[i] = true;
			sum++;
		}
	}
}

/*
有n个作业，a1,a2，…，an，
作业aj的处理时间为tj，产生的效益为pj，最后完成期限为dj，作业一旦被调度则不能中断，
如果作业aj在dj前完成，则获得效益pj，否则无效益。给出最大化效益的作业调度算法。*/
//采用贪心算法
int t[] = { 0,1,4,1 };		//下标0不用
int d[] = { 0,5,4,5 };
int p[] = { 0,2,8,6 };
struct Action_7
{
	int t;			//处理时间
	int d;			//完成期限
	int p;			//效益
	bool operator< (const Action_6 t) const
	{
		return p > t.p;		//按效益递减排序
	}
};
Action_7 A7[51];	//下标0不用
int bestp = 0;			//最大的效益

void solve()
{
	for (int i = 1; i <= n; i++)	//产生A数组元素
	{
		A7[i].t = t[i];
		A7[i].d = d[i];
		A7[i].p = p[i];
	}

	sort(A7, A7 + 1);
	int sum = 0;
	for (int i = 1; i < sizeof(A7); i++)
	{
		if (A7[i].d > sum)
		{
			bestp += A7[i].p;
			sum += A7[i].t;
		}
	}
}

//贪心法求解流水作业调度问题
int a[N] = { 5,12,4,8 };		//对应M1的时间
int b[N] = { 6,2,14,7 };		//对应M2的时间

struct NodeType_8
{
	int no;			//作业序号
	bool group;			//1代表第一组N1,0代表第二组N2
	int time;			//a,b的最小时间
	bool operator<(const NodeType_8& s) const
	{
		return time < s.time;	//用于按time递增排序
	}
};
int best[N];			//最优调度序列

//求解问题
int solve_8()
{
	n = 4;
	int i, j, k;
	NodeType_8 c[N];
	for (int i = 0; i < n; i++)
	{
		c[i].no = i;
		c[i].group = (a[i] <= b[i]);
		c[i].time = a[i] <= b[i] ? a[i] : b[i];
	}
	sort(c, c + n);       //c元素按照time递增排序
	j = 0; k = n - 1;
	for (i = 0; i < n; i++)  //扫描c所有元素,产生最优调度方案
	{
		if (c[i].group == 1)
			best[j++] = c[i].no;//第1组,按time递增排列放在best的前面部分
		else
			best[k--] = c[i].no;//第0组,按time递减排列放到best的后面部分
	}
	int f1 = 0;   //累计M1上的执行时间
	int f2 = 0;    //最优调度下的消耗总时间
	for (i = 0; i < n; i++)
	{
		f1 += a[best[i]];
		f2 = max(f2, f1) + b[best[i]];
	}
	return f2;
}