#include "ALG_MapMethod.h"
#include "Graph.cpp"
#include "Common.h"
//ͼ�㷨���


typedef set<int> SET;   //���弯��
MGraph g;      //ͼ���ڽӾ���
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
	int minpathlen = INF;
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
void debug2()
{
	//�����ʾ
	int s;    

	//��������ʾ
	int Count = 1;   //·�������ۼ�
	vector<int>minpath;     //���·������
	int minpathlen = INF;

}
