/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should 
take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all 
courses, return an empty array. 

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about 
how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
#include<bits/stdc++.h>
using namespace std;
/*
同样是建立图，层序遍历。
*/
vector<int> findOrder(int numCourses, vector< pair<int, int> >& prerequisites) {
    vector<int> res;
    vector< vector<int> > graph(numCourses,vector<int> (0));//每个节点对应的节点列表
    vector<int> in(numCourses,0);//表示节点入度
    queue<int> q;//存储入度为0的节点。
    for(int i=0;i<prerequisites.size();i++)//有向图的建立
    {
        graph[prerequisites[i].second].push_back(prerequisites[i].first);
        in[prerequisites[i].first]++;
    }
    for(int i=0;i<numCourses;i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        res.push_back(temp);
        for(int i=0;i<graph[temp].size();i++)
        {
            in[graph[temp][i]]--;
            if(in[graph[temp][i]]==0)
            {
                q.push(graph[temp][i]);
            }
        }
    }
    vector<int> res1;
    for(int i=0;i<numCourses;i++)
    {
        if(in[i]!=0)
        return res1;
    }
    return res;

}
int main()
{
    int n,m;//n个数，m组数据
    while(cin>>n>>m)
    {
        vector<int> res;
        vector< pair<int,int> > data;
        for(int i=0;i<m;i++)
        {
            int a;
            int b;
            cin>>a>>b;
            data.push_back(pair<int,int>(a,b));
        }
        res=findOrder(n,data);
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<' ';
        }
    }
    return 0;
}