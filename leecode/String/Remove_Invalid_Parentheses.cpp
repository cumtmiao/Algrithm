/*
Remove the minimum number of invalid parentheses in order to make the input string valid. 
Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/
/*
本题目很难，尽管参考答案了，也是debug之后才理解，，，，基本写不出来。

*/
#include<bits/stdc++.h>
using namespace std;
char p[2]={'(',')'};//检测右括号是否是多余的
char p_re[2]={')','('};//检测左括号是否多余
void reverse(char * start,char* end)//字符串翻转
{
    while(start<end)
    {
        char temp;
        temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
}
void dfs(string s, int last_i,int last_j,char *p,vector<string> &res)
{
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==p[0])
        count++;
        else if(s[i]==p[1])
        count--;
        else
        ;
        if(count>=0)
        continue;
        //直到我们找到有且仅有产生一个括号多余的情况
        for(int j=last_j;j<=i;j++)
        {
            //前面的任意一个括号都可以去掉，如果有多个连续，则默认去掉第一个
            if(s[j]==p[1]&&(j==last_j||s[j]!=s[j-1]))
            {
                dfs(s.substr(0,j)+s.substr(j+1),i,j,p,res);
            }
        }
        return ;
    }
    //翻转字符串，如果"检测左括号是否多余的情况"如果已经进行过，则直接输出结果，否则进行左括号检测。
    reverse(&s[0],&s[s.size()-1]);
    if(p[0]=='(')
    dfs(s,0,0,p_re,res);
    else
    res.push_back(s);
}
vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    dfs(s,0,0,p,res);
    return res;
}