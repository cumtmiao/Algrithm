/*
Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters 
and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not 
divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.
Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/
#include<bits/stdc++.h>
using namespace std;
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    int n=words.size();
    int l=0;
    int count=0;
    while(l<n)
    {
        int r=l;int len=0;
        while(r<n&&len+words[r].size()+r-l<=maxWidth)//这里len存储的是刚好满足总长度小于maxWidth的单词总长度
        {
            len+=words[r].size();
            r++;
        }
        int space=maxWidth-len;//当前行空格的数量
        string out;
        for(int k=l;k<r;k++)
        {
            out+=words[k];
            if(space>0)
            {
                int tmp;
                if(r==n)//根据是否是最后一行，对应处理
                {
                    if(k==r-1)
                    tmp=space;
                    else
                    tmp=1;
                }
                else
                {
                    if(k<r-1)
                    {
                        if(space%(r-k-1)==0)
                        tmp=space/(r-k-1);
                        else
                        tmp=space/(r-k-1)+1;
                    }
                    else
                    tmp=space;
                }
                out.append(tmp,' ');
                space-=tmp;
            }
        }
        res.push_back(out);
        l=r;
    }
    return res;
}