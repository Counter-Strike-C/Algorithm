#include "ALG_BaBMethod.h"
int n = 6;
void ALG_BaBMethod::bfs_2()
{
	NodeType_M_1 e, e1;     //���ڵ���ӽڵ�
	queue<NodeType_M_1> pqu; 
	e.vno = v;
	e.length = 0;
	pqu.push(e);   //Դ�ڵ����
}
struct NodeType_1		//���н������
{
	int no;			//�����
	int i;			//��Ա���
	int x[MAXN];		//x[i]Ϊ��Աi�����������
	bool worker[MAXN];		//worker[i]=true��ʾ����i�Ѿ�����
	int cost;			//�Ѿ�������������Ҫ�ĳɱ�
	int lb;			//�½�
	bool operator<(const NodeType_1& s) const	//����<��ϵ����
	{
		return lb > s.lb;
	}
};

int c[MAXN][MAXN] = { {0},{0,9,2,7,8},{0,6,4,3,7},
	{0,5,8,1,8},{0,7,6,9,4} };
//�±�0��Ԫ�ز���
int bestx[MAXN];		//���ŷ��䷽��
int mincost = INF;		//��С�ɱ�
int total = 1;			//�������ۼ�

//��֦�޽編��������������
void debug_1()
{
	n = 4;

}

//���½�ĺ���
void bound(NodeType_1& e)
{
	
	int minsum = 0;
	for (int i1 = e.i + 1; i1 <= n; i1++)   //����δ�������Ա
	{
		int minc = INF;
		for (int j1 = 1; j1 <= n; j1++)      //����ĳ�˵ĳɱ�
		{
			if (e.worker[j1] == false && c[i1][j1] <= minc)  //�������û�з���,�ҵ���С�ĳɱ�
			{
				minc = c[i1][j1];
			}
			minsum += minc;
		}
	}
	e.lb = e.cost + minsum;
}

void bfs_3()          //����������
{
	int j;
	NodeType_1 e, e1;
	priority_queue<NodeType_1> qu;
	memset(e.x, 0, sizeof(e.x));
	memset(e.worker, 0, sizeof(e.worker));  //��ʼ�����ڵ��worker

	e.i = 0;    //���ڵ�ָ����ԱΪ0
	e.no = total++;
	e.cost = 0;    
	bound(e);
	qu.push(e);       //���ڵ����

	while (!qu.empty())  //
	{
		e = qu.top();
		qu.pop();      //���ӽڵ�e���ǵ�ǰ��Աi
		if (e.i == n)    //���ﵽҶ�ӽڵ�
		{
			if (e.cost < mincost)   //�Ƚ������Ž�
			{
				mincost = e.cost;
				for (int i = 0; i <= n; i++) //�ҵ����Ž⣬���ƽ�����
					bestx[i] = e.x[i];
			}
		}
		e1.i = e.i + 1;  //������һ����Ա
		for (int j = 1; j <= n; j++)
		{
			if (e.worker[j] == 1)
				continue;
			for (int i = 1; i <= n; i++)
				e1.x[i] = e.x[i];   //���ƽ�����
			e1.x[e1.i] = j;      //��������j
			for (int i2 = 1; i2 <= n; i2++)
				e1.worker[i2] = e.worker[i2];
			e1.worker[j] = true;     //����j�Ѿ�����
			e1.cost = e.cost + c[e1.i][j];
			bound(e1);      //��e1�ı߽�
			e1.no = total++;
			if (e1.lb < mincost)      //��֦
				qu.push(e1);
		}

	}
}

int a[MAX] = { 0,5,12,4,8 };	//M1�ϵ�ִ��ʱ��,�����±�0��Ԫ��
int b[MAX] = { 0,6,2,14,7 };	//M2�ϵ�ִ��ʱ��,�����±�0��Ԫ��

//�������ʾ
int bestf = INF;			//������ŵ���ʱ��
//int bestx[MAX];		//��ŵ�ǰ��ҵ��ѵ���
//int total = 1;			//�������ۼ�


int n = 4;			//��ҵ��
int a[MAX] = { 0,5,12,4,8 };	//M1�ϵ�ִ��ʱ��,�����±�0��Ԫ��
int b[MAX] = { 0,6,2,14,7 };	//M2�ϵ�ִ��ʱ��,�����±�0��Ԫ��  ��i=0ʱ��b[0]�����ж�f2
//�������ʾ
//int bestf = INF;			//������ŵ���ʱ��
int bestx[MAX];		//��ŵ�ǰ��ҵ��ѵ���
int total = 1;			//�������ۼ�

//�����ˮ����ҵ��������
void debug_2()
{
	n = 4;
	free(bestx);
	total = 1;
	bestf = INF;
}

struct NodeType_2		//���н������
{
	int no;			//�����
	int x[MAX];			//x[i]��ʾ��i��������ҵ���
	int y[MAX];			//y[i]=1��ʾ���Ϊi����ҵ�Ѿ�����  //
	int i;			//������
	int f1;			//�Ѿ�������ҵM1��ִ��ʱ��
	int f2;			//�Ѿ�������ҵM2��ִ��ʱ��
	int lb;			//�½�
	bool operator<(const NodeType_2& s) const	//����<��ϵ����
	{
		return lb > s.lb;	//lbԽСԽ���ȳ���
	}
};

//�߽纯��
void bound_2(NodeType_2 &e)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (e.y[i] == 0) sum += b[i];      //���û�з��䣬����ʣ��bʱ���ܺ�
	e.lb = sum;     //����߽�
}

//���
void bfs_2()
{
	NodeType_2 e, e1;
	priority_queue<NodeType_2> qu;
	e.i = 0;
	e.no = total++;
	e.f1 = 0;
	e.f2 = 0;
	bound_2(e);
	qu.push(e);   //���ڵ�
	while (!qu.empty())
	{
		e = qu.top();
		qu.pop();
		//if (e.i == n)    //��Ҷ�ӽڵ���
		//{
		//	if (e.f2 < bestf)
		//	{
		//		bestf = e.f2;
		//		for (int i = 0; i <= n; i++)
		//			bestx[i] = e.x[i];
		//	}
		//}
		e1.i = e.i + 1;
		for (int j = 1; j <= n; j++)
		{
			if (e.y[j] == 1)continue;
			for (int i1 = 1; i1 <= n; i1++)
				e1.x[i1] = e.x[i1];
			for (int i2 = 1; i2 <= n; i2++)
				e1.y[i2] = e.y[i2];
			e1.x[e1.i] = j;     //Ϊ��i��������ҵj
			e1.y[j] = 1;    //j�ѷ���
			e1.f1 = e.f1 + a[j];      //��f1      f1=f1+a[j]
			e1.f2 = max(e1.f1, e.f2) + b[j];   //��f2        f[i+1]=max(f2[i],f1)+b[j]
			
			bound_2(e1);
			if (e1.i == n)  //�������Ҷ�ӽڵ�
			{
				if (e1.f2 < bestf)   //�Ƚ������Ž�
				{
					bestf = e1.f2;
					for (int i = 0; i <= n; i++)
							bestx[i] = e.x[i];
				}
			}
			else if (e1.lb < bestf)      //��ȥ����õ����Ž�Ľ�
			{
				e1.no = total++;    //�ڵ���+1
				qu.push(e1);
			}
		} 
	}
}