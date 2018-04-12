/*
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows) {
	vector<vector<int>> res;
	if (numRows == 0) return res;
	for (int row = 0; row < numRows; row++)//首先将杨辉三角形所有元素初始化为1
	{
		vector<int> temp;
		for (int col = 0; col <= row; col++)
		{
			temp.push_back(1);
		}
		res.push_back(temp);
	}
	if (numRows == 1 || numRows == 2)//行数为1或者2的时候，直接返回结果
		return res;

	for (int row = 2; row < numRows; row++)//如果行数大于等于3，修改相应数据
	{
		for (int col = 1; col < row; col++)
		{
			res[row][col] = res[row - 1][col - 1] + res[row - 1][col];
		}
	}
	return res;

}