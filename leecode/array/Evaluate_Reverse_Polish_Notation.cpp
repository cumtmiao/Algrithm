/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and 
there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
#include<bits/stdc++.h>
using namespace std;
bool isoperator(string str)//判断一个数是不是操作符
{
    if(str=="+"||str=="-"||str=="*"||str=="/")
    return true;
    else
    return false;
}
/*
如果遇到的一个数是操作数则进栈；
遇到操作符则：从栈中弹出两个操作数做运算，最后将结果再压人栈中。
最后返回栈顶元素即是结果。
*/
int evalRPN(vector<string>& tokens) {
    int n=tokens.size();
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(!isoperator(tokens[i]))//如果是操作数，则进栈
        {
            int temp;
            stringstream in(tokens[i]);
            in>>temp;
            s.push(temp);
        }
        else//操作符则运算
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(tokens[i]=="+")
            {
                s.push(b+a);
            }
            else if (tokens[i]=="-")
            {
                s.push(b-a);
            }
            else if (tokens[i]=="*")
            {
                s.push(a*b);
            }
            else
            {
                s.push(b/a);
            }
        }
    }
    return s.top();
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<string> data;
        for(int i=0;i<n;i++)
        {
            string tempstr;
            cin>>tempstr;
            data.push_back(tempstr);
        }
        cout<<evalRPN(data);
    }
    return 0;
}