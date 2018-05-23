/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 
(where it will stay), or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
#include<bits/stdc++.h>
using namespace std;
/*
使用set，如果某个元素在集合中已经出现过，则表示陷入循环，返回false;
若没有进入循环，并且出现1则返回true；
*/
bool isHappy(int n) {
    set<int> se;
    int sum;
    while(true)
    {
        sum=0;
        while(n!=0)
        {
            int yushu=n%10;
            sum+=yushu*yushu;
            n=n/10;
        }
        if(sum==1)
        return true;
        if(se.find(sum)==se.end())
        {
            se.insert(sum);
            n=sum;
        }
        else
        break;
    }
    return false;

}