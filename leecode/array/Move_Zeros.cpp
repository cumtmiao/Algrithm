/*
Given an array nums, write a function to move all 0's to the end of it while maintaining 
the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
#include<iostream>
#include<vector>
using namespace std;
void exchange(int & a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
//��������Ȼ���԰�0�Ƶ�ĩβ�����Ƿ�0Ԫ�ص����λ�û�ı䣬���������⡣
void moveZeros(vector<int> &nums)
{
	int n = nums.size();
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		if (nums[end] == 0)
		{
			end--;
		}
		else if (nums[start] == 0)
		{
			exchange(nums[start], nums[end]);
			start++;
			end--;
		}
		else
			start++;
	}

}
//����˼�룺
//��������ָ�룺��һ��ָ��������0Ԫ�أ��ڶ���ָ�������ҵ�һ��ָ����һ����0Ԫ�أ��ҵ�֮������Ԫ�ؽ�����
void moveZeros1(vector<int> &nums)
{
	int n = nums.size();
	int start = 0;
	int second = 0;
	while (second <= n - 1)
	{
		if (nums[start] != 0)
		{
			start++;
			second++;
		}
		else
		{
			while (second <= n - 1 && nums[second] == 0)
			{
				second++;
			}
			if (second <= n - 1)
				exchange(nums[start], nums[second]);
		}
	}

}
/*
void main()
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(3);
	nums.push_back(0);
	nums.push_back(5);
	nums.push_back(1);
	nums.push_back(0);
	moveZeros1(nums);
}
*/