/*

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional 
elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
#include<bits/stdc++.h>
using namespace std;
//归并排序，O(m+n)的时间，o（m）的空间
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> help;
    for(int i=0;i<m;i++)
    {
        help.push_back(nums1[i]);
    }
    int index1=0;
    int index2=0;
    int index3=0;
    while(index1<m&&index2<n)
    {
        if(help[index1]<=nums2[index2])
        {
            nums1[index3]=help[index1];
            index1++;
            index3++;
        }
        else
        {
            nums1[index3]=nums2[index2];
            index2++;
            index3++;
        }
    }
    if(index1==m)
    {
        while(index3<m+n)
        {
            nums1[index3]=nums2[index2];
            index2++;
            index3++;
        }
    }
    else if(index2==n)
    {
        while(index3<m+n)
        {
            nums1[index3]=help[index1];
            index1++;
            index3++;
        }
    }
}