/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
/*
本题目考察了set  unordered_set  map  unordered_map 的区别。

思路：使用hash表来保存数组中的每一个数，每次遍历到一个数的时候看往上找到所有连续的数最多有几个，
往下找比他小的数最多有几个．为了避免连续的序列中的数重复查找，在找到一个相邻的数之后就把他从hash表中删除，
也就是一个连续的序列只会被查找一次．因此时间复杂度为O(n)．
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>//注意在c++11之前使用unordered_map要使用以下格式
using namespace std;
using namespace std::tr1;
int longestConsecutive(vector<int>& nums) {
    const int length=nums.size();
    unordered_map<int,bool> hash;
    for(int i=0;i<length;i++)//将vector中的元素存放到unordered_map中
    {
        hash[nums[i]]=true;
    }
    int res=0;
    for(int i=0;i<length;i++)
    {
        int currentvalue=nums[i];
        int len=0;
        //从currentvalue开始往上查找。注意connt 函数和find函数的区别，count函数查找该键值是否在哈希表中存在，
        //返回值只有0和1两种，而find函数的返回值为迭代器。
        while(hash.count(currentvalue))
        {
            len++;
            hash.erase(currentvalue);
            currentvalue++;
        }
        currentvalue=nums[i]-1;
        while(hash.count(currentvalue))//从currentvalue开始往下查找。
        {
            len++;
            hash.erase(currentvalue);
            currentvalue--;
        }
        res=max(res,len);
    }
    return res;

}
int main()
{
    vector<int> data;
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            data.push_back(temp);
        }
        cout<<longestConsecutive(data);
    }
    return 0;
}