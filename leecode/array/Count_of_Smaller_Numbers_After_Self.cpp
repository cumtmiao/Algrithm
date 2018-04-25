/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/
#include <bits/stdc++.h>
using namespace std;
/*
暴力方法：时间复杂度为O(n^n)
AC：16/16。时间超时。
*/
vector<int> countSmaller(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
    return nums;
    vector<int> res;
    for(int i=0;i<n-1;i++)
    {
        int temp=0;
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]>nums[j])
            temp++;
        }
        res.push_back(temp);
    }
    res.push_back(0);
    return res;
}
/*
二分查找方法。借助辅助数组help，把原始数组中的每个数从后往前按照顺序插入到辅助数组中，在插入辅助数组的过程中使其中的元素保持增序。
插入过程中，辅助数组元素的索引即可以表示当前元素右边有几个元素比当前元素小。
空间复杂度O(n)
时间复杂度O(nlogn);
*/
vector<int> countSmaller(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
    return nums;
    vector<int> res(n);
    vector<int> help;
    for(int i=n-1;i>=0;i--)
    {
        int l=0;int r=help.size();
        while(l<r)//用二分查找法查nums[i]的插入位置
        {
            int mid=l+(r-l)/2;
            if(help[mid]<nums[i])
            l=mid+1;
            else
            r=mid;
        }
        res[i]=r;//插入位置的索引表明了当前元素右边有几个元素比该元素小
        help.insert(help.begin()+r,nums[i]);
    }
    return res;
}
