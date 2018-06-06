/*
Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain.

Example 1:

Input: [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
Example 2:

Input: [2,2,2]
Output: 0
Explanation: There is no mountain.
 

Note:

0 <= A.length <= 10000
0 <= A[i] <= 10000
*/
#include<bits/stdc++.h>
using namespace std;
/*
每一个元素分别向左向右扩展，可得到当前节点下的山峰的长度
250ms
*/
int longestMountain(vector<int>& A) {
    int res=0;
    if(A.size()<3)
    return 0;
    for(int i=1;i<A.size()-1;i++)
    {
        int left=i-1;
        int right=i+1;
        int cur=A[i];
        int num1=0;
        int num2=0;
        while(left>=0&&A[left]<cur)
        {
            num1++;
            cur=A[left];
            left--;
        }
        cur=A[i];
        while(right<A.size()&&A[right]<cur)
        {
            num2++;
            cur=A[right];
            right++;
        }
        if(num1>0&&num2>0)
        res=max(res,num1+num2+1);
    }
    return res;
}
/*
使用动态规划的方法
25ms
*/
int longestMountain(vector<int>& A) {
    int res=0;
    if(A.size()<3)
    return 0;
    vector<int> forward(A.size(),0);//farward[i]表示以i结尾的最长递增子序列的长度
    vector<int> backward(A.size(),0);
    int num=0;
    for(int i=0;i<A.size();i++)//更新forward数组
    {
        if(i==0||A[i]<=A[i-1])
        {
            forward[i]=1;
            num=1;
        }
        else
        {
            num++;
            forward[i]=num;
        }
    }
    for(int i=A.size()-1;i>=0;i--)//更新backward数组
    {
        if(i==A.size()-1||A[i]<=A[i+1])
        {
            num=1;
            backward[i]=num;
        }
        else
        {
            num++;
            backward[i]=num;
        }
    }
    for(int i=0;i<A.size();i++)//计算结果
    {
        if(forward[i]>1&&backward[i]>1)
        res=max(res,forward[i]+backward[i]-1);
    }
    return res;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> nums;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        cout<<longestMountain(nums);
    }
    return 0;
}