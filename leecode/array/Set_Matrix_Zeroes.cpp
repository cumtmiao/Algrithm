/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include<bits/stdc++.h>
using namespace std;
/*
first_row:表示第一行是否有0
first_col:表示第一列是否有0
*/
void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size();
    if(m!=0)
    {
        int n=matrix[0].size();
        bool first_row=false;
        bool first_col=false;
        for(int i=0;i<n;i++)//判断第一行是否有0
        {
            if(matrix[0][i]==0)
            {
                first_row=true;
                break;
            }
        }
        for(int i=0;i<m;i++)//判断第一列是否有0
        {
            if(matrix[i][0]==0)
            {
                first_col=true;
                break;
            }
        }
        for(int i=1;i<m;i++)//根据除了第一列和第一行的值-->来更新第一行和第一列（记录对应某一行和某一列是否有0）
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<m;i++)//根据第一行和第一列的值来更新矩阵的其他部分
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(first_row)//更新第一行
        {
            for(int i=0;i<n;i++)
            {
                matrix[0][i]=0;
            }
        }
        if(first_col)//更新第一列
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][0]=0;
            }
        }
    }
}