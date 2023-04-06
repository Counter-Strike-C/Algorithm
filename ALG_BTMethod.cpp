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

//���������������