/*
Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence 
[123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
F.length >= 3;
and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, 
except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:

Input: "123456579"
Output: [123,456,579]
Example 2:

Input: "11235813"
Output: [1,1,2,3,5,8,13]
Example 3:

Input: "112358130"
Output: []
Explanation: The task is impossible.
Example 4:

Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
Example 5:

Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.
*/
#include<bits/stdc++.h>
using namespace std;
/*
测试通过。23ms
应用DFS的思想
*/
vector<int> res;
bool isvalid(string s)
{
    if(s.size()>1&&s[0]=='0')
    return false;
    return true;
}
bool splitIntoFibonaccicore(string s,int index)
{
    int n=s.size();
    int first=res[res.size()-2];
    int second=res[res.size()-1];
    int tempsum=first+second;
    bool find=false;
    if(index==s.size())
    {
        find=true;
        return find;
    }
    for(int i=index;i<s.size();i++)
    {
        if(!isvalid(s.substr(index,i-index+1)))
        break;
        stringstream stream(s.substr(index,i-index+1));
        long long sum;
        stream>>sum;
        if(sum>INT_MAX)
        break;
        if(sum==tempsum)
        {
            res.push_back(sum);
            find=splitIntoFibonaccicore(s,i+1);
            if(find)
            return true;
            res.pop_back();
        }
        else if (sum>tempsum)
        {
            break;
        }
    }
    return find;
}
vector<int> splitIntoFibonacci(string S) {
    int n=S.size();
    if(n<3)
    return res;
    bool find=false;//记录当前是否找到一个结果
    for(int i=0;i<=n-3;i++)
    {
        if(!isvalid(S.substr(0,i+1)))//判断当前字符串是否有效，即是否以‘0’开头
        break;
        for(int j=i+1;j<=n-2;j++)
        {

            stringstream stream(S.substr(0,i+1));
            long long a;
            stream>>a;
            if(a>INT_MAX)//如果当前字符串超出整数的范围，则break
            break;
            if(!isvalid(S.substr(i+1,j-i)))
            break;
            stringstream stream1(S.substr(i+1,j-i));
            long long b;
            stream1>>b; 
            if(b>INT_MAX) 
            break;
            res.push_back(a);
            res.push_back(b);
            find=splitIntoFibonaccicore(S,j+1);
            if(find)
            return res;
            res.pop_back();
            res.pop_back();
                
        }
    }
    return res;
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        vector<int> res;
        res=splitIntoFibonacci(s);
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<' ';
        }
    }
    return 0;
}