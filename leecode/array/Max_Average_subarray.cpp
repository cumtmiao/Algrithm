/*
Given an array consisting of n integers, 
find the contiguous subarray of given length k that has the maximum average value.
And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/
#include<iostream>
using namespace std;
double MaxAverageSubarray(int *p,int n,int k)
{
	int max=0;
	int current;
	for (int i = 0; i < n-k; i++)
	{
		current = 0;
		for (int j = 0; j < k; j++)
		{
			current = current + p[j];
			
		}
		if (current>max)max = current;

	}
	return max*1.0 / k;
}

void main()
{
	int p[6] = { 1, 12, -5, -6, 50, 3 };
	cout << MaxAverageSubarray(p,6,4);
}