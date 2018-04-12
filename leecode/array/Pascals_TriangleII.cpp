/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
#include<iostream>
#include<vector>
using namespace std;
//动态规划的思想
vector<int> getRow(int rowIndex) {
	vector<int> res(rowIndex + 1, 1);
	vector<int> res2(rowIndex + 1, 1);//中间数组，用来保存中间结果，以免res更新给自身带来影响
	if (rowIndex == 0 || rowIndex == 1)
		return res;
	for (int i = 2; i <= rowIndex; i++)//行
	{
		for (int j = 1; j < i; j++)//列
		{
			res2[j] = res[j - 1] + res[j];
		}	
		res = res2;
	}
	return res;
}
/*
void main()
{
	getRow(3);
}
*/