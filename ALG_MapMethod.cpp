#include "ALG_MapMethod.h"
#include "Graph.cpp"
#include "Common.h"
//图算法设计


typedef set<int> SET;   //定义集合
MGraph g;      //图的邻接矩阵
int minpathlen = INF;
//使用动态规划方法解决旅行家问题
void debug1()
{
	//求解tsp问题
	//问题表示
	int s = 0;    //起点为0

	int A[][MAXV] = {						//一个带权有向图
		{0,8,5,36},{6,0,8,5},{8,9,0,5},{7,7,8,0} };
	int n = 4, e = 12;
	CreateMat(g, A, n, e);					//创建图的邻接矩阵g
	SET V;
	for (int i = 1; i < g.n; i++)				//插入1,2,3顶点
		V.insert(i);    //建立顶点集合

	f(V, 0);

	free(&g);
}

int f(SET V, int i)
{

	if (V.size() == 0)   //当v为空时,直接返回当前边
		return g.edges[0][i];
	else     //集合不为空时
	{
		SET::iterator it;
		for (it = V.begin(); it != V.end(); ++it)        //扫描集合v中的顶点
		{
			SET tmpV = V;
			int j = *it;
			tmpV.erase(j);      //去除j
			int pathlen = f(tmpV, j) + g.edges[i][j];      //加上上一个点到这一个点距离
			minpathlen = min(minpathlen, pathlen);
		}
		return minpathlen;
	}
}

//回溯法求解tsp问题
int s = 0;
vector<int>minpath;     //最短路径数组
void debug2()
{
	minpath.clear();
	minpathlen = INF;
	//求解问题表示
	int Count = 1;   //路径条数累计
	int A[][MAXV] = {						//一个带权有向图
		{0,8,5,36}, {6,0,8,5}, {8,9,0,5}, {7,7,8,0} };
	int n = 4, e = 12;
	CreateMat(g, A, n, e);		//创建图的邻接矩阵存储结构g
	s = 0;					//起始顶点为0
	vector<int> path;
	int pathlen = 0;
	SET V;
	for (int i = 1; i < g.n; i++)			//插入1,2,3顶
		V.insert(i);
	TSP2(V, 0, path, pathlen);
}

//回溯法
void TSP2(SET V,int i,vector<int> path,int pathlen)
{
	int prev; 
	if (path.size() > 0)
		prev = path.back();        //prev为路径最后一个顶点
	path.push_back(i);     //添加当前顶点i
	pathlen += g.edges[prev][i];      //累计路径长度
	if (V.size() == 0)      //找到一个叶子节点
	{
		if (g.edges[i][s] != 0 && g.edges[i][s] != INF)  //如果顶点i到起点s之间有边
		{
			path.push_back(0);   //路径加入起点0
			pathlen += g.edges[i][s];     //累计路径长度
			if (pathlen < minpathlen)
			{
				minpathlen = pathlen;
				minpath = path;
			}
		}
	}
	else
	{
		SET::iterator it;
		for (it = V.begin(); it != V.end(); it++)
		{
			SET tmpV = V;
			int j = *it;
			tmpV.erase(j);
			if (pathlen < minpathlen)
				minpathlen = pathlen;
		}
	}
}

//分枝限界法求解问题
struct NodeType3			//队列结点类型
{
	int v;				//当前顶点
	int num;				//路径中的结点个数
	vector<int> path;			//当前路径
	int pathlen;			//当前路径长度
	int visited[MAXV];			//顶点访问标记
	bool operator<(const NodeType3& s) const
	{
		return pathlen > s.pathlen;	//pathlen越小越优先出队
	}
};
struct NodeType3;    //队列节点类型
void debug3()
{
	s = 0;

	int Count = 1;
	vector<int> minpath;     //保存最短路径
	minpathlen = INF;
	
}

//分枝限界法
void TSP3()
{
	NodeType3 e, e1;
	priority_queue<NodeType3> qu;        
	e.v = 0;          //根节点e
	e.pathlen = 0;
	e.path.push_back(0);
	e.num = 0;
	memset(e.visited, 0, sizeof(e.visited));
	e.visited[0] = 1;
	qu.push(e);       //根节点e进队

	while (!qu.empty())      //队不空循环
	{
		e = qu.top();
		qu.pop();      //出队节点e
		if (e.num == g.n)   //到达叶子节点
		{
			if (g.edges[e.v][s] != 0 && g.edges[e.v][s] != INF)   //如果e到根节点s之间有边
			{
				e.path.push_back(s);      //将起点加入到路径中
				e.pathlen += g.edges[e.v][s];       //另外计入从e.v到起点s的路径长度
				if (e.pathlen < minpathlen)    //更新最短路径
				{
					minpathlen = e.pathlen;
					minpath = e.path;
				}
			}
		}
		else  //非叶子节点
		{
			for (int j = 1; j < g.n; j++)    //顶点1到顶点j循环
			{
				if (g.edges[e.v][j] != 0 && g.edges[e.v][j] != INF)     //当前顶点到顶点j有边
				{
					if (e.visited[j] == 1)//跳过重复访问顶点
						continue;
					e1.v = j;
					e1.num = e.num + 1;
					e1.path = e.path;
					e1.path.push_back(j);
					e1.pathlen = e.pathlen + g.edges[e.v][j];
					for (int i = 0; i < g.n; i++)
						e1.visited[i] = e.visited[i];
					if (e1.pathlen < minpathlen)      //剪枝
					{
						e1.visited[j] = 1;
						qu.push(e1);
					}
				}
			}
		}
	}
}