#include "ALG_BTMethod.h"
#define MAXN 20
int w[] = { 0,10,40,40 };      //����װ�������
int n = 3;
int c1 = 50, c2 = 50;
int maxw = 0;			//��ŵ�һ���ִ����Ž��������
int x[MAXN];			//��ŵ�һ���ִ����Ž�����

/// <summary>
/// 
/// </summary>
/// <param name="i">��i����װ��</param>
/// <param name="tw">��ǰ��װ������</param>
/// <param name="rw">ʣ�༯װ������</param>
/// <param name="op">��ʱ�洢������</param>
void clDfs(int i, int tw, int rw, int op[])
{
	if (i > n)
	{
		if (tw > maxw)    //�ж��Ƿ��Ǹ��Ž�
		{
			maxw = tw;
			for (int i = 0; i < n; i++)
				x[i] = op[i];          //���Ƹ��Ž�
		}
	}
	else
	{
		if (tw + w[i] <= c1)
		{
			op[i] = 1;
			clDfs(i+1, tw + w[i], rw - w[i], op);
		}
		if (tw + rw - w[i] > maxw)    //����ʣ�����������װ������
		{
			op[i] = 0;
			clDfs(i+1, tw, rw - w[i], op);
		}

	}
}

bool solve()    //��⸴��װ������
{
	int sum = 0;  //�ۼƵ�һ���ִ�װ���ʣ��ļ�װ������
	for (int i = 0; i <= n; i++)
		if (x[i] == 0)
			sum += w[i];
	if (sum <= c2)
		return true;
	else
		return false;
}


//����Ӽ�������
//����n����ͬ������������w=��w1��w2������wn����һ��������W��Ҫ���ҳ�w���Ӽ�s��ʹ���Ӽ�������Ԫ�صĺ�ΪW��
//���磬��n = 4ʱ��w = ��11��13��24��7����W = 31��������Ҫ����Ӽ�Ϊ��11��13��7���ͣ�24��7����

int W1 = 31;
void dfs1(int i, int tw, int rw, int x[])
{
	if (i > n)
	{
		if (tw == W1)
		{
			for (int i = 0; i < n; i++)       //������
				cout << x[i];
		}
	}
	else
	{
		if (tw + w[i] <= W1)
		{
			x[i] = 1;
			dfs1(i + 1, tw + w[i], rw - w[i], x);
		}
		if (tw + rw - w[i] >= maxv)
		{
			x[i] = 0;
			dfs1(i + 1, tw, rw - w[i], x);
		}
	}
}


const int num = 5;
int q[num];

bool place(int i)   //���Ե�i�е�q[i]�����ܷ�ڷŻʺ�
{
	int j = 1;
	if (i == 1) return true;
	while (j < i)    //j = 1~i���Ѿ������˻ʺ����
	{
		if ((q[j] == q[i] || abs(q[j] - q[i]) == abs(j - i)))
			//�ûʺ��Ƿ�����ǰ�ʺ�ͬ�У�λ�ã�j��q[j])��(i��q[i])�Ƿ�ͬ�Խ���
			return false;
	}
	return true;
}

void disp1(int n)
{
	for (int i = 0; i < n; i++)
		cout << q[i] << endl;
}

//���n�ʺ�����⣬ʹ�û��ݷ��ǵݹ鷽��

void Queens(int n)
{
	int i = 1;         //i��ʾ��ǰ��,���õ�i���ʺ�
	q[i] = 0;         //q[i]��ʾ��ǰ�У�ÿ���¿��ǵĻʺ��ʼλ����Ϊ0��
	while (i >= 1)      //��δ���ݵ�ͷ��ѭ��
	{
		q[i]++;         //ԭλ������ƶ�һ��
		while (q[i] <= n && !place(i))  //��̽һ��λ��,������ܷ�����
			q[i]++;  //����ƶ�һ��

		if (q[i] < n)//Ϊ��i���ʺ��ҵ���һ������λ��(i,q[i])
		{
			if (i == n)  //�����������лʺ�,���һ����
				disp1(n);
			else        //�ʺ�û�з�����
			{
				i++;        //��ʼ��һ�еķ���
				q[i] = 0;       //ÿһ���µĻʺ��ʼλ��Ϊ0��
			}
		}
		else i--;        //����i���ʺ��Ҳ������ʵ�λ�ã�����ݵ���һ���ʺ�
	}
}


