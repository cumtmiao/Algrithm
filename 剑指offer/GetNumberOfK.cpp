/*
统计一个数字在排序数组中出现的次数。
*/
#include<bits/stdc++.h>
using namespace std;
//二分查找
int GetNumberOfK(vector<int> data ,int k) {
    int length=data.size();
    if(length==0)
    return 0;
    int left=0;
    int right=length-1;
    int numleft=0;
    int numright=0;
    while(left<=right)
    {
        int mid=(left+right)>>1;
        if(data[mid]<k)
        left=mid+1;
        else if(data[mid]>k)
        right=mid-1;
        else{//解法一的不足：当找到一个数字等于k时，顺序查找其余的数，有可能导致仍是o(n)的时间复杂度。
            for(int i=mid;i>=left;i--)
            {
                if(data[i]==k)numleft++;
                else break;
            }
            for(int i=mid+1;i<=right;i++)
            {
                if(data[i]==k)numright++;
                else break;
            }
            break;
        }
    }
    return numleft+numright;
}

//解法二：先用二分查找找到第一个k的位置O（lgn）；再用二分查找找到最后一个k的位置，最后返回k出现的次数。总的时间复杂度是O（lgn）
//具体方法见《剑指offer》263页。