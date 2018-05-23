/*

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the 
array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: [1,2,3,1], k = 3
Output: true
Example 2:

Input: [1,0,1,1], k = 1
Output: true
Example 3:

Input: [1,2,1], k = 0
Output: false
*/
#include<bits/stdc++.h>
using namespace std;
//暴力方法：超时。21/23
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(nums[i]==nums[j])
            return true;
        }
    }
    return false;
}
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    int n=nums.size();
    map<int,int> m;//存储的是元素值<->元素下标
    for(int i=0;i<n;i++)
    {
        if(m.count(nums[i])==1)//某个元素已经在hash表中有值了，判断新来的值与原来值的索引之间的距离差
        {
            if(i-m[nums[i]]<=k)
            return true;
            else
            m[nums[i]]=i;
        }
        else
        m[nums[i]]=i;
    }
    return false;
    
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> data;
        int k;
        cin>>k;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            data.push_back(temp);
        }
        cout<<containsNearbyDuplicate(data,k);
    }
    return 0;
}