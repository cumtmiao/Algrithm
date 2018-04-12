/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

/*
定义一种新的比较关系。
方法一：使用字符数组  比较复杂----书上的方法。
方法二：使用string 类，相对比较简单。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxnumbersize=10;
char* combine1=new char[2*maxnumbersize+1];
char* combine2=new char[2*maxnumbersize+1];
 int compare(const void * str1,const void * str2)
{
    strcpy(combine1,*(const char **)str1);
    strcat(combine1,*(const char **)str2);

    strcpy(combine2,*(const char **)str2);
    strcat(combine2,*(const char **)str1);
    return strcmp(combine1,combine2);
  
}
 string PrintMinNumber(vector<int> numbers)//书上代码，AC通不过--因为compare函数在class中使用时必须为静态函数，而它又调用了非静态函数。
 {
     int length=numbers.size();
     char** res=(char**)(new int[length]);
     for(int i=0;i<length;i++)
     {
          res[i]=new char[maxnumbersize+1];
         sprintf(res[i],"%d",numbers[i]);
     }
     qsort(res,length,sizeof(char*),compare);   
     string finalres="";
     for(int i=0;i<length;i++)
     {
         finalres+=res[i];
     }
     for(int i=0;i<length;i++)
     {
         delete[] res[i];
     }
     delete[] res;
     return finalres;
 }

static bool compare2(string & str1,string & str2)//注意此处必须是静态函数--因为在提交测试的时候是在class 中测试的
{
    string combine1=str1+str2;
    string combine2=str2+str1;
    return combine1<combine2;
}
 string PrintMinNumber(vector<int> numbers)//利用string类比较简单--AC通过。
 {
     int length=numbers.size();
     string * strnumber=new string[length];
     string res="";
     for(int i=0;i<length;i++)
     {
         stringstream stream;
         stream<<numbers[i];
         stream>>strnumber[i];
     }
     sort(strnumber,strnumber+length,compare2);
     for(int i=0;i<length;i++)
     {
         res+=strnumber[i];
     }
     delete[] strnumber;
     return res;
 }