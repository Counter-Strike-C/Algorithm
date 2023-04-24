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

//求解最长递增子序列问题
int a5[]= { 2,1,5,3,6,4,8,9,7 };
int n5 = sizeof(a5) / sizeof(a5[0]);
//求解结果表示
int ans5 = 0;
int dp5[MAX];

void solve(int a[], int n)
{
	int i, j;
	for (int i = 0; i < n; i++)
	{
		dp5[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
				dp5[i] = max(dp5[i], dp5[j] + 1);
		}
	}
	ans5 = dp5[0];
	for (int i = 0; i < n5; i++)
		ans5 = max(ans5, dp5[i]);
}


//求解编辑距离问题
/*设A和B是两个字符串。现在要用最少的字符操作次数，将字符串A转换为字符串B。这里所说的字符操作共有3种：
    （1）删除一个字符。
    （2）插入一个字符。
    （3）将一个字符替换另一个字符。
*/
//问题表示
string a6 = "sfdqxbw";
string b6 = "gfdgw";
//求解结果表示
int dp6[MAX][MAX];

void solve6()
{
	int i, j;
	for (i = 1; i <= a6.length(); i++)
		dp6[i][0] = i;
	for (j = 1; j <= a6.length(); j++)
		dp6[0][j];	

	for(i=1;i<= a6.length();i++)
		for (j = 1; j <= a6.length(); j++)
		{
			if (a[i - 1] == b[i - 1])
				dp6[i][j] = dp6[i - 1][j - 1] + 1;
			else
				dp6[i][j] = min(min(dp6[i - 1][j - 1], dp6[i][j - 1]), dp6[i - 1][j])+1	;
		}
}


//问题表示
int n7 = 5, W7 = 10;
int w7[MAXN] = { 0,2,2,6,5,4 };	//下标0不用
int v7[MAXN] = { 0,6,3,5,4,6 };	//下标0不用

//求解结果表示
int dp7[MAXN][MAXN];        //动态规划数组,存放总价值
int x[MAXN];        //存放最优解
int maxv;           //存放最优解的总价值

void knap7()
{
	int i, r;
	for (i = 0; i <= n7; i++)
		dp7[i][0] = 0;
	for (r = 0; r <= W7; r++)
		dp7[0][r] = 0;

	for (i = 1; i <= n7; i++)
	{
		for (r = 1; r <= W7; r++)
			if (r < w7[i])       //装不下此物品时
				dp7[i][r] = dp7[i - 1][r]; //不装入此物品
			else
				dp7[i][r] = max(dp7[i - 1][r], dp7[i - 1][r - w7[i]] + v7[i]);  //判断不装入和装入两种情况的总价值
	}
}

//回推求最优解
void buildx()
{
	int i = n7, r = W7;
	maxv = 0;
	while (i	>=0)
	{
		if (dp7[i][r] != dp7[i - 1][r])    //若物品i已经选取
		{
			x[i] = 1;         //选取物品i
			maxv += v7[i];         //累计物品总价值
			r = r - w7[i];
		}
		else
		{
			x[i] = 0;
		}
	}
}

//问题表示
int n8, W8;
int w8[MAXN], v8[MAXN];
//求解结果表示
int dp8[MAXN + 1][MAXW + 1], fk8[MAXN + 1][MAXW + 1];
//dp[i][j]表示从前i个物品中选出重量不超过j的物品的最大总价值。
//其中fk[i][j]存放dp[i][j]得到最大值时物品i挑选的件数。
int solve8()        //求解多重背包问题
{
	int i, j, k;
	for (i = 1; i <= n8; i++)     //物品号
		for(j=0;j<=W8;j++)    
			for (k = 0; k * w7[i] <= j; k++)     //重量不超过j
				if (dp8[i][j] < dp8[i - 1][j - k * w8[i]] + k * v7[i])
				{
					dp8[i][j] = dp8[i - 1][j - k * w8[i]] + k * v7[i];
					fk8[i][j] = k;     //物品i选取k件
				}
	return dp8[n8][W8];
}

//回推求最优解
void TraceBack()
{
	int i = n8, j = W8;
	while (i>=1)
	{
		printf("物品%d共%d件 ", i, fk8[i][j]);
		j -= fk8[i][j] * w8[i];	//剩余重量
		i--;

	}
}

int solve1()			//动态规划法求完全背包问题优化
{
	int i, k, j;
	for (i = 1; i <= n; i++)
		for (j = 0; j <= W8; j++)
		{
			if (j < w8[i])
				dp8[i][j] = dp8[i - 1][j];
			else
				dp8[i][j] = max(dp8[i - 1][j], dp8[i][j - w8[i]] + v8[i]);
		}
	return dp8[n][W8];		//返回总价值
}
