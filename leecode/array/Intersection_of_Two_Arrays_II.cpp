/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
*/
#include<bits/stdc++.h>
using namespace std;
/*
使用map O(n^2)的时间复杂度
*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> m1;
    map<int, int> m2;
    vector<int> res;
    for(int i=0;i<nums1.size();i++)
    {
        m1[nums1[i]]++;
    }
    for(int i=0;i<nums2.size();i++)
    {
        m2[nums2[i]]++;
    }
    map<int,int>::iterator it1=m1.begin();
    map<int,int>::iterator it2=m2.begin();
    for(;it1!=m1.end();it1++)
    {
        for(it2=m2.begin();it2!=m2.end();it2++)
        {
            if(it1->first==it2->first)
            {
                int minval=min(it1->second,it2->second);
                for(int i=0;i<minval;i++)
                {
                    res.push_back(it1->first);
                }
            }
        }
    }
    return res;
}
/*
思路二：先排序再扫描 O(nlgn)的时间复杂度
*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int traverse1=0;
    int traverse2=0;
    vector<int> res;
    while(traverse1<n1&&traverse2<n2)
    {
        if(nums1[traverse1]<nums2[traverse2])
        traverse1++;
        else if (nums1[traverse1]>nums2[traverse2])
        {
            traverse2++;
        }
        else
        {
            res.push_back(nums1[traverse1]);
            traverse1++;
            traverse2++;
        }
    }
    return res;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> nums1;
        vector<int> nums2;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            nums1.push_back(temp);
        }
        for(int i=0;i<m;i++)
        {
            int temp;
            cin>>temp;
            nums2.push_back(temp);
        }
        res=intersect(nums1,nums2);
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<endl;
        }
    }
    return 0;
}