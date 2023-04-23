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

//�����������
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

//�ݹ�
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

//�Զ����µĶ�̬�滮�㷨������¼����
int Split2(int n, int k)
{
	if (dp1[n][k] != 0)return dp1[n][k];    //����
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
//���ַ�����һ�ֵݹ��㷨����ִ�й���Ҳ���Զ����µģ�����ĳ��������������
//�����������һ�ű�dp���У�������ͬ��������ֻ����һ�Σ�
//�ں�����Ҫʱֻ�м򵥲���Ա���������ظ����㡣
//���ַ�����֮Ϊ����¼������memorization method����


//2�����������������к�����
void maxSubSum()
{
	dp2[0] = 0;
	for (int j = 1; j <= n; j++)
		dp2[j] = max(dp2[j - 1] + a[j], a[j]);
}

//3��������·���͵�����
int Search()       //�����·����ans
{
	int i, j;
	dp3[0][0]=a3[0][0];
	for (int i = 1; i <= n; i++)    //����j=0�����
	{
		dp3[i][0] = dp3[i - 1][0] + a3[i][0];
		pre[i][0] = i - 1;
	}
		

	for (int i = 1; i <= n; i++)       //����i=j�����
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
	return k;      //k�������·���յ㣬pre�洢���·��

}

void disppath(int k)  //�����С��·��
{
	int i = n - 1;
	vector<int> path;
	while (i>=0)
	{
		path.push_back(a3[i][k]);
		k = pre[i][k];     //��ȡǰ���ڵ�
		i--;
	}
	vector<int>::reverse_iterator it;
	for (it = path.rbegin(); it != path.rend(); ++it)
		cout << *it;    //���������������·��
	cout << endl;
}

//������������������
int m;
string a, b;				//�������ʾ
int dp4[MAX][MAX];			//��̬�滮����
vector<char> subs;       //���lcs

void LCSLength()        //��dp
{
	int i, j;
	for (i = 0; i <= m; i++)         //�߽�����
		dp4[i][0] = 0;
	for (j = 0; j <= n; j++)       //�߽�����
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
	int k = dp4[m][n];      //kΪ����������г���
	int i = m;
	int j = n;

	while (k>0)          //��subs�з��������������
	{
		if (dp4[i][j] == dp4[i - 1][j])
			i--;
		else if (dp4[i][j] == dp4[i][j - 1])
			j--;
		else
		{
			subs.push_back(a[i - 1]);  //����������ջ
			i--; j--; j--;
		}
	}
}