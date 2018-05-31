/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/
#include<bits/stdc++.h>
using namespace std;
/*
最简单的思路：利用stl中的next_permutation函数求第k个排列。
*/
string getPermutation(int n, int k) {
    string s="";
    for(int i=1;i<=n;i++)
    {
        stringstream stream;
        stream<<i;
        s+=stream.str();
    }
    for(int i=0;i<k-1;i++)
    {
        next_permutation(s.begin(),s.end());
    }
    return s;
}
/*
参考网上的一个思路：
O(n)的时间复杂度
*/
string getPermutation(int n, int k) {
    string res;
    string nums="123456789";
    vector<int> f(n,1);//存储的是阶乘
    for(int i=1;i<n;i++)
    f[i]=f[i-1]*i;
    k--;
    for(int i=n;i>=1;i--)
    {
        int j=k/f[i-1];//当前元素在nums序列的第几个位置
        k=k%f[i-1];
        res.push_back(nums[j]);
        nums.erase(j,1);
    }
    return res;
}
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        cout<<getPermutation(n,k);
    }
    return 0;
}