/*
Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, 
compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.
*/
#include<bits/stdc++.h>
#include<queue>
using namespace std;
/*
简单有二维向三维扩展的思路是不正确的，一个cell装多少水不止由当前行和当前列决定，而应该由当前的边界确定。
*/
// int trapRainWater(vector< vector<int> >& heightMap) {
//     int rows=heightMap.size();
//     if(rows<=2)
//     return 0;
//     int cols=heightMap[0].size();
//     if(cols<=2)
//     return 0;
//     vector< vector<int> > l_max(rows,vector<int>(cols,0));
//     vector< vector<int> > r_max(rows,vector<int>(cols,0));
//     vector< vector<int> > u_max(rows,vector<int>(cols,0));
//     vector< vector<int> > d_max(rows,vector<int>(cols,0));
//     for(int i=0;i<rows;i++)//初始化
//     {
//         int lmax=0;
//         for(int j=0;j<cols;j++)
//         {
//             if(heightMap[i][j]>lmax)
//             lmax=heightMap[i][j];
//             l_max[i][j]=lmax;
//         }
//     }
//     for(int i=0;i<rows;i++)//初始化
//     {
//         int rmax=0;
//         for(int j=cols-1;j>=0;j--)
//         {
//             if(heightMap[i][j]>rmax)
//             rmax=heightMap[i][j];
//             r_max[i][j]=rmax;
//         }
//     }
//     for(int j=0;j<cols;j++)
//     {
//         int umax=0;
//         for(int i=0;i<rows;i++)
//         {
//             if(heightMap[i][j]>umax)
//             umax=heightMap[i][j];
//             u_max[i][j]=umax;
//         }
//     }
//     for(int j=0;j<cols;j++)
//     {
//         int dmax=0;
//         for(int i=rows-1;i>=0;i--)
//         {
//             if(heightMap[i][j]>dmax)
//             dmax=heightMap[i][j];
//             d_max[i][j]=dmax;
//         }
//     }
//     int res=0;
//     for(int i=1;i<rows-1;i++)
//     {
//         for(int j=1;j<cols-1;j++)
//         {
//             res+=min(min(l_max[i][j],r_max[i][j]),min(u_max[i][j],d_max[i][j]))-heightMap[i][j];
//         }
//     }
//     return res;
// }
/*
思路参见：
https://www.cnblogs.com/grandyang/p/5928987.html
*/
int trapRainWater(vector< vector<int> >& heightMap) {
    int rows=heightMap.size();
    if(rows<=2)
    return 0;
    int cols=heightMap[0].size();
    if(cols<=2)
    return 0;
    priority_queue< pair<int,int>,vector< pair<int,int> >,greater<pair<int,int> > > q;//定义优先级队列
    vector< vector<int> > dir{{0,-1},{0,1},{1,0},{-1,0}};
    vector< vector<bool> > visited(rows,vector<bool>(cols,0));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==0||j==0||i==rows-1||j==cols-1)
            {
                q.push(make_pair(heightMap[i][j],cols*i+j));
                visited[i][j]=true;
            }
        }
    }
    int mx=INT_MIN;//表示当前水位的高度。
    int res=0;
    while(!q.empty())
    {
        auto temp=q.top();
        q.pop();
        mx=max(temp.first,mx);
        int r=temp.second/cols;
        int c=temp.second%cols;
        for(int i=0;i<dir.size();i++)
        {
            int x=r+dir[i][0];
            int y=c+dir[i][1];
            if(x<0||x>=rows||y<0||y>=cols||visited[x][y]==true)
            continue;
            visited[x][y]=true;
            if(heightMap[x][y]<mx)
            res+=mx-heightMap[x][y];
            q.push(make_pair(heightMap[x][y],x*cols+y));
        }
    }
    return res;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector< vector<int> > nums;
        for(int i=0;i<n;i++)
        {
            vector<int> tempv;
            for(int j=0;j<m;j++)
            {
                int temp;
                cin>>temp;
                tempv.push_back(temp);
            }
            nums.push_back(tempv);
        }
        cout<<trapRainWater(nums);
    }
    return 0;
}