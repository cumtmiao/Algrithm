/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different 
letters represent different tasks.Tasks could be done without original order. Each task could be done in 
one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at 
least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/
#include<bits/stdc++.h>
using namespace std;
/*
贪心算法。
*/
int leastInterval(vector<char>& tasks, int n) {
    map<char,int>m;
    priority_queue<int> q;//默认由大到小排序
    int res=0;
    int cycle=n+1;//每一块的大小为n+1;
    for(char c:tasks)//将tasks映射到hash表。
    m[c]++;
    for(auto a:m)
    q.push(a.second);
    while(!q.empty())
    {
        vector<int> temp;
        int cou=0;
        for(int i=0;i<cycle;i++)
        {
            if(!q.empty())
            {
                temp.push_back(q.top());
                q.pop();
                cou++;
                
            }
            else
            break;
        }
        for(int i=0;i<temp.size();i++)
        {
            if(--temp[i]>0)
            q.push(temp[i]);
        }
        if(q.empty())
        res+=cou;
        else
        res+=cycle;
    }
    return res;
}