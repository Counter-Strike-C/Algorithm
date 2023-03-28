#pragma once
#define MAX 1025
#include "Common.h"
//���η��㷨���

//1���������򣨼����ݽṹ��Ŀ��
//2����·�鲢���򣨼����ݽṹ��Ŀ��
//3���Զ����µĶ�·�鲢�㷨��������

//4����ⰴ��������򡱵�����С���򡱵�˳���������⡣
//һ�������еġ�δ���򡱵Ķ���������ڱ˴�˳��һ�µ���Ŀ�Ե����������磬����ĸ���С�DAABEC���У�
//�ö���Ϊ5����ΪD�����ұ���4����ĸ��E�������ұߵ�1����ĸ���ö�����Ϊ�����е���������
//���С�AACEDGG��ֻ��һ������ԣ�E��D������������������ˣ������С�ZWQM����6������ԣ�
//����δ����ģ�ǡ���Ƿ���
//����Ҫ�����ɸ�DNA���У�������4����ĸA��C��G��T���ַ��������࣬ע���Ƿ�������ǰ���ĸ˳������
//���ǰ��ա�������򡱵�����С���򡱵�˳�����У�����DNA���еĳ��ȶ���ͬ��

/*���ַ�����������ans*/
int ans;
void Merge(char a[], int low, int mid, int high)
{
	
	int i = low;
	int j = mid + 1;
	int k = 0;
	char* tmp = (char*)malloc((high - low + 1) * sizeof(char));
	while (i <= mid && j <= high)
	{
		if (a[i] > a[j])
		{
			tmp[k++] = a[j++];
			ans += mid - i + 1;        //�ۼ�����
		}
		else tmp[k++] = a[i++];
	}
	while (i <=mid)
		tmp[k++] = a[i++];
	while (j <=high)
		tmp[k++] = a[j++];
	for (int k1 = 0; k1 <k; k1++)
		a[low+k1] = tmp[k1];
	free(tmp);
}

void Merge_sort(char a[], int low,  int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;  //�Զ����£����η�˼��
		Merge_sort(a, low, mid);
		Merge_sort(a, mid+1, high);
		Merge(a, low, mid, high);
	}
}

int Inversion(char a[], int n)
{
	ans = 0;
	Merge_sort(a, 0, n - 1);   //��·�鲢�㷨���
	return ans;
}


//5���������ʹδ�Ԫ��
void solve(int a[], int low, int high, int& max1, int& max2)
{
	if (low == high)   //����ֻ��һ��Ԫ��
	{
		max1 = a[low];
		max2 = -INF;
	}
	else if (high - low == 1) //����������Ԫ��
	{
		max1 = a[high] > a[low] ? a[high] : a[low];
		max2 = a[high] > a[low] ? a[low] : a[high];
	}
	else
	{
		int mid = (low + high) / 2;
		int lmax1, lmax2;
		solve(a, low, mid, lmax1, lmax2);     //��������ֵ����������
		int rmax1, rmax2;
		solve(a, mid + 1, high, rmax1, rmax2);    //��������ֵ
		if (lmax1 > rmax1)
		{
			max1 = lmax1;
			max2 = lmax2 > rmax1 ? lmax2 : rmax1;
		}
		else
		{
			max1 = rmax1;
			max2 = rmax2 > lmax1 ? rmax2 : lmax1;
		}
	}
}

//6������һ������Ϊn���������У������Ϊ�������У�a[0..n-1]��
//�����м�λ�õ�Ԫ�س�Ϊa����λ����
//���һ���㷨������������������е���λ����
int midium(int a[], int s1, int t1, int b[], int s2, int t2)
{
	int m1, m2;
	if (s1 == t1 && s2 == t2)  //�ݹ����
		return a[s1] > b[s2] ? a[s1] : b[s2];
	else
	{
		m1 = (s1 + t1) / 2;
		m2 = (s2 + t2) / 2;
		if (a[m1] > b[m2])
		{
			prepart( s1, t1);
			postpart(s2, t2);
			return midium(a, s1, t1, b, s2, t2);
		}
	}
}

//�ֳ�ǰ��
void prepart(int& s, int& t)
{
	s = s;
	t = (s + t) / 2;
}

//�ֳ����
void postpart(int& s, int& t)
{
	t = t;
	s = (s + t) / 2;
}

long max3(long a, long b, long c)
{
	long max = a > b ? a : b;
	return max > c ? max : c;
}

