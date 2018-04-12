/*
从扑克牌中随机抽取5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2~10为数字本身，
A为1，J为11，Q为12，K为13，而大，小王可以看成任意数字。
*/
/*
思路：
1.先将数组进行排序；
2.统计数组中0的个数；
3.统计数组中Gap的个数；
4.如果数组中有两个数相等，则输出false;
5.Gap个数小于o的个数时，输出true;
*/
#include<bits/stdc++.h>
using namespace std;
bool IsContinuous( vector<int> numbers ) {
    int length=numbers.size();
    if(length==0)
    return false;
    sort(numbers.begin(),numbers.end());
    int numberofZero=0;
    int numberofGap=0;
    for(int i=0;i<length;i++)
    {
        if(numbers[i]==0)
        numberofZero++;
        else
        break;
    }
    for(int i=numberofZero;i<length;i++)
    {
        if(i+1<length)
        {
            if(numbers[i]==numbers[i+1])
            return false;
            else 
            numberofGap+=numbers[i+1]-numbers[i]-1;
        }
    }
    if(numberofGap<=numberofZero)
    return true;
    return false;
}