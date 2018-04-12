/*
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,
哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
本问题即约瑟夫环问题。
*/
//解法一：利用list实现环形链表。
#include<bits/stdc++.h>
using namespce std;
  int LastRemaining_Solution(int n, int m)
  {
      if(n<1||m<1)
      return -1;
      list<int> numbers;     
      for(int i=0;i<n;i++)//环初始化
      {
          numbers.push_back(i);
      }
      list<int>::iterator cur=numbers.begin();
      while(numbers.size()>0)
      {
          for(int i=0;i<m-1;i++)
          {
              cur++;
              if(cur==numbers.end())
              {
                  cur=numbers.begin();
              }
          }
          list<int>::iterator next=++cur;
          if(next==numbers.end())
          next=numbers.begin();
          cur--;
          numbers.erase(cur);
          cur=next;
      }
      return *cur;

  }
/*
通过数学分析，最后可以得到一个递推公式：
f(n,m)=0  if n=1,
f(n,m)=[f(n-1,m)+m]%n if n>1
f(n,m)表示：在n个数字0,1,...n-1中删除第m个数字后最后剩下的数字
*/
  int LastRemaining_Solution2(int n, int m)
  {
      if(n<1||m<1)
      return -1;
      int last=0;
      for(int i=2;i<=n;i++)
      {
          last=(last+m)%i;
      }
      return last;

  }

 