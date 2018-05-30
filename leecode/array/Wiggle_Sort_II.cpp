/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/
#include<bits/stdc++.h>
using namespace std;
/*
基本的思路：
1.首先运行partition函数找到第（n+1）/2的位置。(时间复杂度O(n),空间复杂度O(1))
2.运行类归并排序。(时间复杂度O(n),空间复杂度O(n))-->如果想将空间复杂度下降到O(1),可以运行完美洗牌算法
*/
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(vector<int>& nums,int start, int end)
{
    int index=start;
    swap(&nums[index],&nums[end]);
    int small=start-1;
    for(index=start;index<end;index++)
    {
        if(nums[index]<nums[end])
        {
            small++;
            if(small!=index)
            {
                swap(&nums[small],&nums[index]);
            }
        }
    }
    small++;
    swap(&nums[small],&nums[end]);
    return small;

}
void wiggleSort(vector<int>& nums) {
    if(nums.size()==0)
    return ;
    int n=nums.size();
    int k=(n+1)/2;//寻找第k小的数。
    int l=0;
    int r=n-1;
    int index=partition(nums,0,nums.size()-1);
    cout<<index;
    while(index!=k-1)
    {
        if(index<k-1)
        {
            l=index+1;
            index=partition(nums,l,r);
        }
        else
        {
            r=index-1;
            index=partition(nums,l,r);
        }
    }
    //步骤二：
    vector<int> res(n,0);
    int left=index;
    int right=n-1;
    int index2=0;
    while(left>=0&&right>=index+1)
    {
        res[index2]=nums[left];
        left--;
        index2++;
        res[index2]=nums[right];
        right--;
        index2++;
    }
    if(left==0)
    res[index2]=nums[0];
    for(int i=0;i<n;i++)
    {
        nums[i]=res[i];
    }
}

/*
最简单的解法：
先排序，再变换。
时间复杂度O(nlgn),空间复杂度O(n)
*/
void wiggleSort(vector<int>& nums) {
    if(nums.size()==0)
    return ;
    int n=nums.size();
    int index=(n-1)/2;//寻找第k小的数。
    sort(nums.begin(),nums.end());
    //步骤二：
    vector<int> res(n,0);
    int left=index;
    int right=n-1;
    int index2=0;
    while(left>=0&&right>=index+1)
    {
        res[index2]=nums[left];
        left--;
        index2++;
        res[index2]=nums[right];
        right--;
        index2++;
    }
    if(left==0)
    res[index2]=nums[0];
    for(int i=0;i<n;i++)
    {
        nums[i]=res[i];
    }
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
        wiggleSort(nums);
        for(int i=0;i<n;i++)
        {
            cout<<nums[i]<<' ';
        }
    }
    return 0;
}