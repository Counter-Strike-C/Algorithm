#include "ALG_Recursion.h"
using namespace std;

void main()
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