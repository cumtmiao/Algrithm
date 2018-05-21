/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.
*/
#include<bits/stdc++.h>
using namespace std;
/*
没用到有序的特性：
建立一个大小为K的最大堆。
空间复杂度O(K),时间复杂度O(N^2);
*/
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n=matrix.size();
    vector<int> heap;//最大堆
    int num=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            num++;
            if(num<=k)
            {
                heap.push_back(matrix[i][j]);
                push_heap(heap.begin(),heap.end(),less<int>());
            }
            else
            {
                if(matrix[i][j]<heap[0])
                {
                    pop_heap(heap.begin(),heap.end(),less<int>());
                    heap.pop_back();
                    heap.push_back(matrix[i][j]);
                    push_heap(heap.begin(),heap.end(),less<int>());
                }
            }
        }
    }
    return heap[0];
}