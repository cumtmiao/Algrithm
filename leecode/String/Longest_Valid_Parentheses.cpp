/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed)
 parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
#include<bits/stdc++.h>
using namespace std;
/*
时间复杂度o(n),空间复杂度o(1),正向反向扫描字符串
*/
int longestValidParentheses(string s) {
    int length=s.size();
    int left=0;
    int right=0;
    int maxlength=0;
    for(int i=0;i<length;i++)
    {
        if(s[i]=='(')
        left++;
        else
        right++;
        if(left==right)
        maxlength=max(maxlength,2*left);
        else if (right>left)
        {
            left=right=0;
        }
    }
    left=right=0;
    for(int i=length-1;i>=0;i--)
    {
        if(s[i]==')')
        right++;
        else
        left++;
        if(left==right)
        maxlength=max(maxlength,2*left);
        else if (left>right)
        {
            left=right=0;
        }
    }
    return maxlength;
}

/*
思路二：应用栈的思想
   1.当遇到‘（’，直接将它推入栈中
   2.当遇到‘）’，先把栈顶元素弹出，如果此时栈为空，则将当前元素入栈；当前元素的索引减去栈顶元素的索引可以更新最长的
   有效括号的长度。
时间复杂度o(n),空间复杂度o(n)
*/
int longestValidParentheses(string s) {
    int length=s.size();
    stack<int> sta;
    int maxlength=0;
    sta.push(-1);
    for(int i=0;i<length;i++)
    {
        if(s[i]=='(')
        sta.push(i);
        else
        {
            sta.pop();
            if(sta.empty())
            {
                sta.push(i);
            }
            maxlength=max(maxlength,i-sta.top());      
        }
    }
    return maxlength;
}