/*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into
a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and
c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same 
row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; 
Otherwise, output the original matrix.

Example 1:
Input:
nums =
[[1,2],
[3,4]]
r = 1, c = 4
Output:
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input:
nums =
[[1,2],
[3,4]]
r = 2, c = 4
Output:
[[1,2],
[3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
*/
#include<iostream>
#include<vector>
using namespace std;
//注意vector的初始化
vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
	vector<vector<int>>res(r,vector<int>(c,0));
	int n = nums.size();//行数
	if (n == 0)return nums;
	int m = nums[0].size();//列数
	if (r*c != m*n)return nums;
	else
	{
		vector <int> temp(m*n, 0);
		vector<int>::iterator it=temp.begin();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				temp[i*m+j]=nums[i][j];
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				res[i][j] = *it;
				it++;
			}
		}
	}
	return res;
}
/*
void main()
{
	vector<vector<int>> nums(4,vector<int>(1, 0));
	int k = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			nums[i][j] = k++;
		}
	}
	matrixReshape(nums, 2, 2);
}
*/