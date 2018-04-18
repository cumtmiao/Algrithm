/*
Given an array of size n, find the majority element. The majority element is the element that appears more 
than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
#include<bits/stdc++.h>
using namespace std;
/*
时间复杂度O(n);
空间复杂度O(1);
*/
int majorityElement(vector<int>& nums) {
    int ans=nums[0];
    int num=1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]==ans)
        num++;
        else
        {
            num--;
            if(num<0)
            {
                ans=nums[i];
                num=1;
            }
        }
    }
    return ans;
}