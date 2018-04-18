/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to
the very right. You can only see the k numbers in the window. Each time the sliding window moves right 
by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/
#include<bits/stdc++.h>
using namespace std;
/*
使用双向队列
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int length=nums.size();
    deque<int> q;
    vector<int> res;
    for(int i=0;i<length;i++)
    {
        if(q.empty()||nums[q.back()]>=nums[i])//如果当前访问的元素比队尾元素小，直接入队
        q.push_back(i);
        else//否则的话从队尾出队元素
        {
            while(!q.empty()&&nums[q.back()]<nums[i])
            q.pop_back();
            q.push_back(i);
        }
        if(i>=k-1)//当元素索引大于等于k-1的时候，输出结果值
        {
            while(i-q.front()>=k)
            q.pop_front();
            res.push_back(nums[q.front()]);
        }
    }
    return res;
}