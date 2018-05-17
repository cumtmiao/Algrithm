/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/
#include<bits/stdc++.h>
using namespace std;
/*
主要思路是：
建立一个tag数组：它是一个bool数组，如果它对应的grid值为‘1’，则将它赋值为true,否则的话将它赋值为false.
遍历访问tag数组。如果某个位置还没有访问过（即为true），则递归访问它，并且将对应的tag值赋为false.
*/
void dfs(vector< vector<bool> >& tag,int rows,int cols,int i,int j)//递归访问为‘1’的位置，并且将它对应的tag赋值为false
{
    tag[i][j]=false;
    if(j-1>=0&&tag[i][j-1]==true)
    dfs(tag,rows,cols,i,j-1);
    if(j+1<cols&&tag[i][j+1]==true)
    dfs(tag,rows,cols,i,j+1);
    if(i-1>=0&&tag[i-1][j]==true)
    dfs(tag,rows,cols,i-1,j);
    if(i+1<rows&&tag[i+1][j]==true)
    dfs(tag,rows,cols,i+1,j);
}
int numIslands(vector< vector<char> >& grid) {
    int rows=grid.size();
    if(rows==0)
    return 0;
    int cols=grid[0].size();
    vector< vector<bool> > tag(rows,vector<bool>(cols,false));//建立标签数组
    for(int i=0;i<rows;i++)//  1<->true:0<->false
    {
        for(int j=0;j<cols;j++)
        if(grid[i][j]=='1')
        tag[i][j]=true;
    }
    int num=0;//表示岛屿的数量
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(tag[i][j]==true)//如果某个1的位置还没有访问过，则递归访问它，并且将对应的tag值赋为false.
            {
                dfs(tag,rows,cols,i,j);
                num++;
            }
        }
    }
    return num;
}
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        vector< vector<char> > data;
        for(int i=0;i<m;i++)
        {
            vector<char> tempv;
            for(int j=0;j<n;j++)
            {
                char temp;
                cin>>temp;
                tempv.push_back(temp);
            }
            data.push_back(tempv);
        }
        cout<<numIslands(data);
    }
    return 0;
}