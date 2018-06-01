/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/
#include<bits/stdc++.h>
using namespace std;
bool findnum(vector<int> nums,int l,int r,int target)
{
    for(int i=l;i<=r;i++)
    {
        if(nums[i]==target)
        return true;
    }
    return false;
}
/*
使用二分法。当左右两端不相等的时候可以应用二分，否则的话只能顺序查找
*/
bool search(vector<int>& nums, int target) {
    int n=nums.size();
    if(n==0)
    return false;
    if(n==1)
    {
        if(nums[0]==target)
        return true;
        else
        return false;
    }
    int l=0;
    int r=n-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(nums[mid]==target)
        return true;
        if(nums[l]>nums[r])
        {
            if(nums[mid]<nums[r])
            {
                if(target<=nums[r]&&target>nums[mid])
                l=mid+1;
                else
                r=mid-1;
            }
            else if(nums[mid]>nums[l])
            {
                if(target>=nums[l]&&target<nums[mid])
                r=mid-1;
                else
                l=mid+1;
            }
            else
            return findnum(nums,l,r,target);
        }
        else
        {
            return findnum(nums,l,r,target);
        }
    }
    if(nums[l]==target)
    return true;
    else
    return false;
}
/*
对方法一的改进能够通过AC 并且超过95%的方法。
*/
bool search(vector<int>& nums, int target) {
    int n=nums.size();
    if(n==0)
    return false;
    if(n==1)
    {
        if(nums[0]==target)
        return true;
        else
        return false;
    }
    int l=0;
    int r=n-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(nums[mid]==target)
        return true;
        if(nums[l]>nums[r])//左边比右边大
        {
            if(nums[mid]<=nums[r])//右边有序
            {
                if(target<=nums[r]&&target>nums[mid])
                l=mid+1;
                else
                r=mid-1;
            }
            else//左边有序
            {
                if(target>=nums[l]&&target<nums[mid])
                r=mid-1;
                else
                l=mid+1;
            }
        }
        else if(nums[l]==nums[r])//左右相等
        {
            l++;
        }
        else//整个数组有序
        {
            if(target>nums[mid])
            {
                l=mid+1;
            }
            else
                r=mid-1;
        }
    }
    if(l<n&&nums[l]==target)
    return true;
    else
    return false;
}
/*
参考网上的思路：
比较中间元素和最左边的元素：nums[mid]和nums[start]：
如果nums[mid]>nums[start]->左边元素有序
如果nums[mid]<nums[start]->右边元素有序
如果nums[mid]==nums[start]->无法判断是否有序，此时将start++.
*/
bool search(vector<int>& nums,int target) { 
    int n=nums.size();
    int start = 0,end = n-1;  
    int mid;  
    while(start <= end){  
        mid = (start + end) / 2;  
        if(nums[mid] == target){  
            return true;  
        }  
        //中间元素大于最左边元素则左部分为有序数组  
        else if(nums[mid] > nums[start]){  
            //目标位于左部分  
            if(target >= nums[start] && target < nums[mid]){  
                end = mid - 1;  
            }  
            //目标位于右部分  
            else{  
                start = mid + 1;  
            }  
        }  
        //中间元素小于最左边元素则右部分为有序数组  
        else if(nums[mid] < nums[start]){  
            //目标位于右部分  
            if(target <= nums[end] && target > nums[mid]){  
                start = mid + 1;  
            }  
            //目标位于左部分  
            else{  
                end = mid - 1;  
            }  
        }  
        //中间元素等于最左边元素则无法区分有序部分  
        else{  
            start++;  
        }  
    }  
    return false;  
    }  