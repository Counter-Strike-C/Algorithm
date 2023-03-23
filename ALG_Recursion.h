#pragma once
#include "Common.h"
//�ݹ��㷨���

int MAX(int a, int b)
{
	return a > b ? a : b;
}

//��2.5 �õݹ鷨��һ����������a�����Ԫ��
int fmax(int a[], int i)
{
	if (i == 1)   //�ݹ����
		return a[0];
	else
		return MAX(fmax(a, i - 1), a[i - 1]);
}



//����n���ڵ���������,�ڵ�ΪInt���ͣ�����������a����������b�����������洢�ṹ
BTNode* CreateBTree(TElemType a[], TElemType b[], int n)
//���������
{
	int k;
	if (n <= 0) return NULL;
	TElemType root = a[0];    //ѡȡa�еĸ��ڵ�
	BTNode* bt = (BTNode*)malloc(sizeof(BTNode));    //�������ڵ�
	bt->data = root;

	for (k = 0; k < n; k++)
		if (b[k] == root)
			break;

	bt->lchild = CreateBTree(a + 1, b, k);
	bt->rchild = CreateBTree(a + k + 1, b + k + 1, n - k - 1);
	return bt;

}

//��2.10 �ɶ������ĸ��ƣ��Ͷ������ı���ͬһ��ԭ��
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


//��2.11 �ҵ�ֵ����x�Ľڵ��·������������tmppath��ΪҪ��ʱ����·��
bool Findxpath2(BTNode* bt, int x, vector<TElemType> tmppath, vector<TElemType>& path)
{
	if (bt == NULL)    //��������false
		return false;
	tmppath.push_back(bt->data);      //��ǰ�ڵ����path
	if (bt->data.a == x)     //�ݹ����
	{
		path = tmppath;  //��ȡ��ʱ·��
		return true;   
	}
	bool find = Findxpath2(bt->lchild, x, tmppath, path);    //���������в���
	if (find)
		return true;     //�ݹ����
	else
		return Findxpath2(bt->rchild, x, tmppath, path);
}

//��2.12 ���һ���������ʮ������n�ĸ�����λ����n=123�����������λΪ123��
void Digits(int n)
{
	if (n != 0)
	{
		
		Digits(n/10);
		cout << n % 10 << endl;
	}
}


//N�ʺ������
const int n = 10;
int q[n];
bool place(int i, int j)       //���ԣ�i��j��λ���ܷ�ڷŻʺ�
{
	if (i == 1)return true;        //��һ���ʺ����ǿ��Է���
	int k = 1;
	while (k < i)    //k=1~i-1���ѷ����˻ʺ����
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
		for (int k = 0; k < n; k++)      //���лʺ���ý���
			cout<<"result: " << q[k] << endl;
	else
	{
		for(int j=1;j<n;j++)   //�ڵ�i����̽ÿһ��
			if (place(i, j ))       //�ڵ�i�����ҵ�һ�����ʵ�λ��
			{
				q[i] = j;
				queen(i + 1, n);
			}
	}
}