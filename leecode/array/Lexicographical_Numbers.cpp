/*
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/
#include<bits/stdc++.h>
using namespace std;
/*
时间复杂度O(nlogn)。
时间复杂度过大，AC：21/26.
*/
static bool compare(string a, string b)
{
    return a<b;
}
vector<int> lexicalOrder(int n) {
    vector<int> res;
    vector<string> strs;
    for(int i=1;i<=n;i++)
    {
        stringstream stream;
        stream<<i;
        strs.push_back(stream.str());
    }
    sort(strs.begin(),strs.end(),compare);
    for(int i=0;i<n;i++)
    {
        int temp;
        stringstream stream(strs[i]);
        stream>>temp;
        res.push_back(temp);
    }
    return res;
}
/*
很巧妙的一种O(n)的解法
*/
vector<int> lexicalOrder(int n) {
    vector<int> res(n);
    int cur=1;
    for(int i=0;i<n;i++)
    {
        res[i]=cur;
        if(cur*10<=n)
        cur=cur*10;
        else
        {
            if(cur>=n)
            cur=cur/10;
            cur=cur+1;
            while(cur%10==0)
            cur=cur/10;
        }
    }
    return res;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> res;
        res=lexicalOrder(n);
        for(int i=0;i<n;i++)
        {
            cout<<res[i]<<' ';
        }
    }
    return 0;
}