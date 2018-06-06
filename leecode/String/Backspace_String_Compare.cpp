/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means 
a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
 

Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
*/
#include<bits/stdc++.h>
using namespace std;
bool backspaceCompare(string S, string T) {
    stack<char> s1;
    stack<char> s2;
    for(int i=0;i<S.size();i++)
    {
        if(S[i]!='#')
        s1.push(S[i]);
        else
        {
            if(!s1.empty())
            s1.pop();
        }
    }
    for(int i=0;i<T.size();i++)
    {
        if(T[i]!='#')
        s2.push(T[i]);
        else
        {
            if(!s2.empty())
            s2.pop();
        }
    }
    if(s1.size()!=s2.size())
    return false;
    for(int i=0;i<s1.size();i++)
    {
        int a=s1.top();
        int b=s2.top();
        s1.pop();
        s2.pop();
        if(a!=b)
        return false;
    }
    return true;
}
int main()
{
    string s1;
    while(getline(cin,s1))
    {
        string s2;
        getline(cin,s2);
        cout<<backspaceCompare(s1,s2);
    }
    return 0;
}