/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
*/
/*
本题目的目的本质是将十进制数转换为26进制数。
*/
#include<bits/stdc++.h>
using namespace std;
//相当于前面的那个题目的变形。但是与传统的十进制转换二十六进制不同，有一些trick，比如每一次计算余数之前先将n-赋值给n。当n==0时退出循环。
string convertToTitle(int n) {
    stack<int> s;
    string str="";
    n=n-1;
    while(true)
    {
        int yushu=n%26;
        s.push(yushu);
        n=n/26;
        if(n==0)
        break;
        else
        n=n-1;
    }
    while(!s.empty())
    {
        int temp=s.top();
        s.pop();
        str+=(char)('A'+temp);
    }
    return str;
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<convertToTitle(n);
    }
    return 0;
}