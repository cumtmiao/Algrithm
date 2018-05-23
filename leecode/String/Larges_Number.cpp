/*

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
*/
/*
版本问题  在这里调试to_string()有错误，但是在LeetCode上面能正常提交。
*/
#include<bits/stdc++.h>
using namespace std;
static bool compare(int a,int b)
{
    string s1=to_string(a);
    string s2=to_string(b);
    string s1s2=s1+s2;
    string s2s1=s2+s1;
    return s1s2>s2s1;
}
string largestNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end(),compare);
    string str="";
    bool allzero=true;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=0)
        allzero=false;
        str+=to_string(nums[i]);
    }
    if(allzero==true)//如果全0的话，返回0；
    return "0";
    else
    return str;
}
int main()
{
    string str;
    int n;
    while(cin>>n)
    {
        vector<int> ve;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            ve.push_back(temp);
        }
        cout<<largestNumber(ve);
    }
    return 0;
}