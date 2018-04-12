/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��nums[i]ǰ����������Ƿ���������Ӱ�죺
//����ǲ�������Ӱ����maxsum = maxsum + nums[i];����maxsum = nums[i];
//��res����¼����maxsum��ֵ
int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int maxsum = nums[0];
	int res = nums[0];
	for (int i = 1; i < n; i++)
	{
		if (maxsum>=0)maxsum = maxsum + nums[i];
		else maxsum = nums[i];
		res = max(res, maxsum);
	}
	return res;
}