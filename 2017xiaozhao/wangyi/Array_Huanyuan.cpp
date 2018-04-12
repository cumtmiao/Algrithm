/*
题目描述
牛牛的作业薄上有一个长度为 n 的排列 A，这个排列包含了从1到n的n个数，但是因为一些原因，
其中有一些位置（不超过 10 个）看不清了，但是牛牛记得这个数列顺序对的数量是 k，
顺序对是指满足 i < j 且 A[i] < A[j] 的对数，请帮助牛牛计算出，符合这个要求的合法排列的数目。
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个整数 n 和 k（1 <= n <= 100, 0 <= k <= 1000000000），
接下来的 1 行，包含 n 个数字表示排列 A，其中等于0的项表示看不清的位置（不超过 10 个）。
输出描述:
输出一行表示合法的排列数目。
示例1
输入

5 5
4 0 0 2 0
输出

2
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int k;
const int maxn=102;
int data[maxn];//原始数据。
int miss[12];//缺失的数据。
int recontruct[maxn];//重构的数据。

int numberofpairsmix()//计算重构数组中的顺序对的个数
{
    int num=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(recontruct[i]<recontruct[j])
            num++;
        }
    }
    return num;
}
int main()
{
    cin>>n;
    cin>>k;
    vector<int> tempve;//用来筛选缺失的数字
    for(int i=0;i<n;i++)//得到原始的输入数组
    {
        int temp;
        cin>>temp;
        data[i]=temp;
        tempve.push_back(i+1);
    }
    for(int i=0;i<n;i++)
    {
        if(data[i]!=0)
        tempve.erase(remove(tempve.begin(),tempve.end(),data[i]),tempve.end()); 
    }
    vector<int>::iterator it=tempve.begin();
    int lengthofmiss=0;//缺失数组的长度
    for(int i=0;it!=tempve.end();i++,it++)
    {
        miss[i]=*it;
        lengthofmiss++;
    }

    int numberofmix=0;//重构数组中的顺序对数
    int res=0;//最终结果，满足条件的排列个数
    do{
       
        for(int i=0,j=0;i<n;i++)//构建recontruct数组。
        {
            if(data[i]!=0)
            recontruct[i]=data[i];
            else
            {
                recontruct[i]=miss[j];
                j++;
            }
        }
        numberofmix=numberofpairsmix();
        if(numberofmix==k)
        res++;
    }while(next_permutation(miss,miss+lengthofmiss));
    cout<<res;
    return 0;

}
