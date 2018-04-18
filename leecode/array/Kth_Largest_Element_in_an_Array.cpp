/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted 
order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include<bits/stdc++.h>
using namespace std;
/*
直接应用STL sort函数
*/
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    return nums[nums.size()-k];
}
/*
利用最小堆。
*/
int findKthLargest(vector<int>& nums, int k)
{
    vector<int> heap;
    for(int i=0;i<k;i++)
    {
        heap.push_back(nums[i]);
        push_heap(heap.begin(),heap.end(),greater<int>());
    }
    for(int i=k;i<nums.size();i++)
    {
        if(nums[i]>heap[0])
        {
            pop_heap(heap.begin(),heap.end(),greater<int>());
            heap.pop_back();
            heap.push_back(nums[i]);
            push_heap(heap.begin(),heap.end(),greater<int>());
        }
    }
    return heap[0];
}