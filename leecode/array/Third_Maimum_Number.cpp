/*
Given a non-empty array of integers, return the third maximum number in this array. 
If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//这么简单的一道题做这么久    日啊。。
//注意有个坑：考虑到数组中可能有INT_MIN的存在。因此max1 max2 max3 初始化的时候只能用LONG_MIN来初始化
int thirdMax(vector<int>& nums) {
	int n = nums.size();
	long max1 = LONG_MIN;
	long max2 = LONG_MIN;
	long max3 = LONG_MIN;
	if (n == 1)return nums[0];
	if (n == 2)return max(nums[0], nums[1]);
	for (int i = 0; i < n; i++)
	{
		if (nums[i]>max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = nums[i];
			continue;
		}
		if (max2 < nums[i] &&nums[i]< max1)//注意判断的时候不能连续写a<b<c...
		{
			max3 = max2;
			max2 = nums[i];
			continue;
		}
		if (max3 < nums[i]&&nums[i] < max2)
			max3 = nums[i];
	}
	if (max3!=LONG_MIN)
		return max3;
	else return max1;

}
/*
void main()
{
	vector<int> res;
	res.push_back(2);
	res.push_back(1);
	res.push_back(3);
	cout<<thirdMax(res);
}
*/