/*
Given an integer array with all positive numbers and no duplicates, find the number of possible 
combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.
Therefore the output is 7.
*/
#include<bits/stdc++.h>
using namespace std;
/*
本题目是动态规划的典型题，注意与“拼凑面额”的题目相对比。（本题目相当于求“排列数”，拼凑面额相当于求“组合数”）
其中dp[i]:表示目标为i的方法数。
*/
int combinationSum4(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    if(nums.size()==0||nums[0]>target)
    return 0;
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<=target;i++)
    {
        for(int j=0;j<nums.size();j++)
        {
            if(i>=nums[j])
            dp[i]+=dp[i-nums[j]];
        }
    }
    return dp[target];
}
int main()
{
    int n;
    while(cin>>n)
    {
        int target;
        cin>>target;
        vector<int> nums;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        cout<<combinationSum4(nums,target);
    }
    return 0;
}