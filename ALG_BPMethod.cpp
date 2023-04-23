#include "ALG_BPMethod.h"

int Fib1(int n)
{
	dp[1] = dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

//整数拆分问题
void Split(int n, int k)
{
	for(int i=1;i <= n;i++)
		for (int j = 1; j <= k; k++)
		{
			if (i == 1 && j == 1)
				dp1[i][j] = 1;
			else if (i < j)
				dp1[i][j] = dp1[i][i];
			else if (i == j)
				dp1[i][j] = dp1[i][j - 1];
			else if (i > j)
				dp1[i][j] = dp1[i - j][j] + dp1[i][j - 1];
		}
}

//递归
int  Split1(int n, int k)
{
	if (n == 1 && k == 1)
		return 1;
	else if (n < k)
		return Split1(n, n);
	else if (n == k)
		return Split1(n, n - 1);
	else if (n > k)
		return Split1(n - k, k) + Split1(n, k - 1);
}

//自顶向下的动态规划算法，备忘录方法
int Split2(int n, int k)
{
	if (dp1[n][k] != 0)return dp1[n][k];    //出口
	if (n == 1 && k == 1)
	{
		return dp1[n][k] = 1;

	}
	else if (n < k)
		return dp1[n][k] = Split1(n, n);
	else if (n == k)
		return dp1[n][k] = Split1(n, n - 1);
	else if (n > k)
		return dp1[n][k] = Split1(n - k, k) + Split1(n, k - 1);
}
//这种方法是一种递归算法，其执行过程也是自顶向下的，但当某个子问题解求出后，
//将其结果存放在一张表（dp）中，而且相同的子问题只计算一次，
//在后面需要时只有简单查表，以避免大量的重复计算。
//这种方法称之为备忘录方法（memorization method）。


//2、求解最大连续子序列和问题
void maxSubSum()
{
	dp2[0] = 0;
	for (int j = 1; j <= n; j++)
		dp2[j] = max(dp2[j - 1] + a[j], a[j]);
}

//3、求解最短路径和的问题
int Search()       //求最短路径和ans
{
	int i, j;
	dp3[0][0]=a3[0][0];
	for (int i = 1; i <= n; i++)    //考虑j=0的情况
	{
		dp3[i][0] = dp3[i - 1][0] + a3[i][0];
		pre[i][0] = i - 1;
	}
		

	for (int i = 1; i <= n; i++)       //考虑i=j的情况
	{
		dp3[i][i] = dp3[i - 1][i - 1] + a3[i][i];
		pre[i][i] = i - 1;
	}
		

	for(int i=2;i<n;i++)
		for (int j = 1; j < n; j++)
		{
			if (a3[i - 1][j - 1] > a3[i - 1][j])
			{
				dp3[i][j] = dp3[i - 1][j] + a3[i][j];
				pre[i][j] = j;
			}
			else
			{
				dp3[i][j] = dp3[i - 1][j-1] + a3[i][j];
				pre[i][j] = j-1;
			}
		}
	int ans = dp3[n - 1][0];
	int k = 0;
	for (int i = i; i <= n; i++)
		if (dp3[n - 1][0] < ans)
			k = i;
	return k;      //k就是最短路径终点，pre存储最短路径

}

void disppath(int k)  //输出最小和路径
{
	int i = n - 1;
	vector<int> path;
	while (i>=0)
	{
		path.push_back(a3[i][k]);
		k = pre[i][k];     //读取前驱节点
		i--;
	}
	vector<int>::reverse_iterator it;
	for (it = path.rbegin(); it != path.rend(); ++it)
		cout << *it;    //反向输出构成正向路径
	cout << endl;
}

//求解最长公共子序列问题
int m;
string a, b;				//求解结果表示
int dp4[MAX][MAX];			//动态规划数组
vector<char> subs;       //存放lcs

void LCSLength()        //求dp
{
	int i, j;
	for (i = 0; i <= m; i++)         //边界条件
		dp4[i][0] = 0;
	for (j = 0; j <= n; j++)       //边界条件
		dp4[0][j] = 0;
	for(int i=1;i<=m;i++)
		for (int  j = 1; i <=n; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp4[i][j] = dp4[i - 1][j - 1] + 1;
			else
				dp4[i][j] = max(dp4[i - 1][j], dp4[i][j - 1]);
		}
}

void Buildsubs()
{
	int k = dp4[m][n];      //k为最长公共子序列长度
	int i = m;
	int j = n;

	while (k>0)          //在subs中放入最长公共子序列
	{
		if (dp4[i][j] == dp4[i - 1][j])
			i--;
		else if (dp4[i][j] == dp4[i][j - 1])
			j--;
		else
		{
			subs.push_back(a[i - 1]);  //将子序列入栈
			i--; j--; j--;
		}
	}
}