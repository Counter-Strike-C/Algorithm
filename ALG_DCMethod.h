#pragma once
#define MAX 1025
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

long max3(long a, long b, long c)
{
	long max = a > b ? a : b;
	return max > c ? max : c;
}

//求a[left..high]序列中最大连续子序列和
long maxSubSum(int a[], int left, int right)
{
	int i, j;
	long maxLeftSum, maxRightSum;
	long maxLeftBorderSum, leftBorderSum;
	long maxRightBorderSum, rightBorderSum;

	if (left == right)     // 如果子序列只有一个元素
	{
		if (a[left] > 0)
			return a[left];
		else
			return 0;
	}
	int mid = (left + right) / 2;
	maxLeftSum = maxSubSum(a, left, mid);
	maxRightSum = maxSubSum(a, mid + 1, right);
	maxLeftBorderSum = 0; leftBorderSum = 0;
	for (i = mid; i >= left; i--)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}
	maxRightBorderSum = 0; rightBorderSum = 0;
	for (j = mid+1; j<=right; j++)
	{
		rightBorderSum += a[i];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

//求解棋盘覆盖的问题
//问题表示
int k;        //棋盘大小       
int x, y;   //特殊方格的位置
	
//求解问题表示
int board[MAX][MAX];
int tile = 1;

//棋盘覆盖问题
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)return;           //递归出口
	int t = tile++;       //取一个L型骨，其牌号为tile
	int s = size / 2;      //分割棋盘

	//考虑左上角象限
	if (dr < tr + s && dc < tc + s)       //特殊方格在此象限中
		ChessBoard(tr, tc, dr, dc, s);
	else
	{
		board[tr + s - 1][tc + s - 1] = t; //用t号L型骨牌覆盖右下角
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
		//将右下角作为特殊方格继续处理象限
	}

	//考虑右上角象限
	if (dr < tr + s && dc >= tc + s)
		ChessBoard(tr, tc + s, dr, dc, s);		//特殊方格在此象限中 
	else					//此象限中无特殊方格
	{
		board[tr + s - 1][tc + s] = t;		//用t号L型骨牌覆盖左下角
		ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
		//将左下角作为特殊方格继续处理该象限
	}

	//处理左下角象限
	if (dr >= tr + s && dc < tc + s)		//特殊方格在此象限中
		ChessBoard(tr + s, tc, dr, dc, s);
	else				//此象限中无特殊方格
	{
		board[tr + s][tc + s - 1] = t;  	//用t号L型骨牌覆盖右上角
		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
		//将右上角作为特殊方格继续处理该象限
	}

	//处理右下角象限
	if (dr >= tr + s && dc >= tc + s)		//特殊方格在此象限中
		ChessBoard(tr + s, tc + s, dr, dc, s);
	else				//此象限中无特殊方格
	{
		board[tr + s][tc + s] = t;  	//用t号L型骨牌覆盖左上角
		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
		//将左上角作为特殊方格继续处理该象限
	}
}

//求解循环日程安排问题
/* 设有n=2k个选手要进行网球循环赛，要求设计一个满足以下要求的比赛日程表：
     （1）每个选手必须与其他n-1个选手各赛一次。
     （2）每个选手一天只能赛一次。
     （3）循环赛在n-1天之内结束。
 */
#define MAX 101
int k;         //求解结果表示
int a[MAX][MAX];     //存放比赛日程表
void Plan(int k)
{
	int i, j, n, t, temp;
	n = 2;			//n从2^1=2开始
	a[1][1] = 1; a[1][2] = 2;   	//求解2个选手比赛日程,得到左上角元素
	a[2][1] = 2; a[2][2] = 1;
	for (t = 1; t < k; t++)		//迭代处理2^2(t=1)…,2^k(t=k-1)个选手
	{
		temp = n;					//temp=2^t 上一个方块长度
		n = n * 2; 					//n=2^(t+1)   下一个方块
		for (i = temp + 1; i <= n; i++)		//填左下角元素
			for (j = 1; j <= temp; j++)
				a[i][j] = a[i - temp][j] + temp; 	//产生左下角元素
		for (i = 1; i <= temp; i++)		//填右上角元素
			for (j = temp + 1; j <= n; j++)
				a[i][j] = a[i + temp][(j + temp) % n];
		for (i = temp + 1; i <= n; i++)		//填右下角元素
			for (j = temp + 1; j <= n; j++)
				a[i][j] = a[i - temp][j - temp];
	}

}