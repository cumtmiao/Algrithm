/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval{
	int start;
	int end;
	Interval() :start(0), end(0){}
	Interval(int s, int e) :start(s), end(e){}
};
bool isless(Interval &a,Interval &b)
{
	return a.start < b.start ? true : false;
}
//这里注意STL sort()函数的用法
vector<Interval> merge(vector<Interval>& intervals) {
	int n = intervals.size();
	vector<Interval> res;
	if (n == 0)return res;
	sort(intervals.begin(), intervals.end(), isless);
	Interval cur = intervals[0];
	for (int i = 1; i < n; i++)
	{
		if (intervals[i].start>cur.end)
		{
			res.push_back(cur);
			cur = intervals[i];
		}
		else
		{
			if (intervals[i].end > cur.end)
				cur.end = intervals[i].end;
		}
	}
	res.push_back(cur);
	return res;
}