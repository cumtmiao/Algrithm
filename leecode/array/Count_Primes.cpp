/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
#include<bits/stdc++.h>
using namespace std;
bool isprim(int x)
{
    int s=(int)sqrt(x);
    for(int i=2;i<=s;i++)
    {
        if(x%i==0)
        return false;
    }
    return true;
}
int countPrimes(int n) {
    if(n<=2)
    return 0;
    if(n==3)
    return 1;
    int num=0;
    for(int i=5;i<n;i+=2)
    {
        if(isprim(i))
        {
            num++;
        }
    }
    return num+2;
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<countPrimes(n);
    }
    return 0;
}