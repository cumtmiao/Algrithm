/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
#include<bits/stdc++.h>
using namespace std;
int firstUniqChar(string s) {
    int n=s.size();
    vector<int> hash(26,0);
    for(int i=0;i<n;i++)
    {
        hash[s[i]-'a']++;
    }
    for(int i=0;i<n;i++)
    {
        if(hash[s[i]-'a']==1)
        return i;
    }
    return -1;
}