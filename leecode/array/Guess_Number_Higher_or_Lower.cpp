/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
*/
#include<bits/stdc++.h>
using namespace std;
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);
/*
二分法。
*/
class Solution {
public:
    int guessNumber(int n) {
        int l=1;
        int h=n;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(guess(mid)==-1)
               h=mid-1;
            else if (guess(mid)==1)
            { 
                l=mid+1;
            }
            else
                return mid;
        }
        return l;
    }
};
