#include "ALG_Recursion.h"
#include "ALG_DCMethod.h"
#include "ALG_BTMethod.h"
using namespace std;



//���ڲ��Եݹ��㷨
void test1()
{
	BTNode* btree;  //����btree
	TElemType a[] = { 1,2,4,5,3,6 };   //��������
	TElemType b[] = { 4,2,5,1,3,6 };  //��������

	btree = CreateBTree(a, b, 6);
	LevelOrder(btree);   //��α���������
	vector<TElemType>tmppath;
	vector<TElemType>path;
	Findxpath2(btree, 6, tmppath, path);  //�ҵ�·��
	cout << endl;
	for (int i = 0; i < path.size(); i++)
	{
		cout << "path: " << path[i].a << endl;
	}

	cout << "------2.12------ " << endl;
	Digits(123);




	cout << "n�ʺ����н��" << endl;
	queen(0, 10);
}

//���ڲ��Է����㷨
void test2()
{
	string str = "AACEDGG";
	char a[8];
	strncpy_s(a, str.c_str(), sizeof(a)-1);
	int ans = Inversion(a, sizeof(a)-1);
	cout <<"������Ϊ��"<< ans << endl;

	//�������ʹδ��Ԫ��
	int b[] = { 10,5,22,45,102,1,5,58,36,99,12,9 };
	int max1=0;
	int max2=0;
	cout << sizeof(b) / 4 << endl;
	solve(b, 0, sizeof(b) /4 -1, max1, max2);
	cout << "���ֵ��" << max1 << endl;
	cout << "�δ�ֵ��" << max2 << endl;
}

//���Ի��ݷ����ִ���
void test3()
{
	int a[] = { 1,2,3 };
	int n = 3;
	int i = 0;
	int x[3];
	dfsSubSet(a, n, i, x);
}

void main()
{
	//test1();
	//test2();
	test3();
}