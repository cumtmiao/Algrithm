/*
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5
示例1
输入
1,2,3,4,5,6,7,0
输出
7
*/
/*
  思路：
    看到这个题目，我们的第一反应是顺序扫描整个数组。没扫描到一个数组的时候，逐个比较该数字和它后面的数字的大小。
  如果后面的数字比它小，则这两个数字就组成了一个逆序对。假设数组中含有n个数字。由于每个数字都要和O(n)这个数字比较，
  因此这个算法的时间复杂度为O(n^2)。
    我们以数组{7,5,6,4}为例来分析统计逆序对的过程。每次扫描到一个数字的时候，我们不拿ta和后面的每一个数字作比较，
    否则时间复杂度就是O(n^2)，因此我们可以考虑先比较两个相邻的数字。
(a) 把长度为4的数组分解成两个长度为2的子数组；
(b) 把长度为2的数组分解成两个成都为1的子数组；
(c) 把长度为1的子数组 合并、排序并统计逆序对 ；
(d) 把长度为2的子数组合并、排序，并统计逆序对；
实际上考察归并排序；
注意:数据量比较大的时候用long或者long long，int 不一定够
*/
#include<bits/stdc++.h>
using namespace std;
int InversePairsCore(vector<int> &data,vector<int> &copy,long start,long end)
{
    if(start==end)
    {
        copy[start]=data[start];
        return 0;
    }
    long length=(end-start)>>1;
    long left=InversePairsCore(copy,data,start,start+length);//--注意：copy与data反着赋值。
    long right=InversePairsCore(copy,data,start+length+1,end);
    long count=0;
    long i=start+length;
    long j=end;
    long indexcopy=end;
    while(i>=start&&j>=start+length+1)
    {
        if(data[i]>data[j])
        {
            count+=j-start-length;
            copy[indexcopy--]=data[i--];
        }
        else
        {
            copy[indexcopy--]=data[j--];
        }
    }
    for(;j>=start+length+1;)
    {
        copy[indexcopy--]=data[j--];
    }
    for(;i>=start;)
    {
        copy[indexcopy--]=data[i--];
    }
    return (left+right+count)%1000000007;
}
int InversePairs(vector<int> data) {
    int length=data.size();
    if(length<=1)
    return 0;
    vector<int> copy;
    for(int i=0;i<length;i++)
    {
        copy.push_back(data[i]);
    }
   return  InversePairsCore(data,copy,0,length-1);

}