/*
目描述
给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
输入描述:
输入为两行内容，第一行是正整数number，1 ≤ length(number) ≤ 50000。第二行是希望去掉的数字数量cnt:
1 ≤ cnt < length(number)。
输出描述:
输出保留下来的结果。
示例1
输入

325 1
输出

35
*/

/**
思路:从左到右找第一次出现比后面小的数，找到后s就记录下这个数的位置，然后删除
这个位置数字，例如87784201(s记录第二个7位置)，如没找到，s值就是记录最后一个
字符，这时其实是三种情况，全部相等或者从左到右递减，或者中间也可能有相等情况，
反正这时s位置记录的数字是最右边最小的 例如：
987654321(s记录1的位置)      
77777777777(s记录最后一个7的位置)  
98877777666555(s记录最后一个5的位置)
 */
#include<bits/stdc++.h>
using namespace std;
string findfirstshengxuanddelete(string number)//在字符串中找到第一个升序的位置，并且在原字符串中删除该字符
{
    int i;
    for(i=1;i<number.size();i++)
    {
        while(number[i]<=number[i-1]&&i<number.size())
        i++;
        break;
    }
    if(i==number.size())
    return number.substr(0,number.size()-1);
    else
    return number.substr(0,i-1)+number.substr(i,number.size()-i);
}
int main()
{
    string number;
    int count;
    while(cin>>number>>count)
    {
        while(count!=0)
        {
            number=findfirstshengxuanddelete(number);
            count--;
        }
        cout<<number;
    }
    return 0;
}