/*
 小美想要在电视上看电影，我们知道在电视上搜索电影可以通过搜索电影名字首字母缩写得到，通过首字母搜索电影的界面由一个
 九宫格组成，如下图：

@!: ABC DEF 

GHI JKL MNO

PQRS TUV WXYZ
光标初始在这个九宫格的左上方，也就是在 “@!:”的位置，每次小美想要输入一个字母，需要通过不断地按上下左右四个方向键
(并且只能按方向键），把光标从当前所在的格子移动到目标的格子(也就是待输入的字母所在的格子)，然后在目标的格子上通过
其他的按键来输入字母。小美觉得频繁地按方向键是十分烦人的事情，所以她想设计一种移动光标方案使得方向键按的次数最少。
问最少要几次?
小美想看 T 部电影，所以她会问你 T 个电影名字的缩写分别需要多少次输入。
注意在一个电影名字输入完以后，光标会回到左上角，期间按的方向键不会计入答案。

输入描述:
第一行一个T(T ≤ 10)，表示小美想看的电影数。
接下来 T 行，每行一个长度不超过100,000的字符串，表示一部电影名字的缩写，保证缩写的每个字符都是大写英文字母。
输出描述:
对于每个电影名字缩写，输出输入这个名字的最小按方向键的次数。
示例1
输入
2
AA
AT
输出
1
3
*/
#include<bits/stdc++.h>
using namespace std;
int distances(char x,char y)
{
    char a=x<=y?x:y;
    char b;
    if(a==x)
    b=y;
    else
    b=x;
    if(a=='A'||a=='B'||a=='C')
    {
        if(b=='A'||b=='B'||b=='C')
        return 0;
        if(b=='D'||b=='E'||b=='F'||b=='J'||b=='K'||b=='L')
        return 1;
        if(b=='G'||b=='H'||b=='I'||b=='T'||b=='U'||b=='V'||b=='M'||b=='N'||b=='O')
        return 2;
        if(b=='P'||b=='Q'||b=='R'||b=='S'||b=='W'||b=='X'||b=='Y'||b=='Z')
        return 3;
    }
    else if (a=='D'||a=='E'||a=='F')
    {
        if(b=='D'||b=='E'||b=='F')
        return 0;
        if(b=='M'||b=='N'||b=='O')
        return 1;
        if(b=='J'||b=='K'||b=='L'||b=='W'||b=='X'||b=='Y'||b=='Z')
        return 2;
        if(b=='G'||b=='H'||b=='I'||b=='T'||b=='U'||b=='V')
        return 3;
        if(b=='P'||b=='Q'||b=='R'||b=='S')
        return 4;
    }
    else if (a=='G'||a=='H'||a=='I')
    {
        if(b=='G'||b=='H'||b=='I')
        return 0;
        if(b=='J'||b=='K'||b=='L'||b=='P'||b=='Q'||b=='R'||b=='S')
        return 1;
        if(b=='M'||b=='N'||b=='O'||b=='T'||b=='U'||b=='V')
        return 2;
        if(b=='W'||b=='X'||b=='Y'||b=='Z')
        return 3;
    }
    else if (a=='J'||a=='K'||a=='L')
    {
        if(b=='J'||b=='K'||b=='L')
        return 0;
        if(b=='M'||b=='N'||b=='O'||b=='T'||b=='U'||b=='V')
        return 1;
        if(b=='P'||b=='Q'||b=='R'||b=='S'||b=='W'||b=='X'||b=='Y'||b=='Z')
        return 2; 
    }
    else if (a=='M'||a=='N'||a=='O')
    {
        if(b=='M'||b=='N'||b=='O')
        return 0;
        if(b=='W'||b=='X'||b=='Y'||b=='Z')
        return 1;
        if(b=='T'||b=='U'||b=='V')
        return 2;
        if(b=='P'||b=='Q'||b=='R'||b=='S')
        return 3;
    }
    else if (a=='P'||a=='Q'||a=='R'||a=='S')
    {
        if(b=='P'||b=='Q'||b=='R'||b=='S')
        return 0;
        if(b=='T'||b=='U'||b=='V')
        return 1;
        if(b=='W'||b=='X'||b=='Y'||b=='Z')
        return 2;
    }
    else if (a=='T'||a=='U'||a=='V')
    {
        if(b=='T'||b=='U'||b=='V')
        return 0;
        if(b=='W'||b=='X'||b=='Y'||b=='Z')
        return 1;
    }
    return 0;
}
int calcualtions(char str)
{
    map<char,int> chushi;//每个元素距离初始位置的距离
    chushi['A']=1;chushi['B']=1;chushi['C']=1;
    chushi['G']=1;chushi['H']=1;chushi['I']=1;
    chushi['D']=2;chushi['E']=2;chushi['F']=2;
    chushi['J']=2;chushi['K']=2;chushi['L']=2;
    chushi['P']=2;chushi['Q']=2;chushi['R']=2;chushi['S']=2;
    chushi['M']=3;chushi['N']=3;chushi['O']=3;
    chushi['T']=3;chushi['U']=3;chushi['V']=3;
    chushi['W']=4;chushi['X']=4;chushi['Y']=4;chushi['Z']=4;
    int res=chushi[str];
    return res;
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            string tempstr;
            cin>>tempstr;
            int tempres=0;
            tempres+=calcualtions(tempstr[0]);
            for(int j=0;j<tempstr.size()-1;j++)
            {
                tempres+=distances(tempstr[j],tempstr[j+1]);
            }
            cout<<tempres<<endl;
        }

    }
    return 0;
}

// int getN(char c){
//     if(c=='@'||c=='!'||c==':'){
//         return 0;
//     }
//     if(c=='A'||c=='B'||c=='C'){
//         return 1;
//     }
//     if(c=='D'||c=='E'||c=='F'){
//         return 2;
//     }
//     if(c=='H'||c=='I'||c=='G'){
//         return 3;
//     }
//     if(c=='J'||c=='K'||c=='L'){
//         return 4;
//     }
//     if(c=='M'||c=='N'||c=='O'){
//         return 5;
//     }
//     if(c=='P'||c=='Q'||c=='R'||c=='S'){
//         return 6;
//     }
//     if(c=='T'||c=='U'||c=='V'){
//         return 7;
//     }
//     if(c=='W'||c=='X'||c=='Y'||c=='Z'){
//         return 8;
//     }
//     return 0;
// }
// vector<string> str;
// int main(){
//     int n;
//     cin >> n;
//     string ss;
//     for(int i=0; i<n ; i++){
//         cin >> ss;
//         ss = '@' + ss;
//         int ans = 0;
//         for(int i = 0; i < ss.length()-1; i ++)
//         {
//             int x = getN(ss[i]);
//             int y = getN(ss[i+1]);
//             ans += abs(x / 3 - y / 3);
//             ans += abs(x % 3 - y % 3);
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }