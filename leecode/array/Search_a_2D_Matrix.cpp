/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
/*
本质是一个二分查找.
注意怎么更新minval和maxval；
注意循环截止条件。
*/
#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector< vector<int> >& matrix, int target) {
    int rows=matrix.size();
    if(rows==0)
    return false;
    int cols=matrix[0].size();
    int maxval=(rows-1)*cols+cols-1;
    int minval=0;
    while(minval<=maxval)
    {
        int mid=minval+(maxval-minval)/2;
        int row=mid/cols;
        int col=mid%cols;
        if(matrix[row][col]==target)
        return true;
        else if (matrix[row][col]<target)
        {
            minval=mid+1;
        }
        else
        {
            maxval=mid-1;
        }
    }
    return false;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector< vector<int> > data;
        int target;
        cin>>target;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<m;j++)
            {
                int temval;
                cin>>temval;
                temp.push_back(temval);
            }
            data.push_back(temp);
        }
        cout<<searchMatrix(data,target);
    }
    return 0;
}