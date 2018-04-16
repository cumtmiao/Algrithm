/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
*/
/*
采用动态规划的思想：
sumarray[i][j]表示到左上角最小的路径和。
*/
#include<bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
    const int rows=grid.size();
    if(rows==0)
    return 0;
    const int cols=grid[0].size();
    int sumarray[rows][cols];
    memset(sumarray,0,sizeof(sumarray));
    int tempsum=0;
    for(int i=0;i<cols;i++)//初始化第一行
    {
        tempsum+=grid[0][i];
        sumarray[0][i]=tempsum;
    }
    tempsum=0;
    for(int i=0;i<rows;i++)//初始化第一列
    {
        tempsum+=grid[i][0];
        sumarray[i][0]=tempsum;
    }
    for(int i=1;i<rows;i++)//动态规划的过程
    {
        for(int j=1;j<cols;j++)
        {
            sumarray[i][j]=min(sumarray[i][j-1],sumarray[i-1][j])+grid[i][j];
        }
    }
    return sumarray[rows-1][cols-1];
}
