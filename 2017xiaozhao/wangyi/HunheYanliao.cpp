/*
题目描述
你就是一个画家！你现在想绘制一幅画，但是你现在没有足够颜色的颜料。为了让问题简单，我们用正整数表示不同颜色的颜料。
你知道这幅画需要的n种颜色的颜料，你现在可以去商店购买一些颜料，但是商店不能保证能供应所有颜色的颜料，所以你需要自己混合一些颜料。
混合两种不一样的颜色A和颜色B颜料可以产生(A XOR B)这种颜色的颜料(新产生的颜料也可以用作继续混合产生新的颜色,XOR表示异或操作)。
本着勤俭节约的精神，你想购买更少的颜料就满足要求，所以兼职程序员的你需要编程来计算出最少需要购买几种颜色的颜料？
输入描述:
第一行为绘制这幅画需要的颜色种数n (1 ≤ n ≤ 50)
第二行为n个数xi(1 ≤ xi ≤ 1,000,000,000)，表示需要的各种颜料.
输出描述:
输出最少需要在商店购买的颜料颜色种数，注意可能购买的颜色不一定会使用在画中，只是为了产生新的颜色。
示例1
输入

3
1 7 3
输出

3
*/
/*
相当于求解矩阵的线性无关组。
将每一个数字都看成是一个二进制的向量，因此所有的颜色可以构成一个矩阵[n*32]:n个实例，每个实例都是32bit。
可以对原来所有向量组成的矩阵用高斯消元法直到让剩余的向量都是线性无关的,非0向量的个数就是答案。
本例子中的高斯消元与传统的不同，而是使用亦或的方法进行消元。
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> colors;
    for(int i=0;i<n;i++)//输入n个实例
    {
        int tempcolor;
        cin>>tempcolor;
        colors.push_back(tempcolor);
    }
    sort(colors.begin(),colors.end(),greater<int>());//从大到小排序
    vector<int>::iterator it=colors.begin();
    int num=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp=colors[i]^colors[j];
            if(temp<colors[j])//用亦或操作进行消元
            {
                colors[j]=temp;
            }
        }
        sort(++it,colors.end(),greater<int>());//消元完之后顺序可能会改变，此时需要调整数组的顺序。使从大到小排列
    }
    for(int i=0;i<n;i++)//消元之后非0的元素个数即为我们要求的数
    {
        if(colors[i]!=0)
        num++;
    }
    cout<< num;
    return 0;
}