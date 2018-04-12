/*
题目描述
小青蛙有一天不小心落入了一个地下迷宫,小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。为了让问题简单,
假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,0代表这个位置有障碍物,小青蛙达到不了这个位置;
1代表小青蛙可以达到的位置。小青蛙初始在(0,0)位置,地下迷宫的出口在(0,m-1)(保证这两个位置都是1,
并且保证一定有起点到终点可达的路径),小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值,
向上爬一个单位距离需要消耗3个单位的体力值,向下移动不消耗体力值,当小青蛙的体力值等于0的时候还没有到达出口,
小青蛙将无法逃离迷宫。现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。
输入描述:
输入包括n+1行:
 第一行为三个整数n,m(3 <= m,n <= 10),P(1 <= P <= 100)
 接下来的n行:
 每行m个0或者1,以空格分隔
输出描述:
如果能逃离迷宫,则输出一行体力消耗最小的路径,输出格式见样例所示;如果不能逃离迷宫,则输出"Can not escape!"。 测试数据保证答案唯一
示例1
输入

4 4 10 1 0 0 1 1 1 0 1 0 1 1 1 0 0 1 1
输出

[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]
*/
/*
本题目主要考察回溯法。
*/
#include<bits/stdc++.h>
using namespace std;
struct mazepoint{//定义一个结构体表示一个“点”
    mazepoint(int _x,int _y):x(_x),y(_y){}
    int x,y;
};
int final_P=INT_MIN;
vector<mazepoint> finalpath;//存放最终路径
int visited=2;
void dfs(vector<vector<int>>& data,int x,int y,int p,vector<mazepoint> &res)
{
    int n=data.size();
    if(n==0)
        return ;
    int m=data[0].size();
    if(x<0||x>=n||y<0||y>=m||p<0)
    return;
    if(data[x][y]!=1)
    return ;
    res.push_back(mazepoint(x,y));
    data[x][y]=visited;
    if(x==0&&y==m-1&&p>=0)//最后记录结果
    {
        
        if(p>final_P)
        {
            final_P=p;
            finalpath=res;
        }
        res.pop_back();
        data[x][y]=1;
        return ;
    }
    //if(x+1>=0&&x+1<n&&data[x+1][y]==1)
    dfs(data,x+1,y,p,res);//递归访问一个节点周围的节点
   // if(x-1>=0&&x-1<n&&data[x-1][y]==1)
    dfs(data,x-1,y,p-3,res);
    //if(y+1>=0&&y+1<m&&data[x][y+1]==1)
    dfs(data,x,y+1,p-1,res);
    //if(y-1>=0&&y-1<m&&data[x][y-1]==1)
    dfs(data,x,y-1,p-1,res);

    res.pop_back();
    data[x][y]=1;
    return ;
}
int main()
{
    int n,m,p;
    while(cin>>n>>m>>p)
    {
        vector<vector<int>> data;
        for(int i=0;i<n;i++)
        {
            vector<int> tempdata;
            for(int j=0;j<m;j++)
            {
                int temp;
                cin>>temp;
                tempdata.push_back(temp);
            }
            data.push_back(tempdata);
        }
        vector<mazepoint> res;
        dfs(data,0,0,p,res);
        if(final_P==INT_MIN)
        cout<<"Can not escape!";
        else
        {
            for(int i=0;i<finalpath.size();i++)
            {
                if(i!=finalpath.size()-1)
                cout<<"["<<finalpath[i].x<<","<<finalpath[i].y<<"],";
                else
                cout<<"["<<finalpath[i].x<<","<<finalpath[i].y<<"]";
            }
        }
    }
    return 0;
}