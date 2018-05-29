/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;
/*
考虑以下特殊情况：
1.负数（需要考虑负数转化正数时存不下的情况）
2.整数部分和负数部分分别考虑
3.处理是否有循环小数
*/
string fractionToDecimal(int numerator, int denominator) {
    bool negative=false;
    if(numerator==0)
    return "0";
    if((numerator<0)^(denominator<0))
    negative=true;//判断结果是否为负数
    string res="";
    if(negative)
    res+="-";
    long long  n=numerator;//分子
    long long  d=denominator;//分母
    n=abs(n);
    d=abs(d);
    long long  zhengshu=n/d;
    stringstream stream;
    stream<<zhengshu;
    res+=stream.str();//整数部分
    long long r=n%d;//余数
    if(r==0)
    return res;
    else
    res+=".";
    unordered_map<long long ,int> m;
    while(r)//处理小数部分
    {
        if(m.find(r)!=m.end())//有循环小数的部分
        {
            res.insert(m[r],1,'(');
            res+=')';
            break;
        }
        m[r]=res.size();
        r=r*10;
        stringstream stream2;
        stream2<<r/d;
        res+=stream2.str();
        r=r%d;
    }
    return res;
}

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        string s;
        s=fractionToDecimal(a,b);
        cout<<s;
    }
    return 0;
}