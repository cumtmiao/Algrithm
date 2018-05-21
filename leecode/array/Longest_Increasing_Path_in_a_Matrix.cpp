/*
iven an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
#include<bits/stdc++.h>
using namespace std;
/*
dfs+记忆搜索。在本问题中记忆搜索能够极大地减小搜索空间。
*/
int longestIncreasingPathCore(vector<vector<int>>& matrix,vector<vector<int>>& mem,int i,int j,int rows,int cols)
{
    if(mem[i][j]!=0)
    return mem[i][j];
    if(i-1>=0&&matrix[i-1][j]>matrix[i][j])
    {
        mem[i][j]=longestIncreasingPathCore(matrix,mem,i-1,j,rows,cols);
    }
    if(i+1<rows&&matrix[i+1][j]>matrix[i][j])
    {
        mem[i][j]=max(mem[i][j],longestIncreasingPathCore(matrix,mem,i+1,j,rows,cols));     
    }
    if(j-1>=0&&matrix[i][j-1]>matrix[i][j])
    {
        mem[i][j]=max(mem[i][j],longestIncreasingPathCore(matrix,mem,i,j-1,rows,cols));
    }
    if(j+1<cols&&matrix[i][j+1]>matrix[i][j])
    {
        mem[i][j]=max(mem[i][j],longestIncreasingPathCore(matrix,mem,i,j+1,rows,cols));
    }
    mem[i][j]++;
    return mem[i][j];
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int rows=matrix.size();
    if(rows==0)
    return 0;
    int cols=matrix[0].size();
    int maxval=0;
    vector<vector<int>> mem(rows,vector<int>(cols,0));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        { 
            bool flag=false;//标记一个节点周围是否有比它小的节点。
            if(i-1>=0)
            {
                if(matrix[i-1][j]<matrix[i][j])
                flag=true;
            }
            if(i+1<rows)
            {
                if(matrix[i+1][j]<matrix[i][j])
                flag=true;
            }
            if(j-1>=0)
            {
                if(matrix[i][j-1]<matrix[i][j])
                flag=true;
            }
            if(j+1<cols)
            {
                if(matrix[i][j+1]<matrix[i][j])
                flag=true;
            }
            if(flag==true)
            continue;
            else
            maxval=max(maxval,longestIncreasingPathCore(matrix,mem,i,j,rows,cols));
        }
    }
    return maxval;
}