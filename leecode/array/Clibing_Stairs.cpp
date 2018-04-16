/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.


Example 1:

Input: 2
Output:  2
Explanation:  There are two ways to climb to the top.

1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output:  3
Explanation:  There are three ways to climb to the top.

1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
#include<bits/stdc++.h>
using namespace std;
int climbStairs(int n) {//递归超时，使用循环。
    int temp1=1;
    int temp2=2;
    int temp;
    if(n==1||n==2)
    return n;
    for(int i=3;i<=n;i++)
    {
        temp=temp1+temp2;
        temp1=temp2;
        temp2=temp;
        
    }
    return temp;
}
int main()
{
    cout<<climbStairs(5);
    getchar();
    return 0;
}