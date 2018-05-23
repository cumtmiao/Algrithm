/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false 
if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/
#include<bits/stdc++.h>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
    map<int ,int> m;
    for(int i=0;i<nums.size();i++)
    {
        m[nums[i]]++;
    }
    map<int,int>::iterator it=m.begin();
    for(;it!=m.end();it++)
    {
        if(it->second!=1)
        return true;
    }
    return false;
}