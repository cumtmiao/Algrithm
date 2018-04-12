/*
有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，
将图像顺时针旋转90度。
给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于500，图像元素小于等于256。
测试样例：
[[1,2,3],[4,5,6],[7,8,9]],3
返回：[[7,4,1],[8,5,2],[9,6,3]]
*/
#include<bits/stdc++.h>
using namespace std;
/*
先主对角线堆成的元素交换；
再列交换。
*/
vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {//相当于进行了两次变换
    // write code here
    if(n==0)
    return mat;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i!=j)
            {
                int temp;
                temp=mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int left=0;int right=n-1;
        while(left<right)
        {
            int temp;
            temp=mat[i][left];
            mat[i][left]=mat[i][right];
            mat[i][right]=temp; 
            left++;
            right--;
        }
    }
    return mat;
}
