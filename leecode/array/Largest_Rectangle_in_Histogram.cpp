/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/
#include<bits/stdc++.h>
using namespace std;
/*
最直接的解法：时间复杂度O(n^2);空间复杂度O(1).---超时
AC样例 93/96;
*/

int largestRectangleArea(vector<int>& heights) {
    int size=heights.size();
    if(size==0)
    return 0;
    // int area[size];
    // // memset(area,0,sizeof(area));
    // area[0]=heights[0];
    int res=0;//返回的结果
    for(int i=0;i<size;i++)
    {
        int tempmax=0;//记录以i为结束位置的最大area的值
        int tempmin=INT_MAX;//记录i结束位置左边的最小值
        for(int j=i;j>=0;j--)
        {
            if(heights[j]<tempmin)
                tempmin=heights[j];
            tempmax=max((i-j+1)*tempmin,tempmax);
        }
       // area[i]=tempmax;
        res=max(res,tempmax);
    }
    return res;
}
/*
使用栈的方法，时间复杂度为o(n)。
栈中放的是非递减序列的索引.
参见：https://www.cnblogs.com/grandyang/p/4322653.html
*/
int largestRectangleArea(vector<int>& heights) 
{
    int size=heights.size();
    if(size==0)
    return 0;
    stack<int> sta;
    heights.push_back(0);//在末尾添加一个元素0，保证能够结束计算出最大值
    int res=0;
    for(int i=0;i<heights.size();i++)
    {
        if(sta.empty()||heights[sta.top()]<=heights[i])//当前访问的元素大于等于栈顶元素
        sta.push(i);
        else
        {
            int temp=sta.top();
            sta.pop();
            res=max(res,heights[temp]*(sta.empty()?i:i-sta.top()-1));
            i--;
        }
    }
    return res;
    
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> data;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            data.push_back(temp);
        }
        cout<<largestRectangleArea(data);
    }
}