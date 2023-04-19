#pragma once
#include "Common.h"
#define N 4
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

void CreateHCode()
{
	string code;
	code.reserve(MAXN);

	for (int i = 0; i < n; i++)      //����Ҷ�ӽڵ�i�Ĺ���������
	{
		code = "";
		int curno = i;//����ÿһ���ڵ㲢�������
		int f = ht[curno].parent;
		while (f != -1)
		{
			if (ht[f].lchild == curno)  //curnoΪ˫��f������
				code = '0' + code;
			else
				code = '1' + code;      //curnoΪ˫��f���Һ���
			curno = f;
			f = ht[curno].parent;
		}
		htcode[ht[i].data] = code;    //������Ӧ�ַ��Ĺ���������
	}
}

struct Action_6
{
	int d;			//�������
	int p;			//Ч��
	bool operator< (const Action_6 t) const
	{
		return p > t.p;		//��Ч��ݼ�����
	}
};
Action_6 A6[] = { {0},{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15} };	//�±�0����
Action_6 flag[MAXN];		//�������ʾ

void solve()
{
	memset(flag, 0, sizeof(flag));
	sort(A6, A6 + 1);
	int sum = 0;     //�ۼ�������ҵʱ��
	for (int i = 1; i <= sizeof(A6); i++)
	{
		if (A6[i].d > sum)
		{
			flag[i] = true;
			sum++;
		}
	}
}

/*
��n����ҵ��a1,a2������an��
��ҵaj�Ĵ���ʱ��Ϊtj��������Ч��Ϊpj������������Ϊdj����ҵһ�������������жϣ�
�����ҵaj��djǰ��ɣ�����Ч��pj��������Ч�档�������Ч�����ҵ�����㷨��*/
//����̰���㷨
int t[] = { 0,1,4,1 };		//�±�0����
int d[] = { 0,5,4,5 };
int p[] = { 0,2,8,6 };
struct Action_7
{
	int t;			//����ʱ��
	int d;			//�������
	int p;			//Ч��
	bool operator< (const Action_6 t) const
	{
		return p > t.p;		//��Ч��ݼ�����
	}
};
Action_7 A7[51];	//�±�0����
int bestp = 0;			//����Ч��

void solve()
{
	for (int i = 1; i <= n; i++)	//����A����Ԫ��
	{
		A7[i].t = t[i];
		A7[i].d = d[i];
		A7[i].p = p[i];
	}

	sort(A7, A7 + 1);
	int sum = 0;
	for (int i = 1; i < sizeof(A7); i++)
	{
		if (A7[i].d > sum)
		{
			bestp += A7[i].p;
			sum += A7[i].t;
		}
	}
}

//̰�ķ������ˮ��ҵ��������
int a[N] = { 5,12,4,8 };		//��ӦM1��ʱ��
int b[N] = { 6,2,14,7 };		//��ӦM2��ʱ��

struct NodeType_8
{
	int no;			//��ҵ���
	bool group;			//1�����һ��N1,0����ڶ���N2
	int time;			//a,b����Сʱ��
	bool operator<(const NodeType_8& s) const
	{
		return time < s.time;	//���ڰ�time��������
	}
};
int best[N];			//���ŵ�������

//�������
int solve_8()
{
	n = 4;
	int i, j, k;
	NodeType_8 c[N];
	for (int i = 0; i < n; i++)
	{
		c[i].no = i;
		c[i].group = (a[i] <= b[i]);
		c[i].time = a[i] <= b[i] ? a[i] : b[i];
	}
	sort(c, c + n);       //cԪ�ذ���time��������
	j = 0; k = n - 1;
	for (i = 0; i < n; i++)  //ɨ��c����Ԫ��,�������ŵ��ȷ���
	{
		if (c[i].group == 1)
			best[j++] = c[i].no;//��1��,��time�������з���best��ǰ�沿��
		else
			best[k--] = c[i].no;//��0��,��time�ݼ����зŵ�best�ĺ��沿��
	}
	int f1 = 0;   //�ۼ�M1�ϵ�ִ��ʱ��
	int f2 = 0;    //���ŵ����µ�������ʱ��
	for (i = 0; i < n; i++)
	{
		f1 += a[best[i]];
		f2 = max(f2, f1) + b[best[i]];
	}
	return f2;
}