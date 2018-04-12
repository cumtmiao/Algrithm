/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/
#include<bits/stdc++.h>
using namespace std;
//当不能使用四则运算来计算两个数的和时,我们考虑使用位运算。
/*
1.不考虑进位相加，相当于两个数的异或；
2.考虑进位，相当于两个数进行与运算后左移一位的结果；
3.知道不产生进位为止。
*/
int Add(int num1, int num2)
{
    int value1=num1^num2;//步骤一
    int value2=(num1&num2)<<1;//步骤二
    while(value2!=0)//步骤三
    {
        int sum=value1^value2;
        int carray=(value1&value2)<<1;
        value1=sum;
        value2=carray;
    }
    return value1;
}
int main()
{
    cout<<Add(111,899);
    getchar();
    return 0;
}
