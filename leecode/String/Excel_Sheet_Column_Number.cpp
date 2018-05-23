/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
*/
#include<bits/stdc++.h>
using namespace std;
/*
相当于26进制向10进制的转换
*/
int titleToNumber(string s) {
    int n=s.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum*26+(s[i]-'A')+1;
    }
    return sum;
}
int main()
{
    string s;
    while(cin>>s)
    {
        cout<<titleToNumber(s);
    }
    return 0;
}