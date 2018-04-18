/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to 
the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space 
for the purpose of space complexity analysis.)
*/
#include<bits/stdc++.h>
using namespace std;
/*
时间复杂度O(n);空间复杂度O(n);
*/
vector<int> productExceptSelf(vector<int>& nums) {
    const int length=nums.size();
    vector<int> A(length,0);
    vector<int> B(length,0);
    A[0]=1;
    for(int i=1;i<length;i++)
    {
        A[i]=A[i-1]*nums[i-1];
    }
    B[length-1]=1;
    for(int i=length-2;i>=0;i--)
    {
        B[i]=B[i+1]*nums[i+1];
    }
    for(int i=0;i<length;i++)
    {
        A[i]=A[i]*B[i];
    }
    return A;
}
/*
将上述算法改进成O(1)的空间复杂度
*/
vector<int> productExceptSelf(vector<int>& nums) {
    int length=nums.size();
    vector<int> A(length,0);
    A[0]=1;
    int p=1;
    for(int i=1;i<length;i++)
    {
        A[i]=A[i-1]*nums[i-1];
    }
    for(int i=length-2;i>=0;i--)
    {
        p=p*nums[i+1];
        A[i]=A[i]*p;
    }
    return A;
}
