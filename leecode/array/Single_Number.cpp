/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


*/
#include<bits/stdc++.h>
using namespace std;
/*
考察亦或操作
*/
int singleNumber(vector<int>& nums) {
    int length=nums.size();
    int res=0;
    for(int i=0;i<length;i++)
    {
        res^=nums[i];
    }
    return res;
}