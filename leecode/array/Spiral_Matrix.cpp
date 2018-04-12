/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
#include<iostream>
#include<vector>
using namespace std;
//从外到内循环，先外圈左->右，上->下，右->左，下->上。关键是注意边界条件和特殊情况的处理。
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	int m = matrix.size();
	if (m == 0)return res;
	int n = matrix[0].size();
	int rowbegin = 0;
	int rowend = m - 1;
	int colbegin = 0;
	int colend = n - 1;
	while (rowbegin <= rowend&&colbegin <= colend)
	{
		for (int i = colbegin; i <= colend; i++)
		{
			res.push_back(matrix[rowbegin][i]);
		}
		rowbegin++;
		for (int i = rowbegin; i <= rowend; i++)
		{
			res.push_back(matrix[i][colend]);
		}
		colend--;
		if (rowbegin <= rowend)//去重判断。
		{
			for (int i = colend; i >= colbegin; i--)
			{
				res.push_back(matrix[rowend][i]);
			}
			rowend--;
		}
		if (colbegin <= colend)//去重判断
		{
			for (int i = rowend; i >= rowbegin; i--)
			{
				res.push_back(matrix[i][colbegin]);
			}
			colbegin++;
		}
			
	}
	return res;
}
