/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and 
return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/
/*
本题目继承了LeetCode中题目“largestRectangleArea”问题：本质相当于求直方图中最大的正方形面积。
时间复杂度O(n^2)
*/
#include<bits/stdc++.h>
using namespace std;

int largest_square(vector<int>& height)//求直方图中最大的正方形面积
{
    height.push_back(0);
    stack<int> sta;
    int res=0;
    for(int i=0;i<height.size();i++)
    {
        if(sta.empty()||height[sta.top()]<=height[i])
        sta.push(i);
        else
        {
            int temp=sta.top();
            sta.pop();
            int res1=min((sta.empty()?i:i-sta.top()-1),height[temp]);
            res=max(res,res1*res1);
            i--;
        }
    }
    return res;
}
int maximalSquare(vector< vector<char> >& matrix) {
    int rows=matrix.size();
    if(rows==0)
    return 0;
    int cols=matrix[0].size();
    vector<int> height(cols,0);
    int res=0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(matrix[i][j]=='0')
            height[j]=0;
            else
            height[j]+=1;
        }
        res=max(res,largest_square(height));
    }
    return res;
}

/*
思路二：动态规划。
状态转移方程：
dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
*/
int maximalSquare(vector< vector<char> >& matrix) {
    const int rows=matrix.size();
    if(rows==0)
    return 0;
    const int cols=matrix[0].size();
    int dp[rows][cols];
    int ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<cols;i++)//定义边界
    {
        if(matrix[0][i]=='0')
        dp[0][i]=0;
        else
        {
            dp[0][i]=1;
            ans=1;
        }
    }
    for(int i=0;i<rows;i++)//定义边界
    {
        if(matrix[i][0]=='0')
        dp[i][0]=0;
        else
        {
            dp[i][0]=1;
            ans=1;
        }
    }

    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)//动态规划的过程  状态转移
        {
            if(matrix[i][j]=='0')
            dp[i][j]=0;
            else
            {
                dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                ans=max(ans,dp[i][j]);
            }
        }
    }
    return ans*ans;
}
int main()
{
    int n,m;
    vector< vector<char> > data;
    while(cin>>n>>m)
    {
        
        for(int i=0;i<n;i++)
        {
            vector<char> temp;
            for(int j=0;j<m;j++)
            {
                char tempval;
                cin>>tempval;
                temp.push_back(tempval);
            }
            data.push_back(temp);
        }
        cout<<maximalSquare(data);
    }
}