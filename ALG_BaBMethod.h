#pragma once
#include "Common.h"
class ALG_BaBMethod
{
#pragma region 01��������

	//�����ʾ
	int n = 3, W = 30;
	int w[4] = { 0,16,15,15 };				//�������±�0����
	int v[4] = { 0,45,25,25 };  				//��ֵ���±�0����
	//�������ʾ
	int maxv = -9999;						//�������ֵ,ȫ�ֱ���
	int bestx[MAXN];					//������Ž�,ȫ�ֱ���

	int total = 1;						//��ռ��н�����ۼ�,ȫ�ֱ���

	struct NodeType		//�����еĽ������
	{
		int no;			//����ţ���1��ʼ
		int i;			//��ǰ����������ռ��еĲ��
		int w;			//��ǰ����������
		int v;			//��ǰ�����ܼ�ֵ
		int x[MAXN];		//��ǰ�������Ľ�����
		double ub;			//�Ͻ�
		bool operator<(const NodeType& s) const	//����<��ϵ����
		{
			return ub < s.ub;				//ubԽ��Խ���ȳ���
		}
	};

	//������e���Ͻ�e.ub�㷨
	void bound(NodeType& e)
	{
		int i = e.i + 1;
		int sumw = e.w;
		double sumv = e.v;
		while (i<=n&&(sumw+w[i]<W))
		{
			sumw += w[i];
			sumv += v[i];
			i++;
		}
		if (i <= n)
			e.ub = sumv + (W - sumw) * v[i] / w[i];
		else
			e.ub = sumv;
	}

	void EnQueue(NodeType e, queue<NodeType>& qu)
	{
		if (e.i == n)  //����Ҷ�ӽڵ�
		{
			if (e.v > maxv)   //�ҵ���ֵ����Ľ�
			{
				maxv = e.v;
				for (int j = 1; j <= n; j++)
					bestx[j] = e.x[j];
			}
		}
		else qu.push(e);        //��Ҷ�ӽڵ����
	}


	void bfs1()    //��01���������Ž�
	{
		int j;
		NodeType e, e1, e2;
		queue<NodeType> qu;

		e.i = 0;
		e.w = 0;
		e.v = 0;
		e.no = total++;
		for (j = 1; j <= n; j++)
			e.x[j] = 0;	
		bound(e);         //����ڵ���Ͻ�
		qu.push(e);      //���ڵ����

		while (!qu.empty())    //�Ӳ���ѭ��
		{
			e = qu.front();
			qu.pop();   //���ӽڵ�

			if (e.w + w[e.i + 1] <= W)        //��֦��������ӽڵ�
			{
				e1.no = total++;     //e1��Ϊ�µ����ӽڵ�
				e1.i = e.i + 1; 
				e1.w = e.w + w[e1.i];
				e1.v = e.v + v[e1.i];    //
				for (j = 1; j <= n; j++)
					e1.x[j] = e.x[j];     //���ƽ�����
				e1.x[e1.i] = 1;  //���õ�ǰ������
				bound(e1);
				EnQueue(e1,qu);     //����
			}
			e2.no = total++;       //�����Һ��ӽڵ�
			e2.i = e.i++;
			e2.w = e.w;
			e2.v = e.v;
			for (j = 1; j <= n; j++)        //���ƽ�����
				e2.x[j] = e.x[j];
			e2.x[e2.i] = 0;	
			bound(e2);   //���Һ��ӽڵ���Ͻ�
			if (e2.ub > maxv)    //���Һ��ӽڵ����	������ӣ����򱻼�֦
				EnQueue(e2, qu);

				
		}
	}
#pragma endregion




};

