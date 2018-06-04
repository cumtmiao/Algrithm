/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
#include<bits/stdc++.h>
using namespace std;
set< vector<int> > res;
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void permutationcore(vector<int>& nums, int index)
{
    if(index==nums.size())
    {
        res.insert(nums);
        return ;
    }
    for(int i=index;i<nums.size();i++)
    {
        if (i != index && nums[i] == nums[index]) continue;
        swap(&nums[i],&nums[index]);
        permutationcore(nums,index+1);
        swap(&nums[i],&nums[index]);
    }
    return ;
}
vector< vector<int> > permuteUnique(vector<int>& nums) {
  
    permutationcore(nums,0);
    return vector< vector<int> >(res.begin(),res.end());
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> nums;
        vector < vector<int> > res1;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        res1=permuteUnique(nums);
        for(int i=0;i<res1.size();i++)
        {
            for(int j=0;j<res1[i].size();j++)
            {
                cout<<res1[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}