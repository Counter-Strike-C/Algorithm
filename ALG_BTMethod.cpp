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


//���n�ʺ�����⣬ʹ�û��ݷ��ǵݹ鷽��
const int num = 5;
int q[num];
void Queens(int n)
{
	int i = 1;         //i��ʾ��ǰ��,���õ�i���ʺ�
	q[i] = 0;         //q[i]��ʾ��ǰ�У�ÿ���¿��ǵĻʺ��ʼλ����Ϊ0��
	while (i > 1)
	{
		q[i]++;
		while(q[i]<=n && !)
	}

}

bool place(int i)   //���Ե�i�е�q[i]�����ܷ�ڷŻʺ�
{
	int j = 1;
	if (i == 1) return true;
	while (j<i)
	{
		if((q[j]==q[i] || abs(q[j]-q[i])==abs(j-i))))
	}
}