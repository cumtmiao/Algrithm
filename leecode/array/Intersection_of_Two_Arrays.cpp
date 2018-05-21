/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/
#include<bits/stdc++.h>
using namespace std;
/*
O(n^2)时间复杂度。O(n)的空间
*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    vector<int> res;
    set<int> temp;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(nums1[i]==nums2[j])
            temp.insert(nums1[i]);
        }
    }
    set<int>::iterator it=temp.begin();
    for(;it!=temp.end();it++)
    {
        res.push_back(*it);
    }
    return res;
}
