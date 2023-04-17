#pragma once
#include "Common.h"
//̰���㷨���

//�����������
//�����ʾ
struct Action     //�����������
{
	int b;   //���ʼ�ͽ���ʱ��
	int e;
	bool operator< (const Action& s) const
	{
		return e < s.e;
	}
};

int n = 11;
Action A[] = { {0},{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},
	 {8,12},{2,13},{12,15} };	//�±�0����
//�������ʾ
bool flag[MAXN];		//���ѡ��Ļ
int Count = 0;			//ѡȡ�ļ��ݻ����

void solve()
{
	memset(flag, 0, sizeof(flag));     //��ʼ��Ϊfalse
	sort(A + 1, A + n + 1);    //��A�����ʱ����е�������
	int preend = 0;    //ǰһ�����ݻ�Ľ���ʱ��
	for (int i = 1; i <= n; i++)
	{
		if (A[i].b > preend)
		{
			flag[i] = true;
			preend = A[i].e;  //���»����ʱ��
		}
	}
}

struct Cow
{
	int no;       //ţ���
	int b;
	int e;
	bool operator< (const Cow& s) const
	{
		if (e == s.e)
			return b < s.b;
		else
			return e < s.e;
	}
};

int n1 = 5;
Cow A[] = { {0},{1,1,10},	{2,2,4},{3,3,6},{4,5,8},{5,4,7} };
//�±�0����
//�������ʾ
int ans[MAXN];			//ans[i]��ʾ��A[i].noͷţ���������

void solve_1()
{
	sort(A + 1, A + n + 1);     //��ָ����ʽ����
	memset(ans, 0, sizeof(ans));     //��ų�ʼ��
	int num = 1;
	for (int i = 1; i <= n1; i++)
	{
		if (ans[i] == 0)   //�����iͷţ��û�а�������
		{
			ans[i] = num;
			int preend = A[i].e;
			for (int j = i+1; j <= n; j++)
			{
				if (A[j].b > preend && ans[j] == 0)   //���û�а�����������������
				{
					ans[j] = num;  //��������
					preend = A[j].e;   //���¼��ݻʱ��
				}

			}
		}
		num++; //��һ������
	}


}


//��ⱳ������
int n2 = 50;
double W = 100;    //����
struct NodeType
{
	double w;
	double v;
	double p;
	bool operator<(const NodeType& s) const
	{
		return p > s.p;			//��p�ݼ�����
	}



};
NodeType A2[] = { {0},{10,20},{20,30},{30,66},{40,40},{50,60} };
//�������ʾ
double V;				//���ֵ
double x_2[MAXN];

void Knap_2()
{
	for (int i = 1; i <= n; i++)		//��v/w
		A2[i].p = A2[i].v / A2[i].w;
	sort(A + 1, A + n + 1);

	V = 0;
	double weight = W;       //����ʣ����װ�������
	memset(x_2, 0, sizeof(x_2));
	int i = 1;

	while (A2[i++].w < weight)        //��Ʒi�ܹ�ȫ��װ��ʱѭ��
	{
		x_2[i] = 1;  //װ��
		weight -= A2[i].w;
		V += A2[i].v;
	}

	if (weight > 0)
	{
		x_2[i] = weight / A2[i].w;       //����Ʒi��һ���ַ���
		V += A2[i].v * x_2[i];      //�ۼ��ܼ�ֵ
	}
}


//�������װ������
int w_3[] = { 0,5,2,6,4,3 };
//�������ʾ
int maxw;        //������Ž�
int x_3[MAXN];        //������Ž�����

void solve_3()
{
	n = 5;
	W = 10;

	memset(x_3, 0, sizeof(x_3));
	sort(w_3 + 1, w_3 + n + 1);
	maxw = 0;
	int restw = W;
	for (int i = 1; i <= n && w_3[i]<=restw; i++)
	{
		x_3[i] = 1;
		restw -= w_3[i];
		maxw += w_3[i];
	}
}

//4���������������
int m_4 = 3;
struct NodeType_4				//���ȶ��н������
{
	int no;					//��ҵ���
	int t;					//ִ��ʱ��
	int mno;					//�������
	bool operator<(const NodeType_4& s) const      //��tԽСԽ���ȳ���
	{
		return t > s.t;
	}			
};
struct NodeType_4 A4[] = { {1,2},{2,14},{3,4},{4,16},{5,6},{6,5},{7,3} };

//�������������
void solve_4()
{
	n = 7;
	NodeType_4 e;
	if (n < m_4)
	{
		cout << "Ϊÿһ����ҵ����һ̨������" << endl;
		return;
	}
	sort(A4 , A4 + n );
	priority_queue<NodeType_4>qu;       //����С����
	for (int i = 0; i < m_4; i++)     //�Ȱ�ʱ���ɴ�С����
	{
		A4[i].mno = i;
		qu.push(A4[i]);    //����С����
	}

	for (int j = m_4; j < n; j++)   //�������µ���ҵ
	{
		e = qu.top();
		qu.pop();
		e.t += A4[j].t;
		qu.push(e);     //t����
	}
}


//����������������
struct HTreeNode			//���������������
{
	char data;				//�ַ�
	int weight;				//Ȩֵ
	int parent;				//˫�׵�λ��
	int lchild;				//���ӵ�λ��
	int rchild;				//�Һ��ӵ�λ��
};
HTreeNode ht[MAXN];			//��Ź�������
map<char, string> htcode;		//��Ź���������

struct NodeType_5			//���ȶ��н������
{
	int no;				//��Ӧ��������ht�е�λ��
	char data;				//�ַ�
	int  weight;			//Ȩֵ
	bool operator<(const NodeType_5& s) const
	{					//���ڴ���С����
		return s.weight < weight;
	}
};

void CreateHTree()       //�������������
{
	n = sizeof(ht);
	NodeType_5 e, e1, e2;
	priority_queue<NodeType_5> qu;      //����С����
	for (int k = 0; k < 2 * n - 1 ;k++)   //��ʼ�����нڵ��ָ����
		ht[k].lchild = ht[k].rchild = ht[k].parent = -1;

	for (int i = 0; i < n; i++)      //�����нڵ����
	{
		e.no = i;
		e.data = ht[i].data;
		e.weight = ht[i].weight;
		qu.push(e);
	}

	for (int j = n; j < 2 * n - 1; j++)      //�������������n-1����Ҷ�ӽڵ�
	{
		e1 = qu.top(); qu.pop();   //����Ȩֵ��С�Ľڵ�

		e2 = qu.top();     //��С�ڵ����
		qu.pop();

		ht[j].weight = e1.weight + e2.weight;       //�����Ҷ�ӽڵ�
		ht[j].lchild = e1.no;
		ht[j].rchild = e2.no;
		ht[e1.no].parent = j;   //�޸�e1.no��˫��Ϊ�ڵ�j
		ht[e2.no].parent = j;
		e.no = j;    //������нڵ�e
		e.weight = e1.weight + e2.weight;
		qu.push(e);
	}
}