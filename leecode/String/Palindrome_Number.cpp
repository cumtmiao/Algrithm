/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward
as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:
Coud you solve it without converting the integer to a string?
*/
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int x) {
    if(x<0)
    return false;
    if(x==0)
    return true;
    int res=0;
    int origin=x;
    while(x!=0)
    {
        int yushu=x%10;
        res=res*10+yushu;
        x=x/10;
    }
    if(res==origin)
    return true;
    else
    return false;
}
int main()
{
    int number;
    while(cin>>number)
    {
        if(isPalindrome(number))
        cout<<"true";
        else
        cout<<"false";
    }
    return 0;
}