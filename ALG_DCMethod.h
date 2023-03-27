#pragma once
#include "Common.h"
//分治法算法设计

//1、快速排序（见数据结构项目）
//2、二路归并排序（见数据结构项目）
//3、自顶向下的二路归并算法，见下题

//4、求解按“最多排序”到“最小排序”的顺序排列问题。
//一个序列中的“未排序”的度量是相对于彼此顺序不一致的条目对的数量，例如，在字母序列“DAABEC”中，
//该度量为5，因为D大于右边是4个字母，E大于其右边的1个字母。该度量称为该序列的逆序数。
//序列“AACEDGG”只有一个逆序对（E和D），它几乎被排序好了，而序列“ZWQM”有6个逆序对，
//它是未排序的，恰好是反序。
//你需要对若干个DNA序列（仅包含4个字母A、C、G和T的字符串）分类，注意是分类而不是按字母顺序排序，
//而是按照“最多排序”到“最小排序”的顺序排列，所有DNA序列的长度都相同。

/*求字符串的逆序数ans*/
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
			ans += mid - i + 1;        //累计增加
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
		int mid = (low + high) / 2;  //自顶向下，分治法思想
		Merge_sort(a, low, mid);
		Merge_sort(a, mid+1, high);
		Merge(a, low, mid, high);
	}
}

int Inversion(char a[], int n)
{
	ans = 0;
	Merge_sort(a, 0, n - 1);   //二路归并算法入口
	return ans;
}


//5、查找最大和次大元素
void solve(int a[], int low, int high, int& max1, int& max2)
{
	if (low == high)   //区间只有一个元素
	{
		max1 = a[low];
		max2 = -INF;
	}
	else if (high - low == 1) //区间右两个元素
	{
		max1 = a[high] > a[low] ? a[high] : a[low];
		max2 = a[high] > a[low] ? a[low] : a[high];
	}
	else
	{
		int mid = (low + high) / 2;
		int lmax1, lmax2;
		solve(a, low, mid, lmax1, lmax2);     //左区间求值，参数传递
		int rmax1, rmax2;
		solve(a, mid + 1, high, rmax1, rmax2);    //右区间求值
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

//6、对于一个长度为n的有序序列（假设均为升序序列）a[0..n-1]，
//处于中间位置的元素称为a的中位数。
//设计一个算法求给定的两个有序序列的中位数。
int midium(int a[], int s1, int t1, int b[], int s2, int t2)
{
	int m1, m2;
	if (s1 == t1 && s2 == t2)  //递归出口
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

//分出前段
void prepart(int& s, int& t)
{
	s = s;
	t = (s + t) / 2;
}

//分出后段
void postpart(int& s, int& t)
{
	t = t;
	s = (s + t) / 2;
}