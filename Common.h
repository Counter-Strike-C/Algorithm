#pragma once
#include <stdlib.h>
#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#include<string>
#define MAXN
#define MAXM
#define INF 32727
#define MAXSIZE 100
const int MAXLEN = 255;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef struct TElemType {
	int a;

	bool operator ==( const TElemType &b)
	{
		return this->a == b.a?true:false;
	}
}TElemType;

#pragma region 二叉树的顺序存储
typedef TElemType SqBiTree[MAXSIZE];
#pragma endregion

#pragma region 二叉树的链式存储
typedef struct BTNode {
	TElemType data;
	struct BTNode* lchild, * rchild;   //左右孩子指针
}BTNode, * BTree;

//遍历二叉树
//层次遍历算法
void LevelOrder(BTNode* b)
{
	BTree  p;
	queue<BTree>  qu;
	qu.push(b);
	while (!qu.empty())
	{
		p = qu.front();

		qu.pop();
		cout << p->data.a << endl;
		if (p->lchild != NULL)qu.push(p->lchild);
		if (p->rchild != NULL)qu.push(p->rchild);
	}
}
