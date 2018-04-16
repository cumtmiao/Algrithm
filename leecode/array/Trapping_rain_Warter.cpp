/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how 
much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain 
water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
#include<bits/stdc++.h>
using namespace std;
/*
暴力方法：针对在i位置，i位置能够收集的水的数量最多为：i位置左边的高度和右边高度的（都包含i位置）的最小值减去i位置的高度。
时间复杂度O(n^2)
*/
int trap(vector<int>& height) {
    int size=height.size();
    int ans=0;
    for(int i=1;i<size-1;i++)
    {
        int left_max=0;
        int right_max=0;    
        for(int j=i;j>=0;j--)
        {
            left_max=max(left_max,height[j]);
        }
        for(int k=i;k<size;k++)
        {
            right_max=max(right_max,height[k]);
        }
        ans+=min(left_max,right_max)-height[i];
    }
    return ans;
}

/*
动态规划：
使用两个数组，分别存储左边最大的值，和右边最大的值。
时间复杂度O(n);
空间复杂度O(n);
*/
int trap(vector<int>& height) 
{
    const int size=height.size();
    if (size==0)
    return 0;
    int left_max[size];
    int right_max[size];
    int lmax=0;
    for(int i=0;i<size;i++)
    {
        if(lmax<height[i])
        lmax=height[i];
        left_max[i]=lmax;
    }
    int rmax=0;
    for(int i=size-1;i>=0;i--)
    {
        if(rmax<height[i])
        rmax=height[i];
        right_max[i]=rmax;
    }
    int ans=0;
    for(int i=1;i<size-1;i++)
    {
        ans+=min(left_max[i],right_max[i])-height[i];
    }
    return ans;
}

/*
两个指针的方法：
时间复杂度为o(n);
空间复杂度为o(1);
*/
int trap(vector<int>& height) 
{
    int size=height.size();
    int left=0;
    int right=size-1;
    int left_max=0;
    int right_max=0;
    int ans=0;
    while(left<right)
    {
        if(height[left]<height[right])
        {
            if(height[left]>left_max)
            left_max=height[left];
            else
            ans+=left_max-height[left];
            left++;
        }
        else
        {
            if(height[right]>right_max)
            right_max=height[right];
            else
            ans+=right_max-height[right];
            right--;
        }
    }
    return ans;
}
