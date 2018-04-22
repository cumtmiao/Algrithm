/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are 
different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/
#include<bits/stdc++.h>
using namespace std;
int numberof1(int x)//求一个数二进制表示中1的个数
{
    int num=0;
    while(x!=0)
    {
        x=x&(x-1);
        num++;
    }
    return num;
}
int hammingDistance(int x, int y) {
    return numberof1(x^y);
}
int main()
{
    cout<<hammingDistance(1,4)<<endl;
    cout<<1;
    getchar();
    return 0;
}