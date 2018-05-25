/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest 
transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
#include<bits/stdc++.h>
using namespace std;
int distan(string s1,string s2)
{
    int n=s1.size();
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])
        num++;
    }
    return num;
}
//DFS的思路，时间复杂度过大。不能通过所有的测试用例。19/39
// int ladderLengthCore(string beginWord, string endWord,vector<bool>& mem,vector<string>& wordList,int x,int num)
// {
//     mem[x]=true;
//     num++;
//     int res=INT_MAX-10000;
//     if(num>wordList.size())
//     {
//         mem[x]=false;
//         return INT_MAX-10000;
//     }
//     if(beginWord==endWord)
//     {
//         mem[x]=false;
//         return 1;
//     }
//     for(int i=0;i<wordList.size();i++)
//     {
//         if(mem[i]==false&&distan(wordList[i],beginWord)==1)
//         {
//             res=min(ladderLengthCore(wordList[i],endWord,mem,wordList,i,num)+1,res);
//         }
//     }
//     mem[x]=false;
//     return res;
// }
// int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//     int size=wordList.size();
//     vector<bool> mem(size,0);
//     int res=INT_MAX-10000;
//     for(int i=0;i<size;i++)
//     {
//         if(distan(wordList[i],beginWord)==1)
//         res=min(ladderLengthCore(wordList[i],endWord,mem,wordList,i,0)+1,res);
//     }
//     if(res==INT_MAX-10000)
//     return 0;
//     else
//     return res;
// }
//BFS通过测试用例30/39；使用vector查找
// int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//     int size=wordList.size();
//     int res=0;
//     int sizeofword=beginWord.size();
//     queue<string> q;
//     q.push(beginWord);
//     while(!q.empty())
//     {
//         res++;
//         int sizeofq=q.size();
//         for(int i=0;i<sizeofq;i++)
//         {
//             string tempstr=q.front();
//             if(tempstr==endWord)
//             {
//                 return res;
//             }
//             q.pop();
//             for(int k=0;k<sizeofword;k++)
//             {
//                 char c=tempstr[k];
//                 for(int j=0;j<26;j++)
//                 {
//                     string tempstr2=tempstr;
//                     if(j+'a'!=c)
//                     {
//                         tempstr2[k]=j+'a';
//                         vector<string>::iterator it=find(wordList.begin(),wordList.end(),tempstr2);
//                         if(it!=wordList.end())
//                         {
//                             if(tempstr2==endWord)
//                             return res+1;
//                             q.push(tempstr2);
//                             wordList.erase(it);
//                         }
//                     }
//                 }
//             }
//         }

//     }
//     return 0;
// }
/*
BFS
使用unordered_set可以极大程度减小时间复杂度。具有好的查询效率
*/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dictionary(wordList.begin(),wordList.end());
    int size=dictionary.size();//词典的大小
    int res=0;
    int sizeofword=beginWord.size();//每个词的长度
    queue<string> q;
    q.push(beginWord);
    while(!q.empty())
    {
        res++;
        int sizeofq=q.size();
        for(int i=0;i<sizeofq;i++)
        {
            string tempstr=q.front();
            if(tempstr==endWord)
            {
                return res;
            }
            q.pop();
            for(int k=0;k<sizeofword;k++)//针对每个词查找它变化一个字符是否在词典中
            {
                char c=tempstr[k];
                for(int j=0;j<26;j++)
                {
                    string tempstr2=tempstr;
                    if(j+'a'!=c)
                    {
                        tempstr2[k]=j+'a';
                        if(dictionary.find(tempstr2)!=dictionary.end())
                        {
                            if(tempstr2==endWord)
                            return res+1;
                            q.push(tempstr2);
                            dictionary.erase(tempstr2);
                        }
                    }
                }
            }
        }

    }
    return 0;
}


int main()
{
    int n;
    while(cin>>n)
    {
        string start;
        string end;
        cin>>start>>end;
        vector<string> words;
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            words.push_back(temp);        
        }
        cout<<ladderLength(start,end,words);
    }
    return 0;
}