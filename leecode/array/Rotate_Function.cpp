/*
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation 
function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
*/
#include<bits/stdc++.h>
using namespace std;
/*
暴力解法O(n^2)超时:AC 16/17
*/
void rotateonestep(vector<int>& A)
{
    vector<int> B;
    for(int i=0;i<A.size();i++)
    {
        B.push_back(A[i]);
    }
    A[0]=B[A.size()-1];
    for(int i=1;i<A.size();i++)
    {
        A[i]=B[i-1];
    }
}
int maxRotateFunction(vector<int>& A) {
    int res=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        res+=i*A[i];
    }
    for(int i=1;i<n;i++)
    {
        rotateonestep(A);
        // for(int i=0;i<n;i++)
        // cout<<A[i]<<' ';
        // cout<<endl;
        int temp=0;
        for(int j=0;j<n;j++)
        {
            temp+=j*A[j];
        }
        res=max(res,temp);
    }
    return res;   
}
/*
找到数学规律：
我们为了找规律，先把具体的数字抽象为A,B,C,D，那么我们可以得到：
F(0) = 0A + 1B + 2C +3D
F(1) = 0D + 1A + 2B +3C
F(2) = 0C + 1D + 2A +3B
F(3) = 0B + 1C + 2D +3A
那么，我们通过仔细观察，我们可以得出下面的规律：
F(1) = F(0) + sum - 4D
F(2) = F(1) + sum - 4C
F(3) = F(2) + sum - 4B
那么我们就找到规律了：
F(i) = F(i-1) + sum - n*A[n-i]
*/
int maxRotateFunction(vector<int>& A) {
    int sum=0;
    int n=A.size();
    int res=0;
    for(int i=0;i<n;i++)
    {
        res+=i*A[i];//先求出F0
        sum+=A[i];
    }
    int front=res;
    for(int i=1;i<n;i++)
    {
        int temp=front+sum-n*A[n-i];
        res=max(res,temp);
        front=temp;
    }
    return res;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> nums;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        cout<<maxRotateFunction(nums);
    }
    return 0;
}