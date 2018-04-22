/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in 
ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in 
ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/
#include<bits/stdc++.h>
using namespace std;
/*
时间复杂度O(n);空间复杂度O(n)
使用栈
*/
int findUnsortedSubarray(vector<int>& nums) {
    stack<int> s;
    int left=nums.size();//记录最短未排序序列的左边界
    int right=0;//记录最短未排序序列的右边界
    for(int i=0;i<nums.size();i++)//找到该左边界
    {
        if(s.empty()||nums[i]>=nums[s.top()])
        s.push(i);
        else
        {
        while(!s.empty()&&nums[i]<nums[s.top()])
        {
            left=min(left,s.top());
            s.pop();
        }
        s.push(i);
        }
    }
    while(!s.empty())
    s.pop();
    for(int i=nums.size()-1;i>=0;i--)//找到该右边界
    {
        if(s.empty()||nums[i]<=nums[s.top()])
        s.push(i);
        else
        {
            while(!s.empty()&&nums[i]>nums[s.top()])
            {
                right=max(right,s.top());
                s.pop();
            }
            s.push(i);
        }
    }
    if(right>left)
    return right-left+1;
    else
    return 0;
}

/*
思路二：时间复杂度为O(n)，空间复杂度为O(1)
*/
int findUnsortedSubarray(vector<int>& nums) {
    int minval=INT_MAX;
    int maxval=INT_MIN;
    bool flag=false;
    for(int i=1;i<nums.size();i++)//找未排序序列的最小值
    {
        if(nums[i]<nums[i-1])
        flag=true;
        if(flag==true)
        minval=min(minval,nums[i]);
    }
    flag=false;
    for(int i=nums.size()-2;i>=0;i--)//找未排序序列的最大值
    {
        if(nums[i]>nums[i+1])
        flag=true;
        if(flag==true)
        maxval=max(maxval,nums[i]);
    }
    int l;
    int r;
    for(l=0;l<nums.size();l++)//找第一个比最小值大的索引（从左向右）
    {
        if(nums[l]>minval)
        break;
    }
    for(r=nums.size()-1;r>=0;r--)//找第一个比最大值小的索引（从右向左）
    {
        if(nums[r]<maxval)
        break;
    }
    return (r>=l)?r-l+1:0;
}