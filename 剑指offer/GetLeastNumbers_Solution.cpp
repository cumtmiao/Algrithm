/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
#include<bits/stdc++.h>
using namespace std;
void swap(int * a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int Partition(vector<int>& input,int start,int end)//Partition函数，将数组分成两个部分，左边部分比目标小，右边部分比目标大
{
    int length=input.size();
    int front=start-1;
    swap(&input[start],&input[end]);
    for(int index=start;index<end;index++)
    {
        if(input[index]<input[end])
        {
            front++;
            if(front!=index)
            {
                swap(&input[index],&input[front]);
            }
        }
    }
    front++;
    swap(&input[front],&input[end]);
    return front;
}
/*
解法一：基于Partition函数来实现，数组顺序会变化，不适用于海量数据的实现。
时间复杂度为O(n).
*/
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    int length=input.size();
    vector<int> res;
    if(length==0||k<1||k>length)
    return res;
    int index=Partition(input,0,length-1);
    while(index!=k-1)
    {
        if(index>k-1)
        {
            index=Partition(input,0,index-1);
        }
        else{
            index=Partition(input,index+1,length-1);
        }
    }
    for(int i=0;i<k;i++)
    {
        res.push_back(input[i]);
    }
    return res;
}

/*
解法二：不需要改变原数组中数据的顺序，适用于海量数据，时间复杂度为O(nlgk)。
利用最大堆，刚开始的时候先把最开始的k个数据压入到堆中；
然后从k到数据的末尾开始遍历，如果当前访问的数据比最大堆堆顶元素还小，则将当前堆顶元素出堆，把目前访问的元素推入堆中，调整堆的顺序。

书上是利用multiset实现的：
typdefine multiset<int,greater<int>> inSet--这是一个允许有重复元素存在的按从大到小排好序的集合。  
*/
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
    int length=input.size();
    vector<int> res;
    if(length==0||k<1||k>length)
    return res;
    for(int i=0;i<k;i++)
    {
        res.push_back(input[i]);
        push_heap(res.begin(),res.end(),less<int>());
    }
    for(int i=k;i<length;i++)
    {
        if(input[i]<res[0])
        {
            pop_heap(res.begin(),res.end(),less<int>());
            res.pop_back();
            res.push_back(input[i]);
            push_heap(res.begin(),res.end(),less<int>());
        }
    }
    return res;
}