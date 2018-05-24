/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
#include<bits/stdc++.h>
using namespace std;
/*
DFS 考察深度优先遍历
*/
vector< vector<int> > res;
void combineCore(int n,int k, int index, vector<int>& temp)
{
    temp.push_back(index);
    if(temp.size()==k)
    {
        res.push_back(temp);
        temp.pop_back();
        return ;
    }
    for(int i=index+1;i<=n;i++)
    {
        combineCore(n,k,i,temp);
    }
    temp.pop_back();

}
vector< vector<int> > combine(int n, int k) {
    vector<int> temp;
    for(int i=1;i<=n-k+1;i++)
    combineCore(n,k,i,temp);
    return res;
}
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        res=combine(n,k);
        int rows=res.size();
        int cols=res[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout<<res[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}