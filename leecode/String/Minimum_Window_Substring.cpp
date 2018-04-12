/*
Given a string S and a string T, find the minimum window in S which will contain all the 
characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique 
minimum window in S.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//注意实现的细节
string minWindow(string s, string t) {
	if (s.size() == 0 || t.size() == 0 || s.size() < t.size())
		return "";
	vector<int> tmap(256,0);//哈希表：存放t串中字符出现的次数
	vector<int> smap(256, 0);//哈希表：存放s串中字符出现的次数
	for (int i = 0; i < t.size(); i++)
	{
		tmap[t[i]]++;
	}
	int start = 0;
	int end = 0;
	int minstart = 0;//最小窗口开始位置
	int minend = 0;//最小窗口结束位置
	int minwindow = INT_MAX;//最小窗口大小
	int count = 0;//计数当前s串中出现的t中字符的个数。
	for (end = 0; end < s.size(); end++)//扫描s串，end指针不断后移。
	{ 
		if (tmap[s[end]]>0)//如果当前字符在t中存在
		{
			smap[s[end]]++;
			if (smap[s[end]] <= tmap[s[end]])//当前s串中出现的已经存在于t中的字符数还没达到t的长度
				count++;
		}
		if (count == t.size())//找到已经包含t中所有字符的窗口
		{
			while (start<end && (smap[s[start]] > tmap[s[start]] || tmap[s[start]] == 0))//不断收缩头指针，最优化窗口大小
			{
				smap[s[start]]--;
				start++;
			}
			if (minwindow > (end - start + 1))//更新窗口大小，记录最小窗口
			{
				minwindow = end - start + 1;
				minstart = start;
				minend = end;
			}
		}

	}
	if (minwindow == INT_MAX)
		return "";
	else
		return s.substr(minstart, minwindow);
}