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

#pragma region ��������˳��洢
typedef TElemType SqBiTree[MAXSIZE];
#pragma endregion

#pragma region ����������ʽ�洢
typedef struct BTNode {
	TElemType data;
	struct BTNode* lchild, * rchild;   //���Һ���ָ��
}BTNode, * BTree;

//����������
//��α����㷨
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
