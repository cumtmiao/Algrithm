/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/
#include<bits/stdc++.h>
using namespace std;

double Power(double base, int exponent)//递归.
{
    if(base==0)
    return 0.0;
    if(exponent==0)
    return 1.0;
    if(exponent==1)
    return base;
    if(exponent>0)
    return base*Power(base,exponent-1);
    else
    return 1/(Power(base,-exponent));
}

double Power1(double base, int exponent)
{
    if(exponent==0)
    return 1;
    double res=1.0;
    for(int i=0;i<abs(exponent);i++)
    {
        res=res*base;
    }
    if(exponent>0)
    return res;
    else
    return 1/(res);
}