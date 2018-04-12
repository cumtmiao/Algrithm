/*
题目描述
输入n个整数，输出出现次数大于等于数组长度一半的数。
输入描述:
每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n/2。
输出描述:
输出出现次数大于等于n/2的数。
示例1
输入

3 9 3 2 5 6 7 3 2 3 3 3
输出

3
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> res;
    int tempdata;
    while(cin>>tempdata)
    res.push_back(tempdata);
    int num=1;
    int temp=res[0];//记录当前的结果
    for(int i=1;i<res.size();i++)
    {
       if(res[i]==temp)
       {
           num++;
       }
       else
       {
           num--;
       }
       if(num<0)
       {
           temp=res[i];
           num=1;
       }
    }
    cout<< temp;
    return 0;
}