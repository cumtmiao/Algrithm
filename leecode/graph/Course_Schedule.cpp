/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish 
all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, 
and to take course 0 you should also have finished course 1. So it is impossible.
*/
#include<bits/stdc++.h>
using namespace std;
/*
本题目实际上是考察有向图中是否有环存在，如果有环则返回false，否则返回true。
首先建立有向图，并且使用一个一维数组存储每一个节点的入度。使用BFS访问有向图，当访问结束的时候，
如果还有节点的入度不为0，则有环否则无环。
*/
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector< vector<int> > graph(numCourses, vector<int>(0));
    vector<int> in(numCourses,0);
    for(int i=0;i<prerequisites.size();i++)//建立有向图并且初始化有向图中每个节点的入度
    {
        graph[prerequisites[i].second].push_back(prerequisites[i].first);
        in[prerequisites[i].first]++;
    }
    queue<int> q;
    for(int i=0;i<numCourses;i++)//将入度为0的节点push进入队列中
    {
        if(in[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        //对当前访问的每个节点，如果它有边指向其他的节点，则队其他节点入度减1，如果该节点入度为0，则再次将它入队
        for(int val:graph[temp])
        {
            in[val]--;
            if(in[val]==0)
            q.push(val);
        }
    }
    for(int i=0;i<numCourses;i++)//遍历有向图节点，如果有节点入度不为0，则有环，否则无环。
    {
        if(in[i]!=0)
        return false;
    }
    return true;
}