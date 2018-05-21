/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using 
only constant extra space complexity?
*/
#include<bits/stdc++.h>
using namespace std;
//先求出0,1，。。n的和，再以此减去数组中的数，最后剩下来的就是所缺失的数
int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int sum=n*(n+1)/2;
    for(int i=0;i<n;i++)
    {
        sum=sum-nums[i];
    }
    return sum;
}