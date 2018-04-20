/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
#include<bits/stdc++.h>
using namespace std;

 bool cmp(const pair<int,int> &p1,const pair<int,int> &p2)
{
    return p1.second>p2.second;
}
/*
基本思路：
先将nums中的元素按照<元素,数量>的方式存储到hash表中，然后转换到vector<pair<int,int>>中，再对上述pair按照第二个元素
进行排序，按需输出即可。
*/
class Solution {
public:

vector<int> topKFrequent(vector<int>& nums, int k) {
    int length=nums.size();
    map<int,int> m;
    vector<int> res;
    for(int i=0;i<length;i++)
    {
        m[nums[i]]++;
    }
    vector<pair<int,int>> p;
    map<int,int>::iterator it=m.begin();
    for(;it!=m.end();it++)
    {
        p.push_back(make_pair(it->first,it->second));
    }
    sort(p.begin(),p.end(),cmp);
    for(int i=0;i<k;i++)
    {
        res.push_back(p[i].first);
    }
    return res;
}
};