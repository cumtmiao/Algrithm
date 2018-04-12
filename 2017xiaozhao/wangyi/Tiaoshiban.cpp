/*
题目描述
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数
(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 
小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述:
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1
示例1
输入

4 24
输出

5
*/
#include<bits/stdc++.h>
using namespace std;
int tiaoshiban(int n,int m,int* data)
{
    int num=0;
    queue<int> qe;
    if(n<m)
    {
        qe.push(n);
        data[n]=1;
        qe.push(-1);
    }
    while(!qe.empty())
    {
        int x=qe.front();
        if(x==-1)
        {
            qe.pop();
            if(!qe.empty())
            {
            num++;
            qe.push(-1);
            }
            else
            {
                num=-1;
                break;
            }
        }
        else if(x==m)
        {
            break;
        }
        else
        {        
            qe.pop();
            for(int i=2;i<=(x/2);i++)
            {
                if((x%i==0)&&(x+i<=m)&&data[x+i]==0)
                {
                    qe.push(x+i);
                    data[i+x]=1;
                }
            }
        }

    }
    return num;

}
int main()//方法一：利用了queue，但是只通过了70%的样例，占用过多的内存。
{
    int n,m;
    cin>>n>>m;
    int data[m+1];
    memset(data,0,sizeof(data));
    cout<<tiaoshiban(n,m,data);
    return 0;
}

/*
思路二：
本题目为典型的动态规划。
采用动态规划思想求解。创建一个vector容器steps，steps[i]表示到达i号石板所需的最小步数。
初始化为steps容器为INT_MAX。从序号N的石板开始逐个遍历，若steps[i]为INT_MAX，表示该点不可到达，直接开始下次循环。
若steps[i]不为INT_MAX，表示该点可以到达，下面求解编号i的约数，进行动态规划。动态规划的转移方程为
steps[i+j] = min(steps[i]+1,steps[i+j])   //i为石板编号，j为i的约束
steps[N] = 0
*/
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> step(m+1,INT_MAX);
    step[n]=0;
    for(int i=n;i<=m;i++)
    {
        if(step[i]==INT_MAX)
        continue;
        for(int j=2;(j*j)<=i;j++)
        {
            if(i%j==0)
            {
                if(i+j<=m)
                   step[i+j]=min(step[i+j],step[i]+1);
                if(i+i/j<=m)
                   step[i+i/j]=min(step[i+i/j],step[i]+1);
            }
        }
    }
    if(step[m]==INT_MAX)
    cout<<-1;
    else
    cout<<step[m];
    return 0;
}