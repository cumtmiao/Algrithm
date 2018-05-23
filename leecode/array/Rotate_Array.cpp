/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/
#include<bits/stdc++.h>
using namespace std;
void traverse(int *left,int *right)
{
    while(left<right)
    {
        int temp;
        temp=*left;
        *left=*right;
        *right=temp;
        left++;
        right--;
    }
}
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    if(n==0)
    return;
    k=k%n;//k不能超过数组的长度。
    traverse(&nums[0],&nums[n-1]);
    traverse(&nums[0],&nums[k-1]);
    traverse(&nums[k],&nums[n-1]);
}
int main()
{
    int n;
    int k;
    while(cin>>n>>k)
    {
        vector<int> data;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            data.push_back(temp);
        }
        rotate(data,k);
        for(int i=0;i<n;i++)
        {
            cout<<data[i]<<' ';
        }
    }
    return 0;
}