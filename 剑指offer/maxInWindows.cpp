/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
 {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/
#include<bits/stdc++.h>
using namespace std;
 vector<int> maxInWindows(const vector<int>& num, unsigned int size)//解法一：暴力方法
    {
        vector<int> res;
        int len=num.size();
        if(size<1||len<size)
        return res;
        int maxsum=INT_MIN;
        int i;
        for(int j=0;j<len-size+1;j++)
        {
            maxsum=INT_MIN;
            for(i=j;i<j+size;i++)
          {
            if(num[i]>maxsum)
            maxsum=num[i];
          }
        res.push_back(maxsum);
        }
        return res;
    }
    /*
    思路二的双向队列所存储的是：候选的最大值的索引。队头的索引指向的值比后面索引指向的值大。
    例如当前考虑的值为num[i]，只要num[i]比队尾指向的值大，则那些值不可能再成为最大值，此时这些值出队；
    如果队头的索引距离i超过了size，则表示当前对头不再成为最大值，出队；
    当前的i入队；
    最后更新res;
    */
 vector<int> maxInWindows(const vector<int>& num, unsigned int size)//解法二：利用双向队列，时间复杂度为O(n)的解法
    {
        vector<int> res;
        int len=num.size();
        deque <int> q;
        if(size<1||len<size)
        return res;
        for(int i=0;i<len;i++)
        {
            while(!q.empty()&&num[i]>=num[q.back()])//只要当前的值比队尾的值大，则队尾值不再可能是最大值，队尾值出队。
            q.pop_back();//双向队列从队尾出队；
            while(!q.empty()&&i-q.front()>=size)//只要当前元素的索引与队头的最大值之间的距离超过了size，则队头出队。
            q.pop_front();//双向队列从队头出队；
            q.push_back(i);//双向队列从队尾加入元素。
            if(size&&i+1>=size)
            res.push_back(num[q.front()]);
        }
        return res;
    }

