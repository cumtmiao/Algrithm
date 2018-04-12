/*
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//典型的动态规划方法。利用下一层的数来求当前层的数。
int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size();
	if (n == 0)return 0;
	vector<int> minisum(n, 0);
	for (int i = 0; i < n; i++)
	{
		minisum[i] = triangle[n - 1][i];
	}
	for (int row = n - 2; row >= 0; row--)
	{
		for (int col = 0; col <= row; col++)
		{
			minisum[col] = triangle[row][col] + min(minisum[col], minisum[col + 1]);

		}
	}
	return minisum[0];

}
