/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)//交换两个元素
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n=nums.size();
    vector<int> res;
    for(int i=0;i<n;i++)//如果一个元素不在自己应该在的位置的时候，把它交换到本该在的位置。
    {
        while(nums[nums[i]-1]!=nums[i])
        swap(&nums[nums[i]-1],&nums[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(nums[i-1]!=i)
        res.push_back(i);
    }
    return res;
}