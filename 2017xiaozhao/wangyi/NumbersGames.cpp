/*
题目描述
小易邀请你玩一个数字游戏，小易给你一系列的整数。你们俩使用这些整数玩游戏。每次小易会任意说一个数字出来，
然后你需要从这一系列数字中选取一部分出来让它们的和等于小易所说的数字。 例如： 如果{2,1,2,7}是你有的一系列数，
小易说的数字是11.你可以得到方案2+2+7 = 11.如果顽皮的小易想坑你，他说的数字是6，那么你没有办法拼凑出和为6 现在小易给你n个数，
让你找出无法从n个数中选取部分求和的数字中的最小数。
输入描述:
输入第一行为数字个数n (n ≤ 20)
第二行为n个数xi (1 ≤ xi ≤ 100000)
输出描述:
输出最小不能由n个数选取求和组成的数
示例1
输入

3
5 1 2
输出

4
*/
#include<bits/stdc++.h>
using namespace std;
int main()//暴力解法--通过AC 但是占用过大的内存
{
    int n;
    cin>>n;
    int data[20];
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        data[i]=temp;
    }
    sort(data,data+n);
    set<int> se;
    se.clear();
    set<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        it=se.begin();
        int length=se.size();
        for(int j=0;j<length;j++,it++)
        {
            se.insert(data[i]+*it);
        }
        se.insert(data[i]);
    }
    int i;
    for(i=1;i<2000000&&se.find(i)!=se.end();i++);
    cout<<i;
    return 0;
}

/*
解法二：
很简单。。时间空间复杂度都很小
*/
int main()
{
    int n;
    cin>>n;
    int data[20];
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        data[i]=temp;
    }
    sort(data,data+n);
    int miss=0;//记录当前访问元素前面所有元素的部分和
    for(int i=0;i<n;i++)
    {
        if(data[i]>miss+1)
        break;
        miss+=data[i];
    }
    cout<<miss+1;
    return 0;
}