/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/
#include<bits/stdc++.h>
using namespace std;

 int Sum_Solution(int n)//解法一：比较巧妙的解法
 {
     int ans=n;
     ans&&(ans=ans+Sum_Solution(n-1));
     return ans;
 }

class Temp{
    public:
    Temp()
    {
        N++;
        Sum=Sum+N;
    }
    static void Reset()
    {
        N=0;
        Sum=0;
    }
    static unsigned int GetSum()
    {
        return Sum;
    }
    private:
    static unsigned int N;
    static unsigned int Sum;

};
unsigned int Temp::N=0;
unsigned int Temp::Sum=0;
 int Sum_Solution(int n)//利用构造函数来求解
 {
Temp::Reset();
Temp* a= new Temp[n];
delete[]a;
a=nullptr;
return Temp::GetSum();
 }
