/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not 
flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped 
to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/
#include<bits/stdc++.h>
using namespace std;
/*
从边界开始，找到每一个边界O能可达的位置，将其赋值为Y,然后将所有Y值赋值回O,其余所有值赋值为X
*/
//DFS递归搜索每一个边界O可达的位置
void solveCore(vector< vector<char> >& board,int rows,int cols,int x, int y)
{
    board[x][y]='Y';
    if(y-1>=0&&board[x][y-1]=='O')
    solveCore(board,rows,cols,x,y-1);
    if(y+1<cols&&board[x][y+1]=='O')
    solveCore(board,rows,cols,x,y+1);
    if(x-1>=0&&board[x-1][y]=='O')
    solveCore(board,rows,cols,x-1,y);
    if(x+1<rows&&board[x+1][y]=='O')
    solveCore(board,rows,cols,x+1,y);

}
void solve(vector< vector<char> >& board) {
    int rows=board.size();
    if(rows==0)
    return ;
    int cols=board[0].size();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==0||i==rows-1||j==0||j==cols-1)
            {
                if(board[i][j]=='O')
                solveCore(board,rows,cols,i,j);
            }
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(board[i][j]=='Y')//如果当前位置是Y，则将它变回O
            board[i][j]='O';
            else
            board[i][j]='X';//否则其余位置都是从边界O不可达的位置，赋值为X
        }
    }
    return ;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector< vector<char> > data;
        for(int i=0;i<n;i++)
        {
            vector<char> tempv;
            for(int j=0;j<m;j++)
            {
                char temp;
                cin>>temp;
                tempv.push_back(temp);
            }
            data.push_back(tempv);
        }
        solve(data);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<data[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}