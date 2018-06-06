/*
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that 
a2 + b2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:
Input: 3
Output: False
*/
#include<bits/stdc++.h>
using namespace std;
bool judgeSquareSum(int c) {
    int sqrtofc=(int)sqrt(c);
    if(sqrtofc*sqrtofc==c)
    return true;
    for(int i=1;i<=sqrtofc;i++)
    {
        int shengyu=c-i*i;
        int tempsqrt=(int)sqrt(shengyu);
        if(tempsqrt*tempsqrt==shengyu)
        return true;
    }
    return false;
}