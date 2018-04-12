/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> multiply(const vector<int>& A) 
{
    vector<int> B;
    vector<int> C;
    int* D=new int[A.size()];
    if(A.size()==0)
    return B;
    int sumc=1;
    C.push_back(1);
    for(int i=1;i<A.size();i++)//算数组C的相应值
    {
        sumc=sumc*A[i-1];
        C.push_back(sumc);
      
    }
    
    int sumd=1;
    D[A.size()-1]=1;
    for(int i=A.size()-2;i>=0;i--)//算数组D的相应值
    {
        sumd=sumd*A[i+1];
        D[i]=sumd;  
             
    }
    for(int i=0;i<A.size();i++)//算数组B，并返回。
    {
        B.push_back(C[i]*D[i]);
        cout<<B[i]<<' ';
    }
    return B;
}

int main()
{
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
    multiply(s);
    getchar();
    return 0;
}