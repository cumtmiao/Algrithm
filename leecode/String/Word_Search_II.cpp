/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells 
are those horizontally or vertically neighboring. The same letter cell may not be used more than once 
in a word.

Example:

Input: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Output: ["eat","oath"]
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
#include<bits/stdc++.h>
using namespace std;
/*
AC ：1634ms
直接采用DFS刚刚能够通过
*/
bool findwordcore(vector< vector<char> >& board, string str,vector< vector<bool> >& mem, int rows,int cols,int x,int y,int index)
{
    mem[x][y]=true;
    if(index==str.size()-1)
    {
        mem[x][y]=false;
        return true;
    }
    bool res=false;
    if(x-1>=0&&mem[x-1][y]==false&&board[x-1][y]==str[index+1])
    {
        res|=findwordcore(board,str,mem,rows,cols,x-1,y,index+1);
    }
    if(res==false&&x+1<rows&&mem[x+1][y]==false&&board[x+1][y]==str[index+1])
    {
        res|=findwordcore(board,str,mem,rows,cols,x+1,y,index+1);
    }
    if(res==false&&y-1>=0&&mem[x][y-1]==false&&board[x][y-1]==str[index+1])
    {
        res|=findwordcore(board,str,mem,rows,cols,x,y-1,index+1);
    }
    if(res==false&&y+1<cols&&mem[x][y+1]==false&&board[x][y+1]==str[index+1])
    {
        res|=findwordcore(board,str,mem,rows,cols,x,y+1,index+1);
    }
    mem[x][y]=false;
    return res;
}
bool findword(vector< vector<char> >& board, string str)
{
    int length=str.size();
    if(length==0)
    return true;
    int rows=board.size();
    if(rows==0)
    return false;
    int cols=board[0].size();
    vector< vector<bool> > mem(rows,vector<bool>(cols,0));
    bool res=false;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(board[i][j]==str[0])
            {
                res|=findwordcore(board,str,mem,rows,cols,i,j,0);
                if(res==true)
                break;
            }
        }
    }
    return res;
}
vector<string> findWords(vector< vector<char> >& board, vector<string>& words) {
    vector<string> res;
    set<string> Words;
    for(int i=0;i<words.size();i++)
    {
        Words.insert(words[i]);
    }
    words=vector<string>(Words.begin(),Words.end());
    for(int i=0;i<words.size();i++)
    {
        if(findword(board,words[i]))
        {
            res.push_back(words[i]);
        }
    }
    return res;
}
/*
建立trie树能够大幅度的提升效率。
AC 41ms
*/
class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string str;
        TrieNode() : str("") {
            for (auto &a : child) a = NULL;
        }
    };
    struct Trie {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (auto &a : words) T.insert(a);//建立trie树
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (T.root->child[board[i][j] - 'a']) {
                    search(board, T.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }
        return res;
    }
    void search(vector<vector<char> > &board, TrieNode *p, int i, int j, vector<vector<bool> > &visit, vector<string> &res) { 
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a']) {
                search(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }
        visit[i][j] = false;
    }
};
int main()
{
    int n;
    while(cin>>n)
    {
        vector<string> words;
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            words.push_back(temp);
        }
        int rows,cols;
        cin>>rows>>cols;
        vector< vector<char> > board;
        for(int i=0;i<rows;i++)
        {
            vector<char> tempboard;
            for(int j=0;j<cols;j++)
            {
                char tempc;
                cin>>tempc;
                tempboard.push_back(tempc);
            }
            board.push_back(tempboard);
        }
        vector<string> res;
        res=findWords(board,words);
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<' ';
        }
    }
    return 0;
}