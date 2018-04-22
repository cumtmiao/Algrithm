/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two 
subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/
#include<bits/stdc++.h>
using namespace std;
bool isodd(int n)
{
    return n%2==1;
}
//使用动态规划。
//dp[i]:表示原数组的任意元素是否能构成和为i的子集和
bool canPartition(vector<int>& nums) {
    int length=nums.size();
    int sum=0;
    for(int i=0;i<length;i++)
    {
        sum+=nums[i];
    }
    if(isodd(sum))//是奇数直接返回false
    return false;
    sum=sum/2;
    vector<bool> dp(sum+1,false);
    dp[0]=true;
    for(int i=0;i<length;i++)
    {
        for(int j=sum;j>=nums[i];j--)//注意此处为了避免前面的值影响后面的值，只能是倒序。
        {
            dp[j]=dp[j]||dp[j-nums[i]];
        }
    }
    return dp[sum];
}