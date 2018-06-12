/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all 
array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/
#include<bits/stdc++.h>
using namespace std;
/*
相当于最后数组中的所有元素全部变为最小的元素值需要的步数。
时间复杂度为O(n)
*/
int minMoves(vector<int>& nums) {
    int n=nums.size();
    if(n<=1)
    return 0;
    //sort(nums.begin(),nums.end());
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(nums[i]<min)
        min=nums[i];
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        res+=nums[i]-min;
    }
    return res;
}