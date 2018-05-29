/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, 
column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

Example 1:
Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
*/
#include<bits/stdc++.h>
using namespace std;
int sumof3numbers(int x,int y, int z)
{
    return x+y+z;
}
//判断左上角坐标为(x,y)的矩形是否是magicSquare
bool isMagicSquare(vector< vector<int> > grid, int x,int y)
{
    map<int,int> hash;
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            if(grid[i][j]>=1&&grid[i][j]<=9)
            {
                hash[grid[i][j]]++;
            }
        }
    }
    for(int i=1;i<=9;i++)
    {
        if(hash[i]!=1)
        return false;
    }
    return sumof3numbers(grid[x][y],grid[x][y+1],grid[x][y+2])==15&&sumof3numbers(grid[x+1][y],grid[x+1][y+1],grid[x+1][y+2])==15&&sumof3numbers(grid[x+2][y],grid[x+2][y+1],grid[x+2][y+2])==15
        &&sumof3numbers(grid[x][y],grid[x+1][y],grid[x+2][y])==15&&sumof3numbers(grid[x][y+1],grid[x+1][y+1],grid[x+2][y+1])==15&&sumof3numbers(grid[x][y+2],grid[x+1][y+2],grid[x+2][y+2])==15
        &&sumof3numbers(grid[x][y],grid[x+1][y+1],grid[x+2][y+2])==15&&sumof3numbers(grid[x+2][y],grid[x+1][y+1],grid[x][y+2])==15;

}
int numMagicSquaresInside(vector< vector<int> >& grid) {
    int rows=grid.size();
    int cols=grid[0].size();
    int num=0;
    for(int i=0;i<rows-2;i++)
    {
        for(int j=0;j<cols-2;j++)
        {
            if(isMagicSquare(grid,i,j))
            num++;
        }
    }
    return num;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector< vector<int> > data(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int temp;
                cin>>temp;
                data[i][j]=temp;
            }
        }
        cout<<numMagicSquaresInside(data);
    }
    return 0;
}