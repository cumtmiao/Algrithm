/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
*/
#include<bits/stdc++.h>
using namespace std;
/*
相当于计算连乘式中因子5出现的次数.先除以5得到5的倍数的个数，再除以25得到25倍数的个数，，，以此类推。
*/
int trailingZeroes(int n) {
    int num=0;
    while(n!=0)
    {
        num+=n/5;
        n=n/5;
    }
    return num;
}