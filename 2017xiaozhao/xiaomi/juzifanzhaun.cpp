/*
题目描述
给定一个句子（只包含字母和空格）， 将句子中的单词位置反转，单词用空格分割, 单词之间只有一个空格，前后没有空格。 
比如： （1） “hello xiao mi”-> “mi xiao hello”
输入描述:
输入数据有多组，每组占一行，包含一个句子(句子长度小于1000个字符)
输出描述:
对于每个测试示例，要求输出句子中单词反转后形成的句子
示例1
输入

hello xiao mi
输出

mi xiao hello
*/

/*
思路：三步反转法：
1.句子整体反转。
2.得到反转后句子中的每一个单词，并且反转。
3.输出结果
*/
#include<bits/stdc++.h>
using namespace std;
void traverse(char * start,char *end)
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
        vector<string> res;
        traverse(&str[0],&str[str.size()-1]);
        for(int i=0;i<length;i++)
        {
            string temp="";
            while(str[i]!=' '&&str[i]!='\0')
            {
                temp+=str[i];
                i++;
            }
            if(temp!="")
            {
                traverse(&temp[0],&temp[temp.size()-1]);
                res.push_back(temp);
            }
        }
        for(int i=0;i<res.size();i++)
        {
            if(i!=res.size()-1)
            cout<<res[i]<<' ';
            else
            cout<<res[i];
        }
    }
    return 0;
}