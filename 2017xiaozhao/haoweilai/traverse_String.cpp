/*
题目描述
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
输入描述:
每个测试输入包含1个测试用例： I like beijing. 输入用例长度不超过100
输出描述:
依次输出倒置之后的字符串,以空格分割
示例1
输入

I like beijing.
输出

beijing. like I
*/
#include<bits/stdc++.h>
using namespace std;
void swap(char* start,char* end)//翻转一个字符串
{
    while(start<end)
    {
        char temp;
        temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
}
int main()
{
    string str;
    while(getline(cin,str))
    {
        int length=str.size();
        swap(&str[0],&str[length-1]);
        int start=0;
        int end=0;
        while(true)
        {
            while(str[end]!=' '&&str[end]!='\0')
            end++;
            if(start!=end)
            swap(&str[start],&str[--end]);
            end++;
            start=end;
            if(str[start]=='\0')
            break;
        }
        cout<<str;
    }
    return 0;

}