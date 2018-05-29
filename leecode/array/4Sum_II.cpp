/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are 
such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. 
All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/
#include<bits/stdc++.h>
using namespace std;
/*
暴力方法：O(N^4);不能AC
*/
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int N=A.size();
    int num=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                for(int l=0;l<N;l++)
                {
                    if(A[i]+B[j]+C[k]+D[l]==0)
                    num++;
                }
            }
        }
    }
    return num;
}

/*
一种O(N^2)的方法
*/
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int N=A.size();
    // sort(A.begin(),A.end());
    // sort(B.begin(),B.end());
    // sort(C.begin(),C.end());
    // sort(D.begin(),D.end());
    map<int,int> m1;
    map<int,int> m2;
    int num=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            m1[A[i]+B[j]]++;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            m2[C[i]+D[j]]++;
        }
    }
    map<int,int>::iterator it1=m1.begin();
    for(;it1!=m1.end();it1++)
    {
        map<int,int>::iterator it2=m2.find(0-(it1->first));
        if(it2!=m2.end())
        {
            num+=(it1->second)*(it2->second);
        }
    }
    return num;
}
/*
一种O(N^2)方法的改进
*/
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int N=A.size();
    map<int,int> m1;
    int num=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            m1[A[i]+B[j]]++;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int target=(-1)*(C[i]+D[j]);
            num+=m1[target];
        }
    }
    return num;
}

