/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: 
[−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result 
overflows.
*/
#include<bits/stdc++.h>
using namespace std;
/*有关数值处理的题目比较头疼，注重细节
*/
int divide(int dividend, int divisor) {
    if(dividend==INT_MIN&&divisor==-1)//考虑特殊情况
    return INT_MAX;
    bool negtive=false;
    if(dividend==0)
    return 0;
    if((dividend<0)^(divisor<0))//结果为负，记录下
    negtive=true;
    long long d=abs((long long)dividend);//将原操作数全部变为正数
    long long r=abs((long long)divisor);
    long long num=0;
    while(d>=r)//次此处比较经典。
    {
        long long t=r,p=1;
        while(d>=(t<<1))
        {
            t<<=1;
            p<<=1;
        }
        num+=p;
        d-=t;
    }
    if(negtive)
    return -num;
    else
    return num;
}