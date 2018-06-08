/*
美团外卖的品牌代言人袋鼠先生最近正在进行音乐研究。他有两段音频，每段音频是一个表示音高的序列。现在袋鼠先生想要在第二段
音频中找出与第一段音频最相近的部分。

具体地说，就是在第二段音频中找到一个长度和第一段音频相等且是连续的子序列，使得它们的 difference 最小。两段等长音频的
difference 定义为：
difference = SUM(a[i] - b[i])2 (1 ≤ i ≤ n),其中SUM()表示求和 
其中 n 表示序列长度，a[i], b[i]分别表示两段音频的音高。现在袋鼠先生想要知道，difference的最小值是多少？
数据保证第一段音频的长度小于等于第二段音频的长度。
输入描述:
第一行一个整数n(1 ≤ n ≤ 1000)，表示第一段音频的长度。
第二行n个整数表示第一段音频的音高（0 ≤ 音高 ≤ 1000）。
第三行一个整数m(1 ≤ n ≤ m ≤ 1000)，表示第二段音频的长度。
第四行m个整数表示第二段音频的音高（0 ≤ 音高 ≤ 1000）。
输出描述:
输出difference的最小值
示例1
输入
复制
2
1 2
4
3 1 2 4
输出
复制
0
*/
#include<bits/stdc++.h>
using namespace std;
int calculations(vector<int> first,int n,vector<int> second,int m)
{
    int res=INT_MAX;
    for(int i=0;i<=m-n;i++)
    {
        int tempsum=0;
        for(int j=i;j<i+n;j++)
        {
            int temp=second[j]-first[j-i];
            tempsum+=temp*temp;
        }
        res=min(res,tempsum);
    }
    return res;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> first;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            first.push_back(temp);
        }
        int m;
        cin>>m;
        vector<int> second;
        for(int i=0;i<m;i++)
        {
            int temp;
            cin>>temp;
            second.push_back(temp);
        }
        int res=calculations(first,n,second,m);
        cout<<res;
    }
    return 0;
}