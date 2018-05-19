/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton 
devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with 
its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above 
Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: 
You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, 
which would cause problems when the active area encroaches the border of the array. 
How would you address these problems?
*/
#include<bits/stdc++.h>
using namespace std;
void gameOfLife(vector<vector<int>>& board) {
    int rows=board.size();
    if(rows==0)
    return ;
    int cols=board[0].size();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            int num=0;
           // 先统计一个cell周围1或者3的个数，因为我们将要改变为0的‘1’节点记录为3
            if(i-1>=0&&j-1>=0)
            {
                if(board[i-1][j-1]==1||board[i-1][j-1]==3)//左上角
                num++;
            }
            if(i-1>=0)
            {
                if(board[i-1][j]==1||board[i-1][j]==3)//正上
                num++;
            }
            if(i-1>=0&&j+1<cols)//右上
            {
                if(board[i-1][j+1]==1||board[i-1][j+1]==3)
                num++;
            }
            if(j-1>=0)//左
            {
                if(board[i][j-1]==1||board[i][j-1]==3)
                num++;
            }
            if(j+1<cols)//右
            {
                if(board[i][j+1]==1||board[i][j+1]==3)
                num++;
            }
            if(i+1<rows&&j-1>=0)//左下
            {
                if(board[i+1][j-1]==1||board[i+1][j-1]==3)
                num++;
            }
            if(i+1<rows)//下
            {
                if(board[i+1][j]==1||board[i+1][j]==3)
                num++;
            }
            if(i+1<rows&&j+1<cols)//右下
            {
                if(board[i+1][j+1]==1||board[i+1][j+1]==3)
                num++;
            }
            if(board[i][j]==0)//如果当前节点为0
            {
                if(num==3)//周围1的个数为3
                board[i][j]=2;//将当前节点改变为2
            }
            else
            {
                if(num<2||num>3)//将想要变为0的‘1’节点统统即为3
                board[i][j]=3;
            }
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(board[i][j]==2)//当前是0的节点，应该改变为1
            board[i][j]=1;
            if(board[i][j]==3)//当前为1的节点，应该改变为0
            board[i][j]=0;
        }
    }
    return;
}