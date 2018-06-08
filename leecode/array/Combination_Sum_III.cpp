/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 
can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
#include<bits/stdc++.h>
using namespace std;
/*
采用DFS的思路。
*/
vector< vector<int> > res;
void dfs(int k,int n,vector<int>& temp,int index,int sum)
{
    if(temp.size()==k)
    {
        if(sum<n)
        return ;
        res.push_back(temp);
    }
    for(int i=index;i<=9&&sum+i<=n;i++)
    {
        temp.push_back(i);
        dfs(k,n,temp,i+1,sum+i);
        temp.pop_back();
    }
}
vector< vector<int> > combinationSum3(int k, int n) {
    vector<int> temp;
    dfs(k,n,temp,1,0);
    return res;
}
int main()
{
    int k,n;
    while(cin>>k>>n)
    {
        res=combinationSum3(k,n);
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
                cout<<res[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}