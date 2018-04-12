/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//基本思想见这篇博客http://blog.csdn.net/zxzxy1988/article/details/8587244
double findkth(vector<int> nums1, vector<int> nums2,int k)
{
	int m = nums1.size();
	int n = nums2.size();
	if (m > n)
		return findkth(nums2, nums1, k);
	if (m == 0)
		return nums2[k - 1];
	if (k == 1)
		return min(nums1[0], nums2[0]);
	int pa = min(k / 2, m);
	int pb = k - pa;
	//int pb = min(k/2,n);
	if (nums1[pa - 1] < nums2[pb - 1])
		return findkth(vector<int>(nums1.begin() + pa, nums1.end()), nums2, k - pa);
	else if (nums1[pa - 1]>nums2[pb - 1])
		return findkth(nums1, vector<int>(nums2.begin() + pb, nums2.end()), k - pb);
	else
		return nums1[pa - 1];
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();
	int total = m + n;
	if (total & 0x1)
		return findkth(nums1, nums2, total / 2 + 1);
	else
		return (findkth(nums1, nums2, total / 2) + findkth(nums1, nums2, total / 2 + 1))/2.0;

}
/*
void main()
{
	vector <int> nums1;
	vector<int> nums2(0);
	nums1.push_back(2);
	cout << findMedianSortedArrays(nums1,nums2);
}
*/