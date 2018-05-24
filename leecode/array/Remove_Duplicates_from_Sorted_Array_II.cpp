/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and 
return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) 
extra memory.
Example 1:
Given nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It doesn't matter what you leave beyond the returned length.
Example 2:
Given nums = [0,0,1,1,1,1,2,3,3],
Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 
and 3 respectively.
It doesn't matter what values are set beyond the returned length.
*/
#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int first=0;//记录前面的指针
    int second=0;//记录后面的指针
    int num=0;
    for(;first<nums.size();first++)
    {
        if(first!=0&&nums[first]==nums[first-1])
        {
            num++;
            if(num>=3)
            continue;
        }
        else
        {
            num=1;
        }
        nums[second++]=nums[first];
    }
    return second;
}