#pragma once
#include "Common.h"
//���η��㷨���

//1���������򣨼����ݽṹ��Ŀ��
//2����·�鲢���򣨼����ݽṹ��Ŀ��
//3���Զ����µĶ�·�鲢�㷨��������

//4����ⰴ��������򡱵�����С���򡱵�˳���������⡣
//һ�������еġ�δ���򡱵Ķ���������ڱ˴�˳��һ�µ���Ŀ�Ե����������磬����ĸ���С�DAABEC���У�
//�ö���Ϊ5����ΪD�����ұ���4����ĸ��E�������ұߵ�1����ĸ���ö�����Ϊ�����е���������
//���С�AACEDGG��ֻ��һ������ԣ�E��D������������������ˣ������С�ZWQM����6������ԣ�
//����δ����ģ�ǡ���Ƿ���
//����Ҫ�����ɸ�DNA���У�������4����ĸA��C��G��T���ַ��������࣬ע���Ƿ�������ǰ���ĸ˳������
//���ǰ��ա�������򡱵�����С���򡱵�˳�����У�����DNA���еĳ��ȶ���ͬ��

/*���ַ�����������ans*/
int ans;
void Merge(char a[], int low, int mid, int high)
{
	
	int i = low;
	int j = mid + 1;
	int k = 0;
	char* tmp = (char*)malloc((high - low + 1) * sizeof(char));
	while (i <= mid && j <= high)
	{
		if (a[i] > a[j])
		{
			tmp[k++] = a[j++];
			ans += mid - i + 1;        //�ۼ�����
		}
		else tmp[k++] = a[i++];
	}
	while (i <=mid)
		tmp[k++] = a[i++];
	while (j <=high)
		tmp[k++] = a[j++];
	for (int k1 = 0; k1 <k; k1++)
		a[low+k1] = tmp[k1];
	free(tmp);
}

void Merge_sort(char a[], int low,  int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;  //�Զ����£����η�˼��
		Merge_sort(a, low, mid);
		Merge_sort(a, mid+1, high);
		Merge(a, low, mid, high);
	}
}

int Inversion(char a[], int n)
{
	ans = 0;
	Merge_sort(a, 0, n - 1);   //��·�鲢�㷨���
	return ans;
}


//5���������ʹδ�Ԫ��
void solve(int a[], int low, int high, int& max1, int& max2)
{
	if (low == high)   //����ֻ��һ��Ԫ��
	{
		max1 = a[low];
		max2 = -INF;
	}
	else if (high - low == 1) //����������Ԫ��
	{
		max1 = a[high] > a[low] ? a[high] : a[low];
		max2 = a[high] > a[low] ? a[low] : a[high];
	}
	else
	{
		int mid = (low + high) / 2;
		int lmax1, lmax2;
		solve(a, low, mid, lmax1, lmax2);     //��������ֵ����������
		int rmax1, rmax2;
		solve(a, mid + 1, high, rmax1, rmax2);    //��������ֵ
		if (lmax1 > rmax1)
		{
			max1 = lmax1;
			max2 = lmax2 > rmax1 ? lmax2 : rmax1;
		}
		else
		{
			max1 = rmax1;
			max2 = rmax2 > lmax1 ? rmax2 : lmax1;
		}
	}
}

//6������һ������Ϊn���������У������Ϊ�������У�a[0..n-1]��
//�����м�λ�õ�Ԫ�س�Ϊa����λ����
//���һ���㷨������������������е���λ����
int midium(int a[], int s1, int t1, int b[], int s2, int t2)
{
	int m1, m2;
	if (s1 == t1 && s2 == t2)  //�ݹ����
		return a[s1] > b[s2] ? a[s1] : b[s2];
	else
	{
		m1 = (s1 + t1) / 2;
		m2 = (s2 + t2) / 2;
		if (a[m1] > b[m2])
		{
			prepart( s1, t1);
			postpart(s2, t2);
			return midium(a, s1, t1, b, s2, t2);
		}
	}
}

//�ֳ�ǰ��
void prepart(int& s, int& t)
{
	s = s;
	t = (s + t) / 2;
}

//�ֳ����
void postpart(int& s, int& t)
{
	t = t;
	s = (s + t) / 2;
}