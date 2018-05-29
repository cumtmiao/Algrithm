/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
#include<bits/stdc++.h>
using namespace std;
/*
中缀表达式变后缀表达式。
如果遇到数字则直接跟在后缀表达式后面；
如果遇到运算符，则将优先级大于等于它的运算符出栈，再将当前访问的运算符入栈。
*/
int calculate(string s) {
    vector<string> ve;
    int size=s.size();
    int start=0;
    int end=0;
    string str="";
    stack<string> sta;//存储运算符
    stack<int> res;//存储结果
    for(int i=0;i<size;i++)//去除空格
    {
        if(s[i]==' ')
        continue;
        str+=s[i];
    }
    while(end<str.size())//将字符串切分，分别将运算符和运算数按照后缀表达式放进vector中
    {
        if(str[end]>='0'&&str[end]<='9')
        end++;
        else{
            ve.push_back(str.substr(start,end-start));
            if(str[end]=='*'||str[end]=='/')
            {
                while(!sta.empty()&&(sta.top()=="*"||sta.top()=="/"))
               {
                string temp=sta.top();
                sta.pop();
                ve.push_back(temp);
               }
               if(str[end]=='*')
               sta.push("*");
               else
               sta.push("/");
            }
            else
            {
                while(!sta.empty())
                {
                    string temp=sta.top();
                    sta.pop();
                    ve.push_back(temp);
                }
               if(str[end]=='+')
               sta.push("+");
               else
               sta.push("-");
            }
            end++;
            start=end;
        }
    }
    ve.push_back(str.substr(start,end-start));
    while(!sta.empty())
    {
        ve.push_back(sta.top());
        sta.pop();
    }
    for(int i=0;i<ve.size();i++)
    {
        if(ve[i]!="+"&&ve[i]!="-"&&ve[i]!="*"&&ve[i]!="/")
        {
            int tempint;
            stringstream in(ve[i]);
            in>>tempint;
            res.push(tempint);
        }
        else if(ve[i]=="+")
        {
            int a=res.top();
            res.pop();
            int b=res.top();
            res.pop();
            res.push(a+b);
        }
        else if(ve[i]=="-")
        {
            int a=res.top();
            res.pop();
            int b=res.top();
            res.pop();
            res.push(b-a);
        }
        else if (ve[i]=="*")
        {
            int a=res.top();
            res.pop();
            int b=res.top();
            res.pop();
            res.push(a*b);
        }
        else
        {
            int a=res.top();
            res.pop();
            int b=res.top();
            res.pop();
            res.push(b/a);
        }
    }
    return res.top();
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        cout<<calculate(s);
    }
    return 0;
}