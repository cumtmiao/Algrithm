/*
题目描述
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入描述:
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
输出描述:
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
示例1
输入

7 2
输出

111
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int M,N;
    while(cin>>M>>N)
    {
        stack<char> res;
        bool negtive=false;
        if(M<0)
        negtive=true;//如果是负数，negtive置为true
        M=abs(M);
        while(M!=0)
        {
        int yushu=M%N;
        if(yushu<10)
        res.push((char)(yushu+'0'));
        else
        res.push((char)('A'+yushu-10));
        M=M/N;
        }
        if(negtive==true)
        {
            cout<<'-';
        }
        while(!res.empty())
        {
            char temp;
            temp=res.top();
            res.pop();
            cout<<temp;
        }

    }
    return 0;
}