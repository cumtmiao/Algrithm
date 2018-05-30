/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character 
is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many 
numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and 
have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence 
exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: 
[−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN 
(−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/
#include<bits/stdc++.h>
using namespace std;
int calculatenum(string str, int l,bool negtive)
{
    long res=0;
    if(negtive==false)
    {
        while(l<str.size()&&str[l]>='0'&&str[l]<='9'&&(INT_MAX-(str[l]-'0'))/10>=res)//考虑不超过最大值
        {
            res=res*10+str[l]-'0';
            l++;
        }
        if(l==str.size()||str[l]<'0'||str[l]>'9')
        ;
        else
        res=INT_MAX;
    }
    else
    {
        while(l<str.size()&&str[l]>='0'&&str[l]<='9'&&(-(long)INT_MIN-(str[l]-'0'))/10>=res)//考虑不超过最小值
        {
            res=res*10+str[l]-'0';
            l++;
        }
        if(l==str.size()||str[l]<'0'||str[l]>'9')
        res=0-res;
        else
        res=INT_MIN;
    }
    return res;

}
int myAtoi(string str) {
    int n=str.size();
    if(n==0)
    return 0;
    int l=0;
    while(l<n&&str[l]==' ')
    l++;
    if(l==n)//空串
    return 0;
    if(str[l]!='+'&&str[l]!='-'&&(str[l]<'0'||str[l]>'9'))//字符开头
    return 0;
    bool negtive=false;
    int res=0;
    if(str[l]=='-')//负数
    {
        negtive=true;
        l++;
        res=calculatenum(str,l,true);
    }
    else if (str[l]=='+')//正数
    {
        l++;
        res=calculatenum(str,l,false);
    }
    else//正数
    {
        res=calculatenum(str,l,false);
    }
    return res;
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        cout<<myAtoi(s);
    }
    return 0;
}