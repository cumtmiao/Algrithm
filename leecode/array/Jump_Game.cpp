/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
#include<bits/stdc++.h>
using namespace std;
/*
动态规划的方法：定义一个数组status[];status[i]表示从位置i是否可以到达末尾。如果为1表示能够到达；
              如果为0，表示不能到达。
时间复杂度O(n^2)；
空间复杂度O(n)
*/
bool canJump(vector<int>& nums)
{
    int size=nums.size();
    int status[size];//表示每个位置的状态，即每个位置是不是可以到达末尾。
    memset(status,0,sizeof(status));
    status[size-1]=1;
    for(int i=size-2;i>=0;i--)
    {
        int minstep=min(size-1,i+nums[i]);//获取从i位置最多能够到达的范围
        for(int j=i+1;j<=minstep;j++)//如果范围内有一个可以到达，则i可以到达    
        {
            if(status[j]==1)
            {
                status[i]=1;
                break;
            }
        }
    }
    return status[0]==1;
}
/*
贪心算法：
时间复杂度O(n);
空间复杂度O(1);
思路，每个节点只要能够到达距离它最近的“good”节点，那么它就是一个good节点。
*/
bool canJump(vector<int>& nums)
{
    int size=nums.size();
    int lastpos=size-1;
    for(int i=size-2;i>=0;i--)
    {
        if(i+nums[i]>=lastpos)
        lastpos=i;
    }
    return lastpos==0;//表示位置0为可以到达末尾的good节点。
}
