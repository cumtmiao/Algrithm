/*
题目描述
小明同学把1到n这n个数字按照一定的顺序放入了一个队列Q中。现在他对队列Q执行了如下程序：
while(!Q.empty())              //队列不空，执行循环

{

    int x=Q.front();            //取出当前队头的值x

    Q.pop();                 //弹出当前队头

    Q.push(x);               //把x放入队尾

    x = Q.front();              //取出这时候队头的值

    printf("%d\n",x);          //输出x

    Q.pop();                 //弹出这时候的队头

}

做取出队头的值操作的时候，并不弹出当前队头。
小明同学发现，这段程序恰好按顺序输出了1,2,3,...,n。现在小明想让你构造出原始的队列，你能做到吗？[注：原题样例第三行5有错，应该为3，以下已修正]
输入描述:
第一行一个整数T（T ≤ 100）表示数据组数，每组数据输入一个数n（1 ≤ n ≤ 100000），输入的所有n之和不超过200000。
输出描述:
对于每组数据，输出一行，表示原始的队列。数字之间用一个空格隔开，不要在行末输出多余的空格.
示例1
输入

4
1
2
3
10
输出

1
2 1
2 1 3
8 1 6 2 10 3 7 4 9 5
*/
#include<bits/stdc++.h>
using namespace std;
int main()//找到内在的数学规律，用数组的方法求解。
{
    int n;
    cin>>n;
    int data[n];
    for(int i=0;i<n;i++)
    {
        int tempdata;
        cin>>tempdata;
        data[i]=tempdata;
    }
    for(int i=0;i<n;i++)
    {
        int tempres[data[i]];
        memset(tempres,0,sizeof(tempres));
        for(int k=1,j=0;k<=data[i];k++)
        {
            while(tempres[j%data[i]]!=0)j++;
            j++;
            while(tempres[j%data[i]]!=0)j++;
            tempres[j%data[i]]=k;
            j++;
        }
        for(int k=0;k<data[i];k++)
        {
            cout<<tempres[k]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

/*思路二：
假设
原始序列为a0,a1,a2,...,an-1,现在压入队列的都是下标0，1，2,...,n-1, 
然后依据题意的while循环，记录每次出队的下标，正好对应1，2，3。。。，并插入map。
最后按照索引遍历map可以得到原始数组的值。
*/
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int nx;
        cin>>nx;
        queue<int> qe;
        map<int,int> ma;
        int value=1;
        for(int j=0;j<nx;j++)
        {
            qe.push(j);
        }
        while(!qe.empty())
        {
            int x=qe.front();
            qe.pop();
            qe.push(x);
            x=qe.front();
            ma.insert(pair<int,int>(x,value++));
            qe.pop();
        }
        for(int j=0;j<nx;j++)
        {
            if(j!=nx-1)
            cout<<ma[j]<<' ';
            else
            cout<<ma[j];
        }
        cout<<endl;
    }
    return 0;
}