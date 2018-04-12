/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0
*/
#include<bits/stdc++.h>
using namespace std;
bool exist(vector<int> number,int length)//该函数用来判断数组中是否存在长度超过数组长度一半的元素。
{
    map<int,int> m;
    for(int i=0;i<length;i++)
    {
        m[number[i]]++;
    }
    map<int,int>::iterator it=m.begin();
    int maxval=INT_MIN;
    for(;it!=m.end();it++)
    {
        if(it->second>maxval)
        maxval=it->second;
    }
    if(maxval>(length>>1))
    return true;
    else 
    return false;

}
int MoreThanHalfNum_Solution(vector<int> numbers) {//方法一：时间复杂度为O(n)。
    if(numbers.size()==0)
    return 0;
    if(!exist(numbers,numbers.size()))
    return 0;
    int* start=&numbers[0];
    int* end=&numbers[numbers.size()-1];
    while(start<end)
    {
        if(*start!=*end)
        {
            start++;
            end--;
        }
        else
            end--;
    }
    return *start;
}
bool morethanhalfoflength(vector<int> numbers, int res)//检查当前的结果值的个数是否多于数组长度的一半
{
    int num=0;
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i]==res)
        num++;
    }
    if(num>((numbers.size())>>1))
    return true;
    else return false;
}
int MoreThanHalfNum_Solution2(vector<int> numbers)//书上的方法。
{
    if(numbers.size()==0)
    return 0;
    int res=numbers[0];
    int times=1;
    for(int i=1;i<numbers.size();i++)
    {
        if(times==0)
        {
            res=numbers[i];
            times=1;
        }
        else if(numbers[i]==res)
        times++;
        else
        times--;
    }
    
    if(morethanhalfoflength(numbers,res))
    return res;
    return 0;

}
int main()
{
    vector<int> s;
    s.push_back(4);
    s.push_back(2);
    s.push_back(1);
    s.push_back(4);
    s.push_back(2);
    s.push_back(4);
    MoreThanHalfNum_Solution2(s);
    getchar();
    return 0;
}