/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one 
and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/
#include<bits/stdc++.h>
using namespace std;
/*
动态规划。
具体状态转移图可参见：
https://www.cnblogs.com/jdneo/p/5228004.html
*/
int maxProfit(vector<int>& prices) {
    int length=prices.size();
    if(length==0)
    return 0;
    vector<int> s0(length,0);//表示买之前最大的收益
    vector<int> s1(length,0);//表示买之后最大的收益
    vector<int> s2(length,0);//表示卖之后最大的收益
    s0[0]=0;
    s1[0]=-prices[0];
    s2[0]=INT_MIN;
    for(int i=1;i<length;i++)
    {
        s0[i]=max(s0[i-1],s2[i-1]);
        s1[i]=max(s0[i-1]-prices[i],s1[i-1]);
        s2[i]=s1[i-1]+prices[i];
    }
    return max(s0[length-1],s2[length-1]);
}