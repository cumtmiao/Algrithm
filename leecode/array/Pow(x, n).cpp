/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
#include<bits/stdc++.h>
using namespace std;
// double powerCore(double x, int n)//正确
// {
//     double res=1;
//     if(n==0)
//     return 1;
//     double temp=powerCore(x,n/2);
//     if(n%2==0)
//     {
//         res=temp*temp;
//     }
//     else
//     {
//         res=temp*temp*x;
//     }
//     return res;
// }
double powerCore(double x, int n)
{
    double res=1;
    if(n==0)
    return 1;
    if(n==1)
    return x;
    if(n%2==0)
    {
        double temp=powerCore(x,n/2);
        res=temp*temp;
    }
    else
    {
        double temp=powerCore(x,n/2);
        res=temp*temp*x;
    }
    return res;
}
double myPow(double x, int n) {
    if(n==0||x==1)
    return 1.0;
    else if (n<0)
    {
        return 1/(powerCore(x,-n));
    }
    else
    return powerCore(x,n);
}
int main()
{
    double x;
    int n;
    while(cin>>x>>n)
    {
        cout<<myPow(x,n);
    }
    return 0;
}