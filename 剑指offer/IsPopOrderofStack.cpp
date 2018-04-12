/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/

/*
解题思路：
1.利用辅助栈；
2.遍历出栈序列，假设当前遍历到的是popV[i],只要（while）栈为空或者popV[i]与栈顶元素不相等，则从入栈序列中入栈一个元素；
当栈顶元素和popV[i]相等时，栈顶元素出栈，继续访问出栈队列的下一个元素；
3.当从入栈队列中找不到即将出栈的元素时，则返回false。
*/
#include<bits/stdc++.h>
using namespace std;
 bool IsPopOrder(vector<int> pushV,vector<int> popV)
 {
     if(pushV.size()==0||popV.size()==0||pushV.size()!=popV.size())
     return false;
     stack<int> s;
     int j=0;
     for(int i=0;i<popV.size();i++)//遍历出栈队列
     {
         
         while(s.empty()||s.top()!=popV[i])//当辅助栈为空，或者栈顶元素与当前访问的出栈元素不相等时，从入栈队列中入栈一个元素。
         {
             s.push(pushV[j]);
             j++;
             if(j>popV.size())
             return false;
         }
         if(s.top()==popV[i])//当栈顶元素与popV[i]相等时，辅助栈出栈一个元素
         {
             s.pop();
         }          
     }
     return true;
 }