//��a[left..high]������������������к�
long maxSubSum(int a[], int left, int right)
{
	int i, j;
	long maxLeftSum, maxRightSum;
	long maxLeftBorderSum, leftBorderSum;
	long maxRightBorderSum, rightBorderSum;

	if (left == right)     // ���������ֻ��һ��Ԫ��
	{
		if (a[left] > 0)
			return a[left];
		else
			return 0;
	}
	int mid = (left + right) / 2;
	maxLeftSum = maxSubSum(a, left, mid);
	maxRightSum = maxSubSum(a, mid + 1, right);
	maxLeftBorderSum = 0; leftBorderSum = 0;
	for (i = mid; i >= left; i--)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}
	maxRightBorderSum = 0; rightBorderSum = 0;
	for (j = mid+1; j<=right; j++)
	{
		rightBorderSum += a[i];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

//������̸��ǵ�����
//�����ʾ
int k;        //���̴�С       
int x, y;   //���ⷽ���λ��
	
//��������ʾ
int board[MAX][MAX];
int tile = 1;

//���̸�������
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)return;           //�ݹ����
	int t = tile++;       //ȡһ��L�͹ǣ����ƺ�Ϊtile
	int s = size / 2;      //�ָ�����

	//�������Ͻ�����
	if (dr < tr + s && dc < tc + s)       //���ⷽ���ڴ�������
		ChessBoard(tr, tc, dr, dc, s);
	else
	{
		board[tr + s - 1][tc + s - 1] = t; //��t��L�͹��Ƹ������½�
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
		//�����½���Ϊ���ⷽ�������������
	}

	//�������Ͻ�����
	if (dr < tr + s && dc >= tc + s)
		ChessBoard(tr, tc + s, dr, dc, s);		//���ⷽ���ڴ������� 
	else					//�������������ⷽ��
	{
		board[tr + s - 1][tc + s] = t;		//��t��L�͹��Ƹ������½�
		ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);
		//�����½���Ϊ���ⷽ��������������
	}

	//�������½�����
	if (dr >= tr + s && dc < tc + s)		//���ⷽ���ڴ�������
		ChessBoard(tr + s, tc, dr, dc, s);
	else				//�������������ⷽ��
	{
		board[tr + s][tc + s - 1] = t;  	//��t��L�͹��Ƹ������Ͻ�
		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);
		//�����Ͻ���Ϊ���ⷽ��������������
	}

	//�������½�����
	if (dr >= tr + s && dc >= tc + s)		//���ⷽ���ڴ�������
		ChessBoard(tr + s, tc + s, dr, dc, s);
	else				//�������������ⷽ��
	{
		board[tr + s][tc + s] = t;  	//��t��L�͹��Ƹ������Ͻ�
		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
		//�����Ͻ���Ϊ���ⷽ��������������
	}
}

//���ѭ���ճ̰�������
/* ����n=2k��ѡ��Ҫ��������ѭ������Ҫ�����һ����������Ҫ��ı����ճ̱�
     ��1��ÿ��ѡ�ֱ���������n-1��ѡ�ָ���һ�Ρ�
     ��2��ÿ��ѡ��һ��ֻ����һ�Ρ�
     ��3��ѭ������n-1��֮�ڽ�����
 */
#define MAX 101
int k;         //�������ʾ
int a[MAX][MAX];     //��ű����ճ̱�
void Plan(int k)
{
	int i, j, n, t, temp;
	n = 2;			//n��2^1=2��ʼ
	a[1][1] = 1; a[1][2] = 2;   	//���2��ѡ�ֱ����ճ�,�õ����Ͻ�Ԫ��
	a[2][1] = 2; a[2][2] = 1;
	for (t = 1; t < k; t++)		//��������2^2(t=1)��,2^k(t=k-1)��ѡ��
	{
		temp = n;					//temp=2^t ��һ�����鳤��
		n = n * 2; 					//n=2^(t+1)   ��һ������
		for (i = temp + 1; i <= n; i++)		//�����½�Ԫ��
			for (j = 1; j <= temp; j++)
				a[i][j] = a[i - temp][j] + temp; 	//�������½�Ԫ��
		for (i = 1; i <= temp; i++)		//�����Ͻ�Ԫ��
			for (j = temp + 1; j <= n; j++)
				a[i][j] = a[i + temp][(j + temp) % n];
		for (i = temp + 1; i <= n; i++)		//�����½�Ԫ��
			for (j = temp + 1; j <= n; j++)
				a[i][j] = a[i - temp][j - temp];
	}

}