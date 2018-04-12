/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
#include<iostream>
#include<vector>
using namespace std;
//accepted!!！基本和uniquepaths差不多  就是要处理obstacleGrid[i][j]==1时的情况  分情况讨论
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	if (m == 0)return 0;
	int n = obstacleGrid[0].size();
	vector<vector<int>> res(m,vector<int>(n,0));
	int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < n; i++)//初始化第0行，当遇到障碍物时，res其后全为0。
	{	
		if (obstacleGrid[0][i] == 0 && flag1 == 0)
			res[0][i] = 1;
		else if (obstacleGrid[0][i] == 1)
		{
			flag1 = 1;
			res[0][i] = 0;
		}
		else
			res[0][i] = 0;	
	}
	for (int i = 0; i < m; i++)//初始化第0列，当遇到障碍物时，res其后全为0。
	{
		if (obstacleGrid[i][0] == 0 && flag2 == 0)
			res[i][0] = 1;
		else if (obstacleGrid[i][0] == 1)
		{
			flag2 = 1;
			res[i][0] = 0;
		}
		else
			res[i][0] = 0;
	}
	for (int i = 1; i < m; i++)//动态规划，开始计算res[i][j]，注意分情况讨论
	{
		for (int j = 1; j < n; j++)
		{
			if (obstacleGrid[i][j]==1)//obstacleGrid[i][j]是障碍物
				res[i][j] = 0;
			else
			{
				if (obstacleGrid[i - 1][j] == 1 && obstacleGrid[i][j - 1] == 1)
					res[i][j] = 0;
				else if (obstacleGrid[i - 1][j] == 1 && obstacleGrid[i][j - 1] == 0)
					res[i][j] = res[i][j - 1];
				else if (obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j - 1] == 1)
					res[i][j] = res[i - 1][j];
				else
					res[i][j] = res[i - 1][j] + res[i][j - 1];
			}
			
		}
	}
	return res[m-1][n-1];
	
}