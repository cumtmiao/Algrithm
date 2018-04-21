/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of 
money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police if two adjacent houses were broken 
into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum 
amount of money you can rob tonight without alerting the police.
*/
#include<bits/stdc++.h>
using namespace std;
/*
简单的动态规划：
dp[i]:表示前i个元素能够robber的最大值。
状态转移方程：
dp[i]=max(dp[i-1],dp[i-2]+num[i-1]);
*/
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
    return 0;
    if(n==1)
    return nums[0];
    int dp[n+1];
    dp[0]=0;
    dp[1]=nums[0];
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
    }
    return dp[n];
}