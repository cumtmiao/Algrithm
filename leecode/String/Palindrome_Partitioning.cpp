/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/
#include<bits/stdc++.h>
using namespace std;
//DFS
vector< vector<string> > res;
bool ispalindrome(string str)
{
    int s=str.size();
    int left=0;
    int right=s-1;
    while(left<right)
    {
        if(str[left]!=str[right])
        return false;
        left++;
        right--;
    }
    return true;
}
void partitionCore(string s,int index,vector<string>& temp)
{
    if(index==s.size())
    {
        res.push_back(temp);
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        if(ispalindrome(s.substr(index,i-index+1)))
        {
            temp.push_back(s.substr(index,i-index+1));
            partitionCore(s,i+1,temp);
            temp.pop_back();
        }
    }
}
vector< vector<string> > partition(string s) {
    vector<string> temp;
    partitionCore(s,0,temp);
    return res;
}
int main()
{
    string s;
    while(cin>>s)
    {
        partition(s);
        int rows=res.size();
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
                cout<<res[i][j]<<' ';
            }
        }
        
    }
    return 0;
}