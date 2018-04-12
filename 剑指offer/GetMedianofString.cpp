/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {//最简单的一种解法：插入的时间复杂度为O(1),得到中位数的时间复杂度为O(nlgn)--最好可以优化到O(n)
public:
vector<int> numbers;
    void Insert(int num)
    {
        numbers.push_back(num);
    }

    double GetMedian()
    { 
        sort(numbers.begin(),numbers.end());
        if(numbers.size()%2==1)
        {
            return numbers[(numbers.size())>>1];
        }
        else
        {
             double right=numbers[numbers.size()>>1];
            double left=numbers[(numbers.size()>>1)-1];
            return ((left+right)/2);
        }
    }

};

/*
思路二：利用最小堆和最大堆来实现。
最小堆：堆顶始终保持着当前堆的最小元素；--表示数据流的右半部分
最大堆：堆顶始终保持着当前堆的最大元素。--表示数据流的左半部分
为了实现找到中位数，最大堆与最小堆中的元素数目之差不能超过1。--实现时，当元素数量为偶数时，插入最小堆，否则插入最大堆
该算法的时间复杂度：
插入一个数据的时间复杂度为O(lgn)
查找中位数的时间复杂度为O(1)
*/
class Solution {
public:
    vector<int> min;//最小堆
    vector<int> max;//最大堆
    void Insert(int num)
    {
        if(((min.size()+max.size())&1)==0)//当前元素数量为偶数，插入最小堆
        {
            if(max.size()>0&&num<max[0])//如果当前即将插入最小堆的元素比最大堆的堆顶元素还小，那它需要先插入最大堆。
            {
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<int>());//调整最大堆，使最大的元素位于堆顶。
                num=max[0];
                pop_heap(max.begin(),max.end(),less<int>());//调整堆，弹出堆顶元素
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<int>());
        }
        else//当前元素数量为奇数，插入最大堆。
        {
            if(min.size()>0&&num>min[0])
            {
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<int>());
                num=min[0];
                pop_heap(min.begin(),min.end(),greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(),max.end(),less<int>());
        }
    }

    double GetMedian()
    {       
        int size=min.size()+max.size();
        double median;
        if((size&1)==0)
        {
            median=(min[0]+max[0])*1.0/2;
        }
        else
        median=min[0]*1.0;
        return median;
    }

};