/*

Given an array with n objects colored red, white or blue, sort them so that objects of the same color
are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/
#include<bits/stdc++.h>
using namespace std;
/*
统计0 1的数量，直接输出给nums。
时间复杂度O(n);
空间复杂度O(1);
*/
void sortColors(vector<int>& nums) {
    int size=nums.size();
    int numof0=0;
    int numof1=0;
    for(int i=0;i<size;i++)
    {
        if(nums[i]==0)
        numof0++;
        else if (nums[i]==1)
        {
            numof1++;
        }
    }
    for(int i=0;i<numof0;i++)
       nums[i]=0;
    for(int i=numof0;i<numof0+numof1;i++)
       nums[i]=1;
    for(int i=numof0+numof1;i<size;i++)
       nums[i]=2;
}