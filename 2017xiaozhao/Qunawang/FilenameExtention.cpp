/*
题目描述
Please create a function to extract the filename extension from the given path,
return the extracted filename extension or null if none.
输入描述:
输入数据为一个文件路径
输出描述:
对于每个测试实例，要求输出对应的filename extension
示例1
输入

Abc/file.txt
输出

txt

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int i;
    int flag=0;
    for(i=0;i<str.size();i++)
    {
        if(str[i]=='.')
        {
            flag=1;
            i++;
            while(str[i]!='\0')
            {
                cout<<str[i];
                i++;
            }
            break;
        }
    }
    if(flag==0)
    cout<<"null";
    //cout<<1;
    return 0;
}