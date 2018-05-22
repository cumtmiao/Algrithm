/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) 
such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/
#include<bits/stdc++.h>
using namespace std;
//暴力解法.时间超时。O(n^3)
// int longestSubstring(string s, int k) {
//     int n=s.size();
//     int res=0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             vector<int> hash(26,0);
//             for(int l=i;l<=j;l++)
//             {
//                 hash[s[l]-'a']++;
//             }
//             int l;
//             for(l=i;l<=j;l++)
//             {
//                 if(hash[s[l]-'a']<k)
//                 break;
//             }
//             if(l>j)
//             res=max(res,j-i+1);
//         }
//     }
//     return res;
// }
/*
解法二：一种巧妙的解法。利用了位运算。
我们遍历字符串，对于每一个字符，我们都将其视为起点，然后遍历到末尾，我们增加哈希表中字母的出现次数，如果其小于k，
我们将mask的对应位改为1，如果大于等于k，将mask对应位改为0。然后看mask是否为0，是的话就更新res结果，
然后把当前满足要求的子字符串的起始位置j保存到max_idx中，等内层循环结束后，将外层循环变量i赋值为max_idx+1，继续循环直至结束.
*/
// int longestSubstring(string s, int k) {
//     int n=s.size();
//     int res=0;
//     int max_index;
//     for(int i=0;i<=n-k;)
//     {
//         max_index=i;
//         int mask=0;
//         int hash[26]={0};
//         for(int j=i;j<n;j++)
//         {
//             hash[s[j]-'a']++;
//             if(hash[s[j]-'a']<k)
//             mask|=(1<<(s[j]-'a'));
//             else
//             mask&=(~(1<<(s[j]-'a')));
//             if(mask==0)
//             {
//                 res=max(res,j-i+1);
//                 max_index=j;
//             }
//         }
//         i=max_index+1;
//     }
//     return res;
// }
/*
思路三：
利用分治法。
*/
int longestSubstring(string s, int k) {
    int n=s.size();
    int res=0;
    vector<int> hash(26,0);//hash用来存储每个字符在字符串中出现的次数
    for(int i=0;i<n;i++)
    {
        hash[s[i]-'a']++;
    }
    vector<int> dis;//dis存储字符串中出现次数少于k次的那些字符的索引
    for(int i=0;i<n;i++)
    {
        if(hash[s[i]-'a']<k)
        dis.push_back(i);
    }
    if(dis.empty())
    return n;
    else//dis不为空的话，针对dis将字符串分成的每一段，调用longestSubstring函数更新res值。
    {
        int i;
        string ste=s.substr(0,dis[0]);
        int te=longestSubstring(ste,k);
        res=max(res,te);
        for(i=1;i<dis.size();i++)
        {
            string temp=s.substr(dis[i-1]+1,dis[i]-dis[i-1]-1);
            int t=longestSubstring(temp,k);
            res=max(res,t);
        }
        res=max(res,longestSubstring(s.substr(dis[i-1]+1),k));
        return res;
    }
    
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        int k;
        cin>>k;
        cout<<longestSubstring(s,k);
    }
    return 0;
}