/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > res;
void swap(int * a,int * b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void permutation(vector<int> nums,int index)//使用递归的方法。
{
    if(index==nums.size())
    {
        res.push_back(nums);
        return ;
    }
    for(int i=index;i<nums.size();i++)
    {
        swap(&nums[i],&nums[index]);
        permutation(nums,index+1);
        swap(&nums[i],&nums[index]);
    }
}
vector< vector<int> > permute(vector<int>& nums) {
    int size=nums.size();
    permutation(nums,0);
    return res;
}
int main()
{
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    permute(data);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
        {
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<0;
    return 0;
}