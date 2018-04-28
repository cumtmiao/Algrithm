/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 
symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
#include<bits/stdc++.h>
using namespace std;
//使用动态规划：dp[i][j]表示前i个元素的和为j-1000的方法数。
int findTargetSumWays(vector<int>& nums, int S) {
    if(nums.size()==0||S>1000)
    return 0;
    vector< vector<int> >dp(21,vector<int>(2001,0));
    dp[0][1000]=1;
    for(int i=1;i<=nums.size();i++)
    {
        for(int j=-1000;j<=1000;j++)
        {
            if(dp[i-1][j+1000]>0)
            {
                dp[i][j+1000+nums[i-1]]+=dp[i-1][j+1000];
                dp[i][j+1000-nums[i-1]]+=dp[i-1][j+1000];
            }
        }
    }
    return dp[nums.size()][S+1000];
}