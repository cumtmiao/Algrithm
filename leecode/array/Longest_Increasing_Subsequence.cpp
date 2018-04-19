/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/
#include<bits/stdc++.h>
using namespace std;
/*
使用动态规划的方法：
dp[i]:表示以i为结束位置，包含i元素的最长的增长序列的长度
状态转移方程：
dp[i]=max(dp[j])+1,∀0≤j<i
返回结果：
ans=max(ans,dp[i]);
*/
int lengthOfLIS(vector<int>& nums) {
    int length=nums.size();
    if(length==0)
        return 0;
    int dp[length];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int ans=1;
    for(int i=1;i<length;i++)
    {
        int maxval=0;
        for(int j=0;j<i;j++)
        {
            if(nums[i]>nums[j])
            maxval=max(maxval,dp[j]);
        }
        dp[i]=maxval+1;
        ans=max(ans,dp[i]);
    }
    return ans;
}
