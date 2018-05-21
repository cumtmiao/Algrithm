/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.   
*/
#include<bits/stdc++.h>
using namespace std;  
/*
要求O(n)的时间复杂度，O(1)的空间复杂度。
*/  
bool increasingTriplet(vector<int>& nums) {
    int length=nums.size();
    if(length<3)
    return false;
    int m1=INT_MAX;//m1表示当前访问到的最小的元素
    int m2=INT_MAX;//m2表示当前访问到的次小的元素
    for(int i=0;i<length;i++)
    {
        if(nums[i]<=m1)
            m1=nums[i];
        else if (nums[i]<=m2)//只要m2被更新过，即表示当前能够构成一个a<b的二元组
        {
            m2=nums[i];
        }
        else 
         return true;
    }
    return false;
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
        cout<<increasingTriplet(data);
    }
    return 0;

}
