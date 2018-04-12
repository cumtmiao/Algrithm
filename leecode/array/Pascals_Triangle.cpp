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
	for (int row = 0; row < numRows; row++)//���Ƚ��������������Ԫ�س�ʼ��Ϊ1
	{
		vector<int> temp;
		for (int col = 0; col <= row; col++)
		{
			temp.push_back(1);
		}
		res.push_back(temp);
	}
	if (numRows == 1 || numRows == 2)//����Ϊ1����2��ʱ��ֱ�ӷ��ؽ��
		return res;

	for (int row = 2; row < numRows; row++)//����������ڵ���3���޸���Ӧ����
	{
		for (int col = 1; col < row; col++)
		{
			res[row][col] = res[row - 1][col - 1] + res[row - 1][col];
		}
	}
	return res;

}