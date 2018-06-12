/*
There are N dominoes in a line, and we place each domino vertically upright.

In the beginning, we simultaneously push some of the dominoes either to the left or to the right.



After each second, each domino that is falling to the left pushes the adjacent domino on the left.

Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of 
the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to 
a falling or already fallen domino.

Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the 
left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not 
been pushed.

Return a string representing the final state. 

Example 1:

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
Example 2:

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Note:

0 <= N <= 10^5
String dominoes contains only 'L', 'R' and '.'
*/
#include<bits/stdc++.h>
using namespace std;
/*
维护两个指针，分别指向'L'或者'R':
左边指针指向'L',右边指针指向'R':L...R->L...R
左边指针指向'L',右边指针指向'L':L...L->LLLLL
左边指针指向'R'，右边指针指向'R':R...R->RRRRR
左边指针指向'R'，右边指针指向'L':R...L->RR.LL或者RRLL。
*/
void tianchong(string& res, int left, int right,char ch)
{
    for(int i=left;i<=right;i++)
    {
        res[i]=ch;
    }
}
void tianchongmiddle(string& res,int left, int right)
{
    while(left<right)
    {
        res[left]='R';
        res[right]='L';
        left++;
        right--;
    }
}
string pushDominoes(string dominoes) {
    string res='L'+dominoes+'R';
    int i=0;
    int j=1;
    for(;j<res.size();j++)
    {
        if(res[j]=='.')
        continue;
        if(res[i]=='L'&&res[j]=='L')
        {
            tianchong(res,i,j,'L');
        }
        else if (res[i]=='R'&&res[j]=='R')
        {
            tianchong(res,i,j,'R');
        }
        else if (res[i]=='R'&&res[j]=='L')
        {
            tianchongmiddle(res,i,j);
        }
        i=j;
    }
    return res.substr(1,res.size()-2);
}