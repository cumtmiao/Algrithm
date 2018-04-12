/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//不能用abs函数，因为得根据localsum和target的大小关系来决定是应该lo++
//还是hi--;
int threeSumClosest(vector<int>& nums, int target) {
	int n = nums.size();
	int cloestnumber = INT_MAX;//表示最小与target差多少
	int sum = 0;//表示最接近target的和
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n - 2; i++)
	{
		int lo = i + 1;
		int hi = n - 1;
		while (lo < hi)
		{
			int locolsum = nums[i] + nums[lo] + nums[hi];
			if (locolsum< target)
			{
				if (target - locolsum < cloestnumber)
				{
					cloestnumber = target - locolsum;
					sum = locolsum;
				}
				lo++;
			}
			else if (locolsum > target)
			{
				if (locolsum - target < cloestnumber)
				{
					cloestnumber = locolsum - target;
					sum = locolsum;
				}
				hi--;
			}
			else
				return target;
			
		}
	}
	return sum;
}
/*
void main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-3);
	cout << threeSumClosest(nums, 1);
}
*/