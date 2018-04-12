/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
//本题采用递归的思路来求解。通过！
#include<bits/stdc++.h>
using namespace std;
bool VerifySquenceOfBSTCore(int* start,int* end)
{
    if(start>=end)
    return true;     
    int* i=start;
    while(i<end)
    {
        if(*i<*end)
        i++;
        else
        break;
    }   
    int* j=i;
    while(j<end)
    {
        if(*j<*end)
        return false;
        j++;
    }       
    return VerifySquenceOfBSTCore(start,i-1)&&VerifySquenceOfBSTCore(i,end-1);

}
   bool VerifySquenceOfBST(vector<int> sequence) {
       int len=sequence.size();
       if(len==0)
       return false;
       return VerifySquenceOfBSTCore(&sequence[0],&sequence[len-1]);
    }

    int  main()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(2);
        v.push_back(5);
        v.push_back(8);
        v.push_back(7);
        v.push_back(4);
        cout<<VerifySquenceOfBST(v);
        getchar();
        return 0;
    }