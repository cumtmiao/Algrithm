/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and 
return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/
/*
本题目的思路是基于LeetCode84题“直方图中最大的矩形”，相当于遍历矩阵的每一行，然后累计i行及其以上部分构成的
直方图，遍历所有行，即可求得二维矩阵中最大的矩形。

此题是之前那道的 Largest Rectangle in Histogram 直方图中最大的矩形 的扩展，这道题的二维矩阵每一层向上都可以看做一个
直方图，输入矩阵有多少行，就可以形成多少个直方图，对每个直方图都调用 Largest Rectangle in Histogram 直方图中最大的
矩形 中的方法，就可以得到最大的矩形面积。那么这道题唯一要做的就是将每一层构成直方图，由于题目限定了输入矩阵的字符只有
 '0' 和 '1' 两种，所以处理起来也相对简单。方法是，对于每一个点，如果是‘0’，则赋0，如果是 ‘1’，就赋 之前的height
 值加上1。
*/
#include<bits/stdc++.h>
using namespace std;
int Largest_Rectangle_in_Histogram(vector<int>& heights)
{
    heights.push_back(0);
    int size=heights.size();
    stack<int> sta;
    int ans=0;
    for(int i=0;i<size;i++)
    {
        if(sta.empty()||heights[sta.top()]<=heights[i])
        sta.push(i);
        else
        {
            int temp=sta.top();
            sta.pop();
            ans=max(ans,heights[temp]*(sta.empty()?i:i-sta.top()-1));
            i--;
        }
    }
    return ans;
}
int maximalRectangle(vector< vector<char> >& matrix) {
    int rows=matrix.size();
    if(rows==0)
    return 0;
    int ans=0;
    vector<int> height(matrix[0].size(),0);
    int cols=matrix[0].size();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(matrix[i][j]=='0')
            height[j]=0;
            else
            height[j]+=1;
        }
        ans=max(ans,Largest_Rectangle_in_Histogram(height));
    }
    return ans;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector< vector<char> > data;
        for(int i=0;i<n;i++)
        {
            vector<char> tempv;
            for(int j=0;j<m;j++)
            {
                char temp;
                cin>>temp;
                tempv.push_back(temp);
            }
            data.push_back(tempv);
        }
        cout<<maximalRectangle(data);
    }
}