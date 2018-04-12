/*
题目描述
继MIUI8推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：首先将电话号码中的每个数字加上8取个位，
然后使用对应的大写字母代替 （"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"），
 然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。
输入描述:
第一行是一个整数T（1 ≤ T ≤ 100)表示测试样例数；接下来T行，每行给定一个分身后的电话号码的分身（长度在3到10000之间）。
输出描述:
输出T行，分别对应输入中每行字符串对应的分身前的最小电话号码（允许前导0）。
示例1
输入

4
EIGHT
ZEROTWOONE
OHWETENRTEO
OHEWTIEGTHENRTEO
输出

0
234
345
0345
*/

/*
找规律，找到字符串中唯一出现的字符。比较麻烦
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    while(cin>>t)
    {
        vector<int> res;
        for(int i=0;i<t;i++)
        {
            string str;
            cin>>str;
            map <char,int> m;
            int hash[10];
            memset(hash,0,sizeof(hash));
            for(int i=0;i<str.size();i++)
            {
                m[str[i]]++;
            }
            while(m['Z']>0)
            {
                m['Z']--;
                m['E']--;
                m['R']--;
                m['O']--;
                hash[0]++;
            }
            while(m['W']>0)
            {
                m['T']--;
                m['W']--;
                m['O']--;
                hash[2]++;
            }
            while(m['U']>0)
            {
                m['F']--;
                m['O']--;
                m['U']--;
                m['R']--;
                hash[4]++;
            }
            while(m['X']>0)
            {
                m['S']--;
                m['I']--;
                m['X']--;
                hash[6]++;
            }
            while(m['G']>0)
            {
                m['E']--;
                m['I']--;
                m['G']--;
                m['H']--;
                m['T']--;
                hash[8]++;
            }
            while(m['T']>0)
            {
                m['T']--;
                m['H']--;
                m['R']--;
                m['E']--;
                m['E']--;
                hash[3]++;
            }
            while(m['S']>0)
            {
                m['S']--;
                m['E']--;
                m['V']--;
                m['E']--;
                m['N']--;
                hash[7]++;
            }
            while(m['F']>0)
            {
                m['F']--;
                m['I']--;
                m['V']--;
                hash[5]++;
            }
             while(m['O']>0)
            {
                m['O']--;
                m['N']--;
                m['E']--;
                hash[1]++;
            }
            while(m['N']>0)
            {
                m['N']--;
                m['I']--;
                m['N']--;
                m['E']--;
                hash[9]++;
            }
            while(hash[8]>0)
            {
                hash[8]--;
                cout<<0;
            }
            while(hash[9]>0)
            {
                hash[9]--;
                cout<<1;
            }
            for(int i=0;i<=7;i++)
            {
                while(hash[i]!=0)
                {
                    hash[i]--;
                    cout<<i+2;
                }
            }
            cout<<endl;
        }
    }
    return 0;

}