/*
题目描述
找出n个数里最小的k个
输入描述:
每个测试输入包含空格分割的n+1个整数，最后一个整数为k值,n
不超过100。
输出描述:
输出n个整数里最小的k个数。升序输出
示例1
输入

3 9 6 8 -10 7 -11 19 30 12 23 5
输出

-11 -10 3 6 7
*/
/*
本方法用的是求流中的最小的k个数。
实际上求解本题目直接排序取最小的k个数即可。
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> data;
    int temp;
    while(cin>>temp)
    data.push_back(temp);//输入数据
    int k=data[data.size()-1];//取出最后一个元素为k
    data.erase(data.end()-1);
    vector<int> res;
    for(int i=0;i<k;i++)//建立一个最大堆
    {
        res.push_back(data[i]);
        push_heap(res.begin(),res.end(),less<int>());
    }
    for(int i=k;i<data.size();i++)
    {
        if(data[i]<res[0])
        {
            pop_heap(res.begin(),res.end(),less<int>());
            res.pop_back();
            res.push_back(data[i]);
            push_heap(res.begin(),res.end(),less<int>());
        }

    }
    sort(res.begin(),res.end());
    for(int i=0;i<k;i++)
    {
        if(i!=k-1)
        cout<<res[i]<<' ';
        else
        cout<<res[i];
    }
    return 0;
}