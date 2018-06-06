/*
Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

Return true if and only if she can.
 
Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.
Note:

1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length
*/
#include<bits/stdc++.h>
using namespace std;
/*
本题目考察map的使用
*/
bool isNStraightHand(vector<int>& hand, int W) {
    int n=hand.size();
    if(n%W!=0)
    return false;
    map<int, int> m;//存放每个元素与它出现的次数的对应值
    for(int i=0;i<n;i++)
    {
        m[hand[i]]++;
    }
    map<int,int>::iterator it=m.begin();
    if(m.size()<W)
    return false;
    while(m.size()>=W)
    {
        it=m.begin();
        int beforefirst=it->first;//记录前一个位置的pair第一个元素值
        int beforesecond=it->second;//记录前一个位置的pair的第二个元素值
        it->second=it->second-1;
        it++;
        for(int i=1;i<W;i++,it++)
        {
            if(it->first!=beforefirst+1)//判断是不是连续的
            return false;
            else
            {
                if(it->second<beforesecond)//第二个元素必须是非降的序列
                return false;
                else{
                    beforefirst=it->first;
                    beforesecond=it->second;
                    it->second=it->second-1;
                }

            }
        }
        it=m.begin();
        for(int i=0;i<W&&it->second==0;i++,it++)//删除第二个元素值为0的pair
        m.erase(it->first);
    }
    if(m.empty())
    return true;
    else
    return false;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int W;
        cin>>W;
        vector<int> hand;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            hand.push_back(temp);
        }
        cout<<isNStraightHand(hand,W);
    }
    return 0;
}