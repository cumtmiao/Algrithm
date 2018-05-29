/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/
#include<bits/stdc++.h>
using namespace std;
bool rowvalid(vector<vector<char>>& board,int i)//判断某一行是否有效
{
    map<char,int> m;
    for(int j=0;j<9;j++)
    {
        m[board[i][j]]++;
    }
    for(int j=0;j<9;j++)
    {
        if(m['1'+j]>1)
        return false;
    }
    return true;
}
bool colvalid(vector<vector<char>>& board,int j)//判断某一列是否有效
{
    map<char,int> m;
    for(int i=0;i<9;i++)
    {
        m[board[i][j]]++;
    }
    for(int i=0;i<9;i++)
    {
        if(m['1'+i]>1)
        return false;
    }
    return true;
}
bool subvalid(vector<vector<char>>& board,int x,int y)//判断某个小矩形是否有效
{
    map<char,int> m;
    for(int i=x;i<x+3;i++)
    {
        for(int j=y;j<y+3;j++)
        {
            m[board[i][j]]++;
        }
    }
    for(int i=0;i<9;i++)
    {
        if(m['1'+i]>1)
        return false;
    }
    return true;
}
bool isValidSudoku(vector<vector<char>>& board) {
    for(int i=0;i<9;i++)
    {
        if(!rowvalid(board,i))
        return false;
    }
    for(int j=0;j<9;j++)
    {
        if(!colvalid(board,j))
        return false;
    }
    for(int i=0;i<9;i=i+3)
    {
        for(int j=0;j<9;j=j+3)
        {
            if(!subvalid(board,i,j))
            return false;
        }
    }
    return true;
}