/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by 
array nums. You are asked to burst all the balloons. If the you burst balloon i you will get 
nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. 
After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/
#include<bits/stdc++.h>
using namespace std;
/*
还用动态规划来求解。
dp[i][j]:表示打爆[i<->j]之间的气球所获得的金币的最大值。
状态转移方程：
dp[i][right]=max(dp[i][right],dp[i][j-1]+dp[j+1][right]+nums[i-1]*nums[j]*nums[right+1]);
*/
int maxCoins(vector<int>& nums) {
    const int n=nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    int dp[n+2][n+2];
    memset(dp,0,sizeof(dp));

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n-k+1;i++)
        {
            int right=i+k-1;
            for(int j=i;j<=right;j++)
            {
                dp[i][right]=max(dp[i][right],dp[i][j-1]+dp[j+1][right]+nums[i-1]*nums[j]*nums[right+1]);
            }
        }
    }
    return dp[1][n];
}