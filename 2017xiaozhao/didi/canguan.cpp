/*
题目描述
某餐馆有n张桌子，每张桌子有一个参数：a 可容纳的最大人数； 有m批客人，每批客人有两个参数:b人数，c预计消费金额。
 在不允许拼桌的情况下，请实现一个算法选择其中一部分客人，使得总预计消费金额最大
输入描述:
输入包括m+2行。 第一行两个整数n(1 <= n <= 50000),m(1 <= m <= 50000) 第二行为n个参数a,
即每个桌子可容纳的最大人数,以空格分隔,范围均在32位int范围内。 接下来m行，每行两个参数b,c。
分别表示第i批客人的人数和预计消费金额,以空格分隔,范围均在32位int范围内。
输出描述:
输出一个整数,表示最大的总预计消费金额
示例1
输入

3 5 2 4 2 1 3 3 5 3 7 5 9 1 10
输出

20
*/
/*
本题目采用贪心的策略：
优先安排钱数多的客人到能容得下它的最合适的桌子。
*/
#include<bits/stdc++.h>
using namespace std;
struct guest{
    int num;
    int money;
};
bool compare(guest a,guest b)//对客人进行排序的时候，钱多的，人少的客人，优先排在前面
{
    if(a.money==b.money)
    {
        a.num<b.num;
    }
    return a.money>b.money;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        multiset<int> desk;//multiset很合适，主要后面寻找合适的桌子的时候，能够利用到lower_buond函数
        vector<guest> people(m);
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            desk.insert(temp);
        }
        for(int i=0;i<m;i++)
        {
            int tempa,tempb;
            cin>>tempa>>tempb;
            people[i].num=tempa;
            people[i].money=tempb;
        }
        sort(people.begin(),people.end(),compare);
        long long res=0;
        for(int i=0;i<m;i++)
        {
            multiset<int>::iterator it=desk.lower_bound(people[i].num);
            if(it!=desk.end())
            {
                res+=people[i].money;
                desk.erase(it);
            }
        }
        cout<<res;
    }
    return 0;
}