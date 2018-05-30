/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
*/
#include<bits/stdc++.h>
using namespace std;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
//由于map中存储的数double<->int的映射，可能存在精度失真问题，导致极个别的用例不能通过。35/36
// int maxPoints(vector<Point>& points) {
//     int n=points.size();
//     int res=0;
//     for(int i=0;i<n;i++)
//     {
//         Point current=points[i];
//         int res1=0;
//         map<double,int> m;//斜率与个数的映射
//         int numofcopy=0;//计算和当前重合的点的个数
//         for(int j=0;j<n;j++)
//         {
//             if(j!=i)
//             {
//                 if(current.x==points[j].x&&current.y==points[j].y)
//                 numofcopy++;
//                 else if (current.x==points[j].x)
//                 {
//                     m[(double)INT_MAX]++;
//                 }
//                 else if (current.y==points[j].y)
//                 {
//                     m[(double)0]++;
//                 }
//                 else
//                 {
//                     m[(points[j].y-current.y)*1.0/(points[j].x-current.x)]++;
//                 }
//             }
//         }
//         map<double,int>::iterator it=m.begin();
//         for(;it!=m.end();it++)
//         {
//             res1=max(res1,it->second);
//         }
//         res1=res1+numofcopy+1;
//         res=max(res1,res);
//     }
//     return res;
// }

/*
尽量的避免除法的出现,map中存储斜率分子分母对与它出现次数的映射
*/
int gcd(int x,int y)
{
    return (y==0)?x:gcd(y,x%y);
}
int maxPoints(vector<Point>& points) {
    int n=points.size();
    int res=0;
    for(int i=0;i<n;i++)
    {
        Point current=points[i];
        int res1=0;
        map<pair<int,int>,int> m;//斜率化简后的分子与分母,以及出现的次数
        int numofcopy=0;//计算和当前重合的点的个数
        for(int j=0;j<n;j++)
        {
            if(j!=i)
            {
                if(current.x==points[j].x&&current.y==points[j].y)
                numofcopy++;
                else if (current.x==points[j].x)
                {
                    m[{0,1}]++;
                }
                else if (current.y==points[j].y)
                {
                    m[{1,0}]++;
                }
                else
                {
                    int dy=points[j].y-current.y;
                    int dx=points[j].x-current.x;
                    int d=gcd(dx,dy);//求dx和dy的最大公约数
                    m[{dx/d,dy/d}]++;
                }
            }
        }
        map<pair<int,int>,int>::iterator it=m.begin();
        for(;it!=m.end();it++)
        {
            res1=max(res1,it->second);
        }
        res1=res1+numofcopy+1;
        res=max(res1,res);
    }
    return res;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<Point> points;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            Point p(x,y);
            points.push_back(p);
        }
        cout<<maxPoints(points);
    }
    return 0;
}