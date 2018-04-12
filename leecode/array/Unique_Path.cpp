/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
Note: m and n will be at most 100.
*/
#include<iostream>
#include<vector>
using namespace std;
int numsofuniquePath(int currow, int curcol, int endrow, int endcol)
{
	if (currow < endrow&&curcol < endcol)
	{
		return numsofuniquePath(currow + 1, curcol, endrow, endcol) + numsofuniquePath(currow, curcol + 1, endrow, endcol);
	}
	else if (currow == endrow||curcol==endcol)
	{
		return 1;
	}

		
}
//使用迭代的方法  超时。！！
int uniquePaths1(int m, int n) {
	int currow = 0;
	int curcol = 0;
	return numsofuniquePath(0, 0, m - 1, n - 1);	
}
//方法二：使用动态规划的办法：v[i][j]=v[i-1][j]+v[i][j-1].
int uniquePaths(int m, int n)
{
	vector<vector<int>> v(m, vector<int>(n, 1));
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			v[i][j] = v[i-1][j] + v[i][j-1];
		}
	}
	return v[m - 1][n - 1];
}
/*
void main()
{
	cout << uniquePaths(9, 13);
}
*/