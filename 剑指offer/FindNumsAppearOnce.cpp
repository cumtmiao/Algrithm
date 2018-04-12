/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/
#include<bits/stdc++.h>
using namespace std;

unsigned int lastpositionofone(int number)//判断一个数字最后一个1的位置。
{
int num=0;
while(((number&1)==0)&&(num<8*sizeof(int)))//这句话真的坑，注意！！！！括号是必须加的。符号的优先级问题！！
{
    number=number>>1;
    num++;
    
}
return num;
}

bool islastpositionofone(int number,int position)
{

    number=number>>position;

return number&1;
}
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
{
    int len=data.size();
    if(len<2)
    return;
    int res=data[0];
    for(int i=1;i<len;i++)
    {
        res=res^data[i];
    }    
    int last1=lastpositionofone(res);
   // cout<<last1;
    vector<int> nums1;
    vector<int> nums2;
    for(int i=0;i<len;i++)
    {
        if(islastpositionofone(data[i],last1))
        nums1.push_back(data[i]);
        else 
        nums2.push_back(data[i]);
    }
    int a1=nums1[0];
     for(int i=1;i<nums1.size();i++)
    {
        a1=a1^nums1[i];
    }
      int a2=nums2[0];
     for(int i=1;i<nums2.size();i++)
    {
        a2=a2^nums2[i];
    }
    *num1=a1;
    *num2=a2;
   // cout<<*num1<<' '<<*num2;
}
    int main()
    {
        vector<int> s;
        s.push_back(2);
        s.push_back(4);
        s.push_back(3);
        s.push_back(6);
        s.push_back(3);
        s.push_back(2);
        s.push_back(5);
        s.push_back(5);
        int* num1;
        int* num2;
        FindNumsAppearOnce(s,num1,num2);        
        getchar();
        return 0;
    }