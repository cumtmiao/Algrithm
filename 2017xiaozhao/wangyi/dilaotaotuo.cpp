/*
题目描述
给定一个 n 行 m 列的地牢，其中 '.' 表示可以通行的位置，'X' 表示不可通行的障碍，牛牛从 (x0 , y0 ) 位置出发，
遍历这个地牢，和一般的游戏所不同的是，他每一步只能按照一些指定的步长遍历地牢，要求每一步都不可以超过地牢的边界，
也不能到达障碍上。地牢的出口可能在任意某个可以通行的位置上。牛牛想知道最坏情况下，他需要多少步才可以离开这个地牢。
输入描述:
每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 50），表示地牢的长和宽。
接下来的 n 行，每行 m 个字符，描述地牢，地牢将至少包含两个 '.'。接下来的一行，包含两个整数 x0, y0，
表示牛牛的出发位置（0 <= x0 < n, 0 <= y0 < m，左上角的坐标为 （0, 0），出发位置一定是 '.'）。
之后的一行包含一个整数 k（0 < k <= 50）表示牛牛合法的步长数，接下来的 k 行，每行两个整数 dx, dy 
表示每次可选择移动的行和列步长（-50 <= dx, dy <= 50）
输出描述:
输出一行一个数字表示最坏情况下需要多少次移动可以离开地牢，如果永远无法离开，输出 -1。以下测试用例中，
牛牛可以上下左右移动，在所有可通行的位置.上，地牢出口如果被设置在右下角，牛牛想离开需要移动的次数最多，为3次。
示例1
输入

3 3
...
...
...
0 1
4
1 0
0 1
-1 0
0 -1
输出

3
*/
/*
我的思路是：错将题目意思理解为找到从（x0,y0）到任意边界出口的最大步数。
不能AC
*/
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int m;
// char data[50][50];
// int isvisited[50][50];
// int sumofbuchang=0;
// int finalbuchang=INT_MIN;
// struct point
// {
//     int x;
//     int y;
//     point(){}
//     point(int x0,int y0):x(x0),y(y0){}

// };
// bool isbianjie(point p)
// {
//     if(p.x==0||p.x==n-1)
//     {
//         if(p.y>=0&&p.y<=m-1)
//         return true;
//     }
//     if(p.y==0||p.y==m-1)
//     {
//         if(p.x>=0&&p.x<=n-1)
//         return true;
//     }
//     return false; 
// }
// bool inbianjie(point p)
// {
//     if(p.x>=0&&p.x<n&&p.y>=0&&p.y<m)
//     return true;
//     return false;
// }
// bool haspath(point p1,point p2)
// {
//     if(data[p1.x][p1.y]=='.'&&data[p2.x][p2.y]=='.')
//     return true;
//     return false;
// }
// void dfs(point p,vector<point> buchang,point p0)
// {
//     if(isbianjie(p)&&!(p.x==p0.x&&p.y==p0.y))
//     {
//         if(sumofbuchang>finalbuchang)
//         finalbuchang=sumofbuchang;
//         return ;
//     }
//     point p1;
//     for(int i=0;i<buchang.size();i++)
//     {
//          p1.x=p.x+buchang[i].x;
//          p1.y=p.y+buchang[i].y;
//         if(inbianjie(p1)&&haspath(p,p1)&&isvisited[p1.x][p1.y]==0)
//         {
//             isvisited[p1.x][p1.y]=1;
//             sumofbuchang++;
//             dfs(p1,buchang,p0);
//             sumofbuchang--;
//             isvisited[p1.x][p1.y]=0;
            
//         }
//     }
// }
// int main()
// {
//     while(cin>>n>>m)
//     {
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 char temp;
//                 cin>>temp;
//                 data[i][j]=temp;
//                 isvisited[i][j]=0;
//             }
//         }
//         int x0,y0;
//         cin>>x0>>y0;
//         int k;
//         cin>>k;
//         vector<point> buchang; 
//         for(int i=0;i<k;i++)
//         {
//             int tempx,tempy;
//              cin>>tempx>>tempy;
//            buchang.push_back(point(tempx,tempy));
//         }
//         dfs(point(x0,y0),buchang,point(x0,y0));
//         cout<<finalbuchang;
//     }
//     return 0;
// }
/*
本题目的意思是，只要ground[i][j]=='.',它就有可能是地牢的出口，求所有可能出口步数的最大值。
本题目利用BFS的思想
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
char ground[50][50];
int dis[50][50];
int direction[50][2];
struct point{
    int x;
    int y;
    point(int x0,int y0):x(x0),y(y0){}
    point go(int index)//从当前节点转移到“direction”矩阵中第index个方向。
    {
        return point(x+direction[index][0],y+direction[index][1]);
    }
    bool isOK()//判断一个节点是不是能够访问：没有超出边界；该点是'.'
    {
        if(x>=0&&x<n&&y>=0&&y<m&&ground[x][y]=='.')
        return true;
        else
        return false;
    }
};
int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char temp;
                cin>>temp;
                ground[i][j]=temp;
                dis[i][j]=INT_MAX;
            }
        }
        int x0,y0;
        cin>>x0>>y0;
        dis[x0][y0]=0;
        int k;
        cin>>k;
        for(int i=0;i<k;i++)
        {
            int tempa,tempb;
            cin>>tempa>>tempb;
            direction[i][0]=tempa;
            direction[i][1]=tempb;
        }
        queue<point> q;
        point start(x0,y0);
        q.push(start);
        while(!q.empty())//广度优先搜索遍历（BFS）
        {
            point x=q.front();
            q.pop();
            for(int i=0;i<k;i++)
            {
                point y=x.go(i);
                if(y.isOK())
                {
                    if(dis[y.x][y.y]>dis[x.x][x.y]+1)
                    {
                        dis[y.x][y.y]=dis[x.x][x.y]+1;
                        q.push(y);
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ground[i][j]=='.')
                {
                    res=max(res,dis[i][j]);
                }
            }
        }
        if(res==INT_MAX)
        cout<<-1;
        else
        cout<<res;
    }
    return 0;
}