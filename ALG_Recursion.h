#pragma once
#include "Common.h"
//递归算法设计

int MAX(int a, int b)
{
	return a > b ? a : b;
}

//例2.5 用递归法求一个整数数组a的最大元素
int fmax(int a[], int i)
{
	if (i == 1)   //递归出口
		return a[0];
	else
		return MAX(fmax(a, i - 1), a[i - 1]);
}



//对于n个节点二点二叉树,节点为Int类型，由先序序列a和中序序列b创建二叉链存储结构
BTNode* CreateBTree(TElemType a[], TElemType b[], int n)
//先序和中序
{
	int k;
	if (n <= 0) return NULL;
	TElemType root = a[0];    //选取a中的根节点
	BTNode* bt = (BTNode*)malloc(sizeof(BTNode));    //创建根节点
	bt->data = root;

	for (k = 0; k < n; k++)
		if (b[k] == root)
			break;

	bt->lchild = CreateBTree(a + 1, b, k);
	bt->rchild = CreateBTree(a + k + 1, b + k + 1, n - k - 1);
	return bt;

}

//例2.10 由二叉树的复制，和二叉树的遍历同一个原理
void CopyBTree(BTNode* bt, BTNode* bt1)
{
	if (bt == NULL)
		bt1 = NULL;
	else
	{
		bt1 = new BTNode;
		bt1->data = bt->data;
		CopyBTree(bt->lchild, bt1->lchild);
		CopyBTree(bt->rchild, bt1->rchild);
	}
}


//例2.11 找到值等于x的节点的路径，不能引用tmppath因为要暂时保存路径
bool Findxpath2(BTNode* bt, int x, vector<TElemType> tmppath, vector<TElemType>& path)
{
	if (bt == NULL)    //空树返回false
		return false;
	tmppath.push_back(bt->data);      //当前节点加入path
	if (bt->data.a == x)     //递归出口
	{
		path = tmppath;  //获取临时路径
		return true;   
	}
	bool find = Findxpath2(bt->lchild, x, tmppath, path);    //在左子树中查找
	if (find)
		return true;     //递归出口
	else
		return Findxpath2(bt->rchild, x, tmppath, path);
}

//例2.12 输出一个大于零的十进制数n的各数字位，如n=123，输出各数字位为123。
void Digits(int n)
{
	if (n != 0)
	{
		
		Digits(n/10);
		cout << n % 10 << endl;
	}
}


//N皇后的问题
const int n = 10;
int q[n];
bool place(int i, int j)       //测试（i，j）位置能否摆放皇后
{
	if (i == 1)return true;        //第一个皇后总是可以放置
	int k = 1;
	while (k < i)    //k=1~i-1是已放置了皇后的行
	{
		if((q[k]==j) || (abs(q[k]-j)==abs(i-k)) )
			return false;
			k++;
	}
	return true;
}

void queen(int i, int n)
{
	if (i > n)
		for (int k = 0; k < n; k++)      //所有皇后放置结束
			cout<<"result: " << q[k] << endl;
	else
	{
		for(int j=1;j<n;j++)   //在第i行试探每一列
			if (place(i, j ))       //在第i行上找到一个合适的位置
			{
				q[i] = j;
				queen(i + 1, n);
			}
	}
}