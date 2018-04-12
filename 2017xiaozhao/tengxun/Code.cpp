/*
题目描述
假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下：
 a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 
 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 
 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
输入描述:
输入一个待编码的字符串,字符串长度小于等于100.
输出描述:
输出这个编码的index
示例1
输入

baca
输出

16331
*/
/*
分析编码的内在规律。
参考：https://www.nowcoder.com/profile/4308470/codeBookDetail?submissionId=13206616
*/
#include<bits/stdc++.h>
using namespace std;
int index(string str)
{
    int length=str.size();
    int res=0;
    int base[4];
    base[3]=1;
    for(int i=2;i>=0;i--)
    {
        base[i]=base[i+1]*25+1;
    }
    for(int i=0;i<length;i++)
    {
        res+=(str[i]-'a')*base[i]+1;
    }
    return res-1;
}
int main()
{
    string str;
    while(cin>>str)
    {
        int length=str.size();
        for(int i=0;i<length;)
        {
            string substr=str.substr(i,min(4,length-i));
            cout<<index(substr);
            i+=min(4,length-i);
        }
    }
    return 0;
}