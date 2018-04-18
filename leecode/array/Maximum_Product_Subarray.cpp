/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
#include<bits/stdc++.h>
using namespace std;
/*
使用动态规划算法：时间复杂度为O(n),空间复杂度为O(1);
*/
int maxProduct(vector<int>& nums) {
    int length=nums.size();
    if(length==0)
    return 0;
    int tempminbefore=1;
    int tempmaxbefore=1;
    int res=INT_MIN;
    for(int i=0;i<length;i++)
    {

        int tempmaxafter=max(max(tempmaxbefore*nums[i],tempminbefore*nums[i]),nums[i]);
        int tempminafter=min(min(tempmaxbefore*nums[i],tempminbefore*nums[i]),nums[i]);
        res=max(tempmaxafter,res);
        tempminbefore=tempminafter;
        tempmaxbefore=tempmaxafter;
    }
    return res;
}