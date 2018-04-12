/*
题目描述
读入一个字符串str，输出字符串str中的连续最长的数字串
输入描述:
个测试输入包含1个测试用例，一个字符串str，长度不超过255。
输出描述:
在一行内输出str中里连续最长的数字串。
示例1
输入

abcd12345ed125ss123456789
输出

123456789
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
      cin>>str;
        int length=str.size();
        int maxlengthofnumber=0;
        string resstr;
        vector<string> res;
        for(int i=0;i<length;i++)
        {
            string tempstr="";
            while(str[i]>='0'&&str[i]<='9')
            {
                tempstr+=str[i];
                i++;
            }   
            
            if(tempstr!="")
            {
                i--;
                res.push_back(tempstr);
            }
            
        }
        for(int i=0;i<res.size();i++)
        {
            if(res[i].size()>maxlengthofnumber)
            {
                maxlengthofnumber=res[i].size();
                resstr=res[i];
            }
        }
        cout<<resstr;
    
    return 0;
}