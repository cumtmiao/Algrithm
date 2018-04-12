/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include<iostream>
#include<vector>
using namespace std;
//��i�е�ֵ������n-i-1�У���j�е�ֵ������j�С�
void rotate(vector<vector<int>>& matrix) {
	int n=matrix.size();
	vector<vector<int>> res(matrix);
	for (int i = 0; i < n; i++)//���ȼ�����������
	{
		for (int j = 0; j < n; j++)
		{
			 res[j][n - 1 - i]=matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++)//�ٽ���������ֵ����ԭ����
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = res[i][j];
		}
	}
}