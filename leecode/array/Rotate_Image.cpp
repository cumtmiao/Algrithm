/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include<iostream>
#include<vector>
using namespace std;
//第i行的值赋给第n-i-1列；第j列的值赋给第j行。
void rotate(vector<vector<int>>& matrix) {
	int n=matrix.size();
	vector<vector<int>> res(matrix);
	for (int i = 0; i < n; i++)//首先计算出结果矩阵
	{
		for (int j = 0; j < n; j++)
		{
			 res[j][n - 1 - i]=matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++)//再将结果矩阵的值赋给原矩阵
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = res[i][j];
		}
	}
}