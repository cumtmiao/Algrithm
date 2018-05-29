/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces
in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;
/*
单纯的递归会超时。 
*/
// vector<string> res;
// void wordBreakCore(string s,vector<string>& wordDict,int index,string str)
// {
//     if(index==s.size())
//     {
//         res.push_back(str);
//         return ;
//     }
//     for(int i=index;i<s.size();i++)
//     {
//          if(count(wordDict.begin(),wordDict.end(),s.substr(index,i-index+1))==1)
//         // if(ma[s.substr(index,i-index+1)]!=0)
//         {
//             string str1;
//             if(index==0)
//             {
//                 str1=str+s.substr(index,i-index+1);
//             }
//             else
//             {
//                 str1=str+" "+s.substr(index,i-index+1);
//             } 
//             wordBreakCore(s,wordDict,i+1,str1);
//         }
//     }
// }
// vector<string> wordBreak(string s, vector<string>& wordDict) {
//     wordBreakCore(s,wordDict,0,"");
//     return res;
// }
/*
带记忆的递归。通过AC
*/
unordered_map <string, vector<string> > m;
vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> res;
    if(m.count(s))
    return m[s];
    if(s.empty())
    return {""};
    
    for(string word:wordDict)
    {
        if(s.substr(0,word.size())!=word)
        continue;
        vector<string> temp=wordBreak(s.substr(word.size()),wordDict);
        for(string str: temp)
        {
            res.push_back(word+(str.empty()?"":" ")+str);
        }
    }
    return m[s]=res;
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        vector<string> dict;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string str;
            cin>>str;
            dict.push_back(str);
        }
        vector<string> res=wordBreak(s,dict);
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<endl;
        }
    }
    return 0;
}