#include "ALG_MapMethod.h"
#include "Graph.cpp"
#include "Common.h"
//ͼ�㷨���


typedef set<int> SET;   //���弯��
MGraph g;      //ͼ���ڽӾ���
int minpathlen = INF;
//ʹ�ö�̬�滮����������м�����
void debug1()
{
	//���tsp����
	//�����ʾ
	int s = 0;    //���Ϊ0

	int A[][MAXV] = {						//һ����Ȩ����ͼ
		{0,8,5,36},{6,0,8,5},{8,9,0,5},{7,7,8,0} };
	int n = 4, e = 12;
	CreateMat(g, A, n, e);					//����ͼ���ڽӾ���g
	SET V;
	for (int i = 1; i < g.n; i++)				//����1,2,3����
		V.insert(i);    //�������㼯��

	f(V, 0);

	free(&g);
}

int f(SET V, int i)
{

	if (V.size() == 0)   //��vΪ��ʱ,ֱ�ӷ��ص�ǰ��
		return g.edges[0][i];
	else     //���ϲ�Ϊ��ʱ
	{
		SET::iterator it;
		for (it = V.begin(); it != V.end(); ++it)        //ɨ�輯��v�еĶ���
		{
			SET tmpV = V;
			int j = *it;
			tmpV.erase(j);      //ȥ��j
			int pathlen = f(tmpV, j) + g.edges[i][j];      //������һ���㵽��һ�������
			minpathlen = min(minpathlen, pathlen);
		}
		return minpathlen;
	}
}

//���ݷ����tsp����
int s = 0;
vector<int>minpath;     //���·������
void debug2()
{
	minpath.clear();
	minpathlen = INF;
	//��������ʾ
	int Count = 1;   //·�������ۼ�
	int A[][MAXV] = {						//һ����Ȩ����ͼ
		{0,8,5,36}, {6,0,8,5}, {8,9,0,5}, {7,7,8,0} };
	int n = 4, e = 12;
	CreateMat(g, A, n, e);		//����ͼ���ڽӾ���洢�ṹg
	s = 0;					//��ʼ����Ϊ0
	vector<int> path;
	int pathlen = 0;
	SET V;
	for (int i = 1; i < g.n; i++)			//����1,2,3��
		V.insert(i);
	TSP2(V, 0, path, pathlen);
}

//���ݷ�
void TSP2(SET V,int i,vector<int> path,int pathlen)
{
	int prev; 
	if (path.size() > 0)
		prev = path.back();        //prevΪ·�����һ������
	path.push_back(i);     //��ӵ�ǰ����i
	pathlen += g.edges[prev][i];      //�ۼ�·������
	if (V.size() == 0)      //�ҵ�һ��Ҷ�ӽڵ�
	{
		if (g.edges[i][s] != 0 && g.edges[i][s] != INF)  //�������i�����s֮���б�
		{
			path.push_back(0);   //·���������0
			pathlen += g.edges[i][s];     //�ۼ�·������
			if (pathlen < minpathlen)
			{
				minpathlen = pathlen;
				minpath = path;
			}
		}
	}
	else
	{
		SET::iterator it;
		for (it = V.begin(); it != V.end(); it++)
		{
			SET tmpV = V;
			int j = *it;
			tmpV.erase(j);
			if (pathlen < minpathlen)
				minpathlen = pathlen;
		}
	}
}

//��֦�޽編�������
struct NodeType3			//���н������
{
	int v;				//��ǰ����
	int num;				//·���еĽ�����
	vector<int> path;			//��ǰ·��
	int pathlen;			//��ǰ·������
	int visited[MAXV];			//������ʱ��
	bool operator<(const NodeType3& s) const
	{
		return pathlen > s.pathlen;	//pathlenԽСԽ���ȳ���
	}
};
struct NodeType3;    //���нڵ�����
void debug3()
{
	s = 0;

	int Count = 1;
	vector<int> minpath;     //�������·��
	minpathlen = INF;
	
}

//��֦�޽編
void TSP3()
{
	NodeType3 e, e1;
	priority_queue<NodeType3> qu;        
	e.v = 0;          //���ڵ�e
	e.pathlen = 0;
	e.path.push_back(0);
	e.num = 0;
	memset(e.visited, 0, sizeof(e.visited));
	e.visited[0] = 1;
	qu.push(e);       //���ڵ�e����

	while (!qu.empty())      //�Ӳ���ѭ��
	{
		e = qu.top();
		qu.pop();      //���ӽڵ�e
		if (e.num == g.n)   //����Ҷ�ӽڵ�
		{
			if (g.edges[e.v][s] != 0 && g.edges[e.v][s] != INF)   //���e�����ڵ�s֮���б�
			{
				e.path.push_back(s);      //�������뵽·����
				e.pathlen += g.edges[e.v][s];       //��������e.v�����s��·������
				if (e.pathlen < minpathlen)    //�������·��
				{
					minpathlen = e.pathlen;
					minpath = e.path;
				}
			}
		}
		else  //��Ҷ�ӽڵ�
		{
			for (int j = 1; j < g.n; j++)    //����1������jѭ��
			{
				if (g.edges[e.v][j] != 0 && g.edges[e.v][j] != INF)     //��ǰ���㵽����j�б�
				{
					if (e.visited[j] == 1)//�����ظ����ʶ���
						continue;
					e1.v = j;
					e1.num = e.num + 1;
					e1.path = e.path;
					e1.path.push_back(j);
					e1.pathlen = e.pathlen + g.edges[e.v][j];
					for (int i = 0; i < g.n; i++)
						e1.visited[i] = e.visited[i];
					if (e1.pathlen < minpathlen)      //��֦
					{
						e1.visited[j] = 1;
						qu.push(e1);
					}
				}
			}
		}
	}
}