#include "ALG_Recursion.h"
using namespace std;

void main()
{
	BTNode* btree;  //创建btree
	TElemType a[] = { 1,2,4,5,3,6 };   //先序序列
	TElemType b[] = { 4,2,5,1,3,6 };  //中序序列

	btree = CreateBTree(a, b, 6);
	LevelOrder(btree);   //层次遍历二叉树
	vector<TElemType>tmppath;
	vector<TElemType>path;
	Findxpath2(btree, 6, tmppath, path);  //找到路径
	cout << endl;
	for (int i = 0; i < path.size(); i++)
	{
		cout << "path: " << path[i].a << endl;
	}

	cout << "------2.12------ " << endl;
	Digits(123);




	cout << "n皇后运行结果" << endl;
	queen(0, 10);
}