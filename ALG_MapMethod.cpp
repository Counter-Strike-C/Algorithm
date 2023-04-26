#include "ALG_MapMethod.h"
#include "Graph.cpp"
#include "Common.h"
//图算法设计


typedef set<int> SET;   //定义集合
MGraph g;      //图的邻接矩阵
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
	int minpathlen = INF;
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
void debug2()
{
	//问题表示
	int s;    

	//求解问题表示
	int Count = 1;   //路径条数累计
	vector<int>minpath;     //最短路径数组
	int minpathlen = INF;

}
