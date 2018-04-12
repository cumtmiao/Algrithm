/*
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*/


/*
思路解析：见
http://blog.csdn.net/yi_afly/article/details/52012593
该解题方式比剑指offer书上的解题方式更有逻辑性和易于理解。
*/
#include<bits/stdc++.h>
using namespce std;
int NumberOf1Between1AndN_Solution(int n)
{
    if(n<1)
    return 0;
    int weight=0;
    int res=0;
    int round=n;
    int base=1;
    while(round!=0)
    {
        weight=round%10;
        round=round/10;
        res+=round*base;
        if(weight>1)
        res+=base;
        if(weight==1)
        res+=(n%base)+1;
        base*=10;
    }
    return res;
}