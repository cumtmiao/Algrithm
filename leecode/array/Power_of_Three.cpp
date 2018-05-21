/*
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?
*/
#include<bits/stdc++.h>
using namespace std;
//直接求log,判断是否为整数。
bool isPowerOfThree(int n) {
    return (log10(n)/log10(3))-(int)(log10(n)/log10(3))==0?true:false;
}