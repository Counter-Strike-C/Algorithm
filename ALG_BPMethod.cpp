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

//������������������
int a5[]= { 2,1,5,3,6,4,8,9,7 };
int n5 = sizeof(a5) / sizeof(a5[0]);
//�������ʾ
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


//���༭��������
/*��A��B�������ַ���������Ҫ�����ٵ��ַ��������������ַ���Aת��Ϊ�ַ���B��������˵���ַ���������3�֣�
    ��1��ɾ��һ���ַ���
    ��2������һ���ַ���
    ��3����һ���ַ��滻��һ���ַ���
*/
//�����ʾ
string a6 = "sfdqxbw";
string b6 = "gfdgw";
//�������ʾ
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
			if (a6[i - 1] == b6[i - 1])
				dp6[i][j] = dp6[i - 1][j - 1] + 1;
			else
				dp6[i][j] = min(min(dp6[i - 1][j - 1], dp6[i][j - 1]), dp6[i - 1][j])+1	;
		}
}


//�����ʾ
int n7 = 5, W7 = 10;
int w7[MAXN] = { 0,2,2,6,5,4 };	//�±�0����
int v7[MAXN] = { 0,6,3,5,4,6 };	//�±�0����

//�������ʾ
int dp7[MAXN][MAXN];        //��̬�滮����,����ܼ�ֵ
int x[MAXN];        //������Ž�
int maxv;           //������Ž���ܼ�ֵ

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
			if (r < w7[i])       //װ���´���Ʒʱ
				dp7[i][r] = dp7[i - 1][r]; //��װ�����Ʒ
			else
				dp7[i][r] = max(dp7[i - 1][r], dp7[i - 1][r - w7[i]] + v7[i]);  //�жϲ�װ���װ������������ܼ�ֵ
	}
}

//���������Ž�
void buildx()
{
	int i = n7, r = W7;
	maxv = 0;
	while (i	>=0)
	{
		if (dp7[i][r] != dp7[i - 1][r])    //����Ʒi�Ѿ�ѡȡ
		{
			x[i] = 1;         //ѡȡ��Ʒi
			maxv += v7[i];         //�ۼ���Ʒ�ܼ�ֵ
			r = r - w7[i];
		}
		else
		{
			x[i] = 0;
		}
	}
}

//�����ʾ
int n8, W8;
int w8[MAXN], v8[MAXN];
//�������ʾ
int dp8[MAXN + 1][MAXW + 1], fk8[MAXN + 1][MAXW + 1];
//dp[i][j]��ʾ��ǰi����Ʒ��ѡ������������j����Ʒ������ܼ�ֵ��
//����fk[i][j]���dp[i][j]�õ����ֵʱ��Ʒi��ѡ�ļ�����
int solve8()        //�����ر�������
{
	int i, j, k;
	for (i = 1; i <= n8; i++)     //��Ʒ��
		for(j=0;j<=W8;j++)    
			for (k = 0; k * w7[i] <= j; k++)     //����������j
				if (dp8[i][j] < dp8[i - 1][j - k * w8[i]] + k * v7[i])
				{
					dp8[i][j] = dp8[i - 1][j - k * w8[i]] + k * v7[i];
					fk8[i][j] = k;     //��Ʒiѡȡk��
				}
	return dp8[n8][W8];
}

//���������Ž�
void TraceBack()
{
	int i = n8, j = W8;
	while (i>=1)
	{
		printf("��Ʒ%d��%d�� ", i, fk8[i][j]);
		j -= fk8[i][j] * w8[i];	//ʣ������
		i--;

	}
}

int solve1()			//��̬�滮������ȫ���������Ż�
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
	return dp8[n][W8];		//�����ܼ�ֵ
}

//�����Դ��������
//�����ʾ
int m9 = 3, n9 = 5;				//�̵���Ϊm,������Ϊn
int v9[MAXM][MAXN] = { {0,0,0,0,0,0},{0,3,7,9,12,13},
	{0,5,10,11,11,11},{0,4,6,11,12,12} }; //����v[0]��
//�������ʾ
int dp9[MAXM][MAXN];
int pnum9[MAXM][MAXN];

//������ŷ���
void Plan()
{
	int maxf,maxj;
	for (int j = 0; j <= n; j++)
		dp9[m9 + 1][j] = 0;     //�߽�����
	for(int i=m9;i>=1;i--)
		for (int s = 1; s <= n9; s++)
		{
			maxf = 0;
			maxj = 0;
			for (int j = 0; j < s; j++)
			{
				if ((v9[i][j] + dp9[i + 1][s - j]) >= maxf)  //����ѭ������������
				{
					maxf = v9[i][j] + dp9[i + 1][s - j];
					maxj = j;
				}
			}
			dp9[i][s] = maxf;
			pnum9[i][s] = maxj;
		}
}

#pragma region �����鰲������
struct NodeType_10
{
	int b;			//��ʼʱ��
	int e;			//����ʱ��
	int length;			//������ִ��ʱ��
	bool operator < (const NodeType_10 t) const
	{				//�����������������غ���
		return e < t.e;		//������ʱ���������
	}

};
int n10 = 11;			//��������
NodeType_10 A10[MAX] = { {1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},
   {8,12},{2,13},{12,15} };	//��Ŷ���
//�������ʾ
int dp10[MAX];			//��̬�滮����
int pre10[MAX];			//pre[i]���ǰ���������

void solve10()
{
	memset(dp10, 0, sizeof(dp10));   //dp�����ʼ��
	stable_sort(A10, A10 + n);         //�ȶ������㷨
	dp10[0] = A10[0].length;
	pre10[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int low = 0;
		int high = i - 1;
		while (low<high)   //��A[0..i-1]���۰���ҽ���ʱ������
				//A[i].b��������A[low-1]
		{
			int mid = (low + high) / 2;
			if (A10[mid].e <= A10[i].b)
				low = mid + 1;
			else
				high = mid - 1;
		}

		if (low == 0)
		{
			if (dp10[i] >= A10[i].length)
			{
				dp10[i] = dp10[i - 1];
				pre10[i] = -2;
			}
		}
		else
		{
			if (dp10[i - 1] >= dp10[low - 1] + A10[i].length)
			{
				dp10[i] = dp10[i - 1];
				pre10[i] = -2;			//��ѡ�񶩵�i
			}
			else
			{
				dp10[i] = dp10[low - 1] + A10[i].length;
				pre10[i] = low - 1;		//ѡ�ж���i

		}
	}
}
#pragma endregion