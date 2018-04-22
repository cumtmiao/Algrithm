/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays 
whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/
#include<bits/stdc++.h>
using namespace std;
/*
O(n^2)的时间复杂度。
*/
int subarraySum(vector<int>& nums, int k) {
    int length=nums.size();
    if(length==0)
    return 0;
    int ans=0;
    for(int l=0;l<length;l++)
    {
        int sum=0;
        for(int r=l;r<length;r++)
        {
            sum+=nums[r];
            if(sum==k)
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> data;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            data.push_back(temp);
        }
        int k;
        cin>>k;
        cout<<subarraySum(data,k);
    }
    return 0;
}