//���ͼ��m��ɫ����
const int n2 = 5;
int a[5][5];
int count1 = 0;       //�������
int m = 4;   //��ɫ������
int k = 8;     //�ߵ�����
bool Same(int i)        //�ж϶���i�Ƿ������ڶ��������ͬ����ɫ
{
	for (int j = 1; j <= n; j++)
		if (a[i][j] == 1 && x[i] == x[j])
			return false;
	return true;

}

void mDfs(int i)        //���ͼ��m��ɫ����
{
	if (i > n)
		count1++;
	else
	{
		for (int j= 1; j < m; i++)    //m��������̽ÿһ����ɫ
		{
			x[i] = j;      //��̽��ɫj
			if(Same(i))   //������ɫj
				mDfs(i + 1);   //��һ��������ɫ
			x[i] = 0;       //����ɫj��������ɫ��һ����ɫ�����ݵ��ֵܽڵ�)
		}
	}
}

//���������������,(0,0)����
int x3[MAXN];     //��ʱ��
int n4 = 4;
int  c2[MAXN][MAXN] = { {0},{0,9,2,7,8},{0,6,4,3,7},
				   {0,5,8,1,8},{0,7,6,9,4} };   //����ɱ�����
int cost = 0;     //��ʱ��ĳɱ�
int bestx[MAXN];       //���Ž�
int mincost = INF;      //���Ž�ɱ�
bool worker[MAXN];          //worker[j]��ʾ����j�Ƿ��Ѿ�������Ա

void dfs3(int i)        //Ϊ��i���˷�������
{
	const int m = i;
	if (i > n4)      //����Ҷ�ӽڵ��
	{
		if (cost < mincost)          //�Ƚ������Ž�
		{
			mincost =cost;
			for (int j = 1; j <= n4; j++)
				bestx[j] = x3[j];
		}
	}
	else
	{
		for (int j = 1; j < n4; j++)
		{
			worker[j] = true;
			x3[j] = 1;
			cost += c2[&m][&j];  //����i��������j�Ļ���
			dfs3(i + 1);
			worker[j] = false;    //����
			x3[j] = 0;
			cost -= c2[&m][&j];

		}
	}
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//5�������������
struct Action
{
	int b;				//���ʼʱ��
	int e;				//�����ʱ��
};
int n5 = 4;
Action A5[] = { {0,0},{1,3},{2,5},{4,8},{6,10} }; //�±�0����

int x5[MAX];     //��ʱ������
int bestx[MAX];       //���Ž�������������Ǹ�����ı��
int laste = 0;        //һ�����ȷ����������ݻ�Ľ���ʱ��,��ֵΪ0
int sum = 0;		//һ�����ȷ��������м��ݻ����,��ֵΪ0
int maxsum = 0;    //���ĵ��ȷ��������м��ݻ�ĸ�������ֵΪ0
void dfs5(int i)
{
	if (i > n5)
	{
		if (sum > maxsum)
		{
			maxsum = sum;
			for (int k = 1; k < n; k++)
				bestx[k] = x5[k];   //������������
		}
	}
	else
	{
		for (int j = 1; j < n; j++)
		{
			swap(a[i], a[j]);   //����������ѡ���ظ�
			int sum1 = sum;
			int laste1 = laste;
			if (A5[x5[j]].b >= laste)     //�����������
			{
				sum++;  //�������1
				laste = A5[x5[j]].e;
			}
			swap(a[i], a[j]);   //����
			int sum = sum1;
			int laste = laste1;
		}
	}
}

//6�������ˮ��ҵ��������
