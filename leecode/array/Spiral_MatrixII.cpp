/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/
#include<iostream>
#include<vector>
using namespace std;
//����Ŀ�൱��spiral_matrix�������㣬�������һ����
vector<vector<int>> generateMatrix(int n) {	
	vector<vector<int>> res(n, vector<int>(n, 0));//�տ�ʼ��ʱ��������vector�ĳ�ʼ��������ᱨ��
	if (n == 0)return res;
	int rowbegin = 0;
	int rowend = n - 1;
	int colbegin = 0;
	int colend = n - 1;
	int num = 1;
	while (rowbegin <= rowend&&colbegin <= colend)
	{
		for (int i = colbegin; i <= colend; i++)
		{
			res[rowbegin][i] = num;
			num++;
		}
		rowbegin++;
		for (int i = rowbegin; i <= rowend; i++)
		{
			res[i][colend] = num;
			num++;
		}
		colend--;
		if (rowbegin <= rowend)//�ж�ֻ��һ�л�һ��ʱ������
		{
			for (int i = colend; i >= colbegin; i--)
			{
				res[rowend][i] = num;
				num++;
			}
			rowend--;
		}
		if (colbegin <= colend)//�ж�ֻ��һ�л�һ��ʱ������
		{
			for (int i = rowend; i >= rowbegin; i--)
			{
				res[i][colbegin] = num;
				num++;
			}
			colbegin++;
		}
	}
	return res;
}
/*
void main()
{
	vector<vector<int>> res = generateMatrix(1);
}
*/