#pragma once
#define MAX 1025
#include "Common.h"
//���ݷ��㷨���������


//1����һ����n������������a������Ԫ�ؾ�����ͬ�����һ���㷨���������Ӽ����ݼ�����
void dispaSSsolution(int a[], int n, int x[])
{
	cout << "{";
	for (int i = 0; i < n; i++)
	{
		if (x[i] == 1)
			cout << a[i] << " ";
	}
	cout << "}  ";
}
void dfsSubSet(int a[], int n, int i, int x[])
{
	if (i >= n)
		dispaSSsolution(a, n, x);
	else
	{
		x[i] = 0;
		dfsSubSet(a, n, i + 1, x);
		x[i] = 1;
		dfsSubSet(a, n, i + 1, x);
	}
}

//���һ���㷨��1��2������9��˳���ܱ䣩����֮�����+��-��ʲô�������룬
//ʹ�ü���������100�ĳ��򣬲�������еĿ����ԡ�
//���磺1 + 2 + 34�C5 + 67�C8 + 9 = 100��
const int N = 9;
void fun(char op[], int sum, int prevadd, int a[], int i)
{
	if (i == N)
	{
		if (sum == 100)
		{
			cout << a[0];
			for (int j = 1; j < N; j++)
			{
				if (op[j] != ' ')
					cout << op[j];
				cout << a[j];
			}
			cout << "=100" << endl;
		}
		return;
	}

	op[i] = '+';
	sum += a[i];
	fun(op, sum, a[i], a, i + 1);
	sum -= a[i];        //���ݣ��Ա���м��ŵĵݹ�

	op[i] = '-';
	sum -= a[i];
	fun(op, sum, -a[i], a, i + 1);
	sum += a[i];

	op[i] = ' ';
	sum -= prevadd;      //�ȼ�ȥǰ���Ԫ�أ��Ա�ϳ�һ����
	int tmp;
	if (prevadd > 0)  //�ж��Ƿ�������
		tmp = prevadd * 10 + a[i];     //��prevadd=5,a[i]=6,���Ϊ56
	else
		tmp = prevadd * 10 - a[i];
	sum += tmp;   //����ϲ����
	fun(op, sum, tmp, a, i + 1);
	sum -= tmp;       //����
	sum += prevadd;
}

//��һ����n������������a������Ԫ�ؾ�����ͬ����������Ԫ�ص�ȫ���С�
//���磬a[] = { 1��2��3 }���õ�����ǣ�1��2��3������1��3��2������2��3��1������2��1��3������3��1��2������3��2��1����

void dispacdfssolution(int a[],int  n)
{
	cout << "{";
	for (int  i = 0; i < n; i++)
	{
		cout << a[i] << ", ";
	}
	cout << "} ";
}
void cdfs(int a[], int n, int i)
{
	if (i >= n)
		dispacdfssolution(a, n);
	else
	{
		for (int j = i; j < n; j++)
		{
			swap(a[i], a[j]);  //���ν���ʹ�õ�һ���ֱ�Ϊ1��2��3��ͨ���ݹ��γɽ�ռ���
			cdfs(a, n, i + 1);
			swap(a[i], a[j]);
		}
	}
}


//01��������
int n2 = 4;  //4����Ʒ
int W = 6;     //��������Ϊ6
int w[] = { 0,5,3,2,1 };      //����
int v[] = { 0,4,4,3,1 };       //��ֵ
//�����չʾ
int x1[5];       //������ս�
int maxv;      //������Ž���ܼ�ֵ
void dfs01(int i, int tw, int tv, int rw,int op[])
{
	if (i > n2)      //�ҵ�һ��Ҷ�ӽڵ�
	{
		if (tw == W && tv > maxv)        //�ҵ�һ�����������ĸ��Ž⣬����
		{
			maxv = tv;
			for (int j = 1; j < n; j++)
				x1[j] = op[j];       //������
		}
	}
	else       //��δ����������Ʒ
	{
		if (tw + w[i] <= W)       //���֦��ȥ��������6��Ҷ�ӽڵ�
		{
			op[i] = 1;
			dfs01(i + 1, tw + w[i], tv + v[i],rw-w[i], op);      //ѡȡ��i����Ʒ
		}
		
		if (tw + rw-w[i] >= W)      //�Ҽ�֦��ȥ����С��6��Ҷ�ӽڵ�
		{
			op[i] = 0;
			dfs01(i + 1, tw, tv, rw-w[i],op);      //��ѡȡ��i����Ʒ
		}
		
	}
}

//�ִ�װ������
int w1[] = { 0,5,2,6,4,3 };    //����װ�������
int n1 = 5;
int W1 = 10;  //ʣ���ִ���������

int maxw = 0;       //������Ž������
int x2[5];       //������Ž�����

//tw��ѡ��������ͣ�rw��ʾʣ�༯װ��������ͣ���ʼʱΪȫ����װ�������ͣ�
void loadDfs(int i, int tw, int rw, int op[])
{
	if (i>n1)
	{
		if (tw > maxw)
		{
			maxw = tw;
			for (int j = 1; j < n1; j++)
				x2[j] = op[j];
		}
	}
	else
	{
		if (tw + w1[i] <= W1)  //���֦
		{
			op[i] = 1;
			loadDfs(i + 1, tw + w[i], rw - w[i], op);
		}

		if (tw + rw - w1[i] > maxw)    //tw����ʣ�༯װ�������������ļ�ֵ
		{
			op[i] = 0;   //��ѡȡ��i���ڵ�
			loadDfs(i + 1, tw, rw-w[i], op);     //��ȥ��ѡ�ģ���Ϊrw��ʣ�༯װ������
		}
	}
}

//��⸴��װ������
//��һ����n����װ��Ҫװ�������������ֱ�Ϊc1��c2���ִ������м�װ��i������Ϊwi����w1+w2+��+wn��c1+c2��  
//װ������Ҫ��ȷ���Ƿ���һ�������װ�ط����ɽ���Щ��װ��װ���������ִ�������У��ҳ�һ��װ�ط�����
void clDfs(int i, int tw, int rw, int op[]);