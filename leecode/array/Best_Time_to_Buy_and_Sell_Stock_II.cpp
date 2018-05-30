/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you 
buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
#include<bits/stdc++.h>
using namespace std;
/*
每次找到最低点和最高点，同时记录最大收益。
*/
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int left=0;
    int right=0;
    int res=0;
    while(right<n)
    {
        while(right==0||(right<n&&prices[right]>=prices[right-1]))//查找连续递增序列的最右位置
        right++;
        if(right==n)//如果到达数组的末尾，则记录结果返回
        {
            res+=prices[--right]-prices[left];
            break;
        }
        else//否则：记录结果，更新left，找连续递减序列的最右位置赋值给left,同时更新right
        {
            res+=prices[--right]-prices[left];
            left=right+1;
            while(left==0||(left<n&&prices[left]<=prices[left-1]))
            left++;
            if(n==left)
            break;
            else
            {
                left--;
                right=left+1;
            }
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
        cout<<maxProfit(data);
    }
    return 0;
}