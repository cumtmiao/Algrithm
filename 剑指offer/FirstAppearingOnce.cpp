/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/
/*
思路：

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    Solution():index(0)
    {
        for(int i=0;i<256;i++)//数组初始化为-1；
        {
            occurance[i]=-1;
        }
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
         if(occurance[ch]==-1)//字符第一次出现时，对应的哈希值为它的索引。索引最小的那个字符即为字符流第一个只出现一次的字符
         {
             occurance[ch]=index;
         }
         else if(occurance[ch]>=0)//字符第二次出现，将哈希值赋值为-2；
         {
             occurance[ch]=-2;
         }
         index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int min=INT_MAX;
        char ch;
        for(int i=0;i<256;i++)
        {
            if(occurance[i]>=0&&occurance[i]<min)//找到大于等于0的最小的哈希值对应的字符即为我们要找的字符。
            {
                min=occurance[i];
                ch=(char)i;
            }           
        }
        if(min!=INT_MAX)
        return ch;
        else
        return '#';
    }
private:
//occurance[i]:ASCII码值为i的字符出现的次数；
//occurance[i]=-1:该字符出现的次数为0次
//occurance[i]=-2:该字符出现的次数为两次及以上
//occurance[i]>=0:该字符出现的次数为一次
 int index;
 int occurance[256];
};