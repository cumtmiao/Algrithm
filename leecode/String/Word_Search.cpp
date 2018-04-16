/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are 
those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/
#include<bits/stdc++.h>
using namespace std;
/*
采用递归的方法。
*/
bool existcore(vector< vector<char> >& board,const int rows,const int cols,int row,int col,string word,int index,vector< vector<int> > & isvisited)
{
    if(index==word.size())
    return true;
    if(row<0||row>=rows||col<0||col>=cols)
    return false;
    bool ans=false;
    if(board[row][col]==word[index]&&isvisited[row][col]==0)
    {
        isvisited[row][col]=1;
        ans= existcore(board,rows,cols,row-1,col,word,index+1,i svisited)||
             existcore(board,rows,cols,row+1,col,word,index+1,isvisited)||
             existcore(board,rows,cols,row,col-1,word,index+1,isvisited)||
             existcore(board,rows,cols,row,col+1,word,index+1,isvisited);   
        isvisited[row][col]=0;
    }
    return ans;
    
}
bool exist(vector< vector<char> >& board, string word) {
    int sizeofword=word.size();
    if(sizeofword==0)
    return true;
    const int rows=board.size();
    if(rows==0)
    return false;
    const int cols=board[0].size();
    vector< vector<int> > isvisited(rows,vector<int> (cols,0));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(existcore(board,rows,cols,i,j,word,0,isvisited))
            return true;
        }
    }
    return false;
}
int main()
{
    vector< vector<char> > data;
    int n,m;
    while(cin>>n>>m)
    {
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
        string str;
        cin>>str;
        if(exist(data,str))
        cout<<"true";
        else
        cout<<"false";
    }
    return 0;
}