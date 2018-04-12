/*
题目描述
如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
{1, 2, 1}, {15, 78, 78, 15} , {112} 是回文序列, 
{1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} 不是回文序列。
现在给出一个数字序列，允许使用一种转换操作：
选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。
输入描述:
输入为两行，第一行为序列长度n ( 1 ≤ n ≤ 50) 第二行为序列中的n个整数item[i] (1 ≤ iteam[i] ≤ 1000)，
以空格分隔。
输出描述:
输出一个数，表示最少需要的转换次数
示例1
输入

4 1 1 1 3
输出

2
*/
/*
思路：
想要转换的步数尽可能少，则应该尽快让左指针指向的数和右指针指向的数相等，--相当于向回文串迈进一步。
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> item;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        item.push_back(temp);
    }
    int left=0;
    int right=item.size()-1;
    int step=0;//记录需要转换的次数
    while(left<right)
    {
        if(item[left]<item[right])//左指针指向的数比较小的时候，合并一步-相当于转换一步
        {
            step++;
            left++;
            item[left]=item[left]+item[left-1];
        }
        else if (item[left]>item[right])//右指针指向的数比较小的时候，右边合并一步，step++。
        {
            step++;
            right--;
            item[right]=item[right]+item[right+1];
        }
        else//相等时候step不变，左指针右移，右指针左移。
        {
            left++;
            right--;
        }
    }
    cout<< step;
    return 0;
}