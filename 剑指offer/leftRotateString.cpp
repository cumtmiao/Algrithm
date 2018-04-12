/*
汇编语言中有一种移位指令叫做循环左移（ROL），
现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/
#include<bits/stdc++.h>
using namespace std;

void rotate(char* start, char* end)
    {
        char temp;
        while(start<end)
        {
            temp=*start;
            *start=*end;
            *end=temp;
            start++;
            end--;
        }
    }
  string LeftRotateString(string str, int n) {
        if(str=="")
            return str;
        int s=str.size();
        char* start=(char*)str.c_str();
        //rotate(start,&start[n-1]);
       // rotate(&start[n],&start[s-1]);
       // rotate(start,&start[s-1]);
       rotate(start,start+n-1);
       rotate(start+n,start+s-1);
       rotate(start,start+s-1);
        return start;
    }
    
    

    int main()
    {
        string S="XYZdefabc";
        cout<<LeftRotateString(S,3);
       //cout<<1;
        getchar();
        return 0;
    }