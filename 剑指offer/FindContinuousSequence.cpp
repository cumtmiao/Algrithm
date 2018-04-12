/*
输入一个正整数S,打印出所有和为s的连续正数序列（至少含有两个数）。
例如：输入15，由于1+2+3+4+5=4+5+6=7+8=15,所以连续打印出三个连续序列1~5,4~6,7~8
*/

//基本思路：维护两个指针，当两个指针区间的和比要求的和大时，small++;
//如果比要求的和要小时，big++;
//当两个指针中间的数字之和正好等于要求的和时，输出该段数字。
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int>> res;
    int small=1;
    int big=2;
    int cursum=small+big;
    while(big<=((sum+1)>>1))
    {
        if(cursum<sum)
        {
            big++;
            cursum+=big;
        }
        else if(cursum>sum)
        {
           cursum-=small;
           small++;
        }
        else
        {
            vector<int> curres;
            for(int i=small;i<=big;i++)
            {
                curres.push_back(i);
            }
            res.push_back(curres);
            big++;
            cursum+=big;
        }
        
    }
    return res;
}