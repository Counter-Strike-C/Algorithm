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
void fun(char op[], int sum, int prevadd, int a[], int i)
{

}