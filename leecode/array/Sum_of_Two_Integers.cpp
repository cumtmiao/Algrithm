/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/
#include<bits/stdc++.h>
using namespace std;
/*
使用亦或来计算和，与操作计算进位，当进位不为0时，退出循环
*/
int getSum(int a, int b) {
    int sum=a^b;
    int carray=(a&b)<<1;
    while(carray!=0)
    {
        int x=sum;
        int y=carray;
        sum=x^y;
        carray=(x&y)<<1;
    }
    return sum;
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<< getSum(a,b);
    }
    return 0;
}