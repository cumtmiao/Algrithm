/*
快排算法。
*/
#include<bits/stdc++.h>
using namespace std;
void Swap(int* a,int* b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int Partition(int* data, int length,int start,int end)//实现快排的一轮，返回data[index]的下标。
{
    //异常处理，剑指offer 80页。
    int index=start;//本步骤应该是随机产生索引，为了方便起见，以第start个元素位置为索引
    Swap(&data[index],&data[end]);
    int small=start-1;
    for(index=start;index<end;index++)
    {
        if(data[index]<data[end])
        {
            small++;
            if(small!=index)
            {
                Swap(&data[small],&data[index]);
            }
        }
    }
    small++;
    Swap(&data[small],&data[end]);
    return small;
}
void QuickSort(int* data, int length, int start,int end)
{
    if(start==end)
    return ;
    int index=Partition(data,length,start,end);
    if(index>start)
    QuickSort(data,length,start,index-1);//递归index左半部分
    if(index<end)
    QuickSort(data,length,index+1,end);//递归index右半部分。
}

int main()
{
    int s[5]={1,5,2,2,7};
    QuickSort(s,5,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<s[i]<<' ';
    }
    getchar();
    return 0;
}