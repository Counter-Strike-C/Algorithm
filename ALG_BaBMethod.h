#pragma once
#include "Common.h"
class ALG_BaBMethod
{
#pragma region 01背包问题

	struct NodeType		//队列中的结点类型
	{
		int no;			//结点编号，从1开始
		int i;			//当前结点在搜索空间中的层次
		int w;			//当前结点的总重量
		int v;			//当前结点的总价值
		int x[MAXN];		//当前结点包含的解向量
		double ub;			//上界
	};

#pragma endregion




};

