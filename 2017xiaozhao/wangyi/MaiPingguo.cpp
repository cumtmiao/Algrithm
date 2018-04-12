/*
题目描述
小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋的包装(包装不可拆分)。 
可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。如果不能购买恰好n个苹果，小易将不会购买。
输入描述:
输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果
输出描述:
输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1
示例1
输入

20
输出

3
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int num8=n/8;
        if(n%8==0)
        cout<<num8;
        else
        {
            for(;num8>=0;num8--)
            {
                if((n-num8*8)%6==0)
                {
                    int num6=(n-num8*8)/6;
                    cout<<(num8+num6);
                    break;
                }
            }
            if(num8<0)
            cout<<-1;
        }
    }
    return 0;
}