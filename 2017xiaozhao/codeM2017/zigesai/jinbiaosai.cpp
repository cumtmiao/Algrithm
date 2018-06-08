/*
组委会正在为美团点评CodeM大赛的决赛设计新赛制。

比赛有 n 个人参加（其中 n 为2的幂），每个参赛者根据资格赛和预赛、复赛的成绩，会有不同的积分。比赛采取锦标赛赛制，
分轮次进行，设某一轮有 m 个人参加，那么参赛者会被分为 m/2 组，每组恰好 2 人，m/2 组的人分别厮杀。
我们假定积分高的人肯定获胜，若积分一样，则随机产生获胜者。获胜者获得参加下一轮的资格，输的人被淘汰。重复这个过程，
直至决出冠军。

现在请问，参赛者小美最多可以活到第几轮（初始为第0轮）？
输入描述:
第一行一个整数 n (1≤n≤ 2^20)，表示参加比赛的总人数。

接下来 n 个数字（数字范围：-1000000…1000000），表示每个参赛者的积分。

小美是第一个参赛者。
输出描述:
小美最多参赛的轮次。
示例1
输入
复制
4
4 1 2 3
输出
复制
2
*/
#include<bits/stdc++.h>
using namespace std;
/*
相当于查找一个元素在排序后的数组中的位置。
*/
int calculation(vector<int> nums)
{
    int n=nums.size();
    int find=nums[0];
    sort(nums.begin(),nums.end());
    int index=0;//标记find(小美)的位置
    for(int i=0;i<n;i++)
    {
        if(nums[i]>find)
        {
            index=i;
            break;
        }
    }
    if(index==0)
    index=n;
    return (int)log2(index);
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> jifen;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            jifen.push_back(temp);
        }
        int res=calculation(jifen);
        cout<<res;
    }
    return 0;
}