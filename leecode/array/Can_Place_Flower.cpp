/*
Suppose you have a long flowerbed in which some of the plots are planted and some are not. 
However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), 
and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.
*/
#include<iostream>
#include<vector>
using namespace std;
//注意一些特殊情况的处理
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	int n1 = flowerbed.size();
	if (n > n1)return false;
	if (n1 == 0)
		return false;
	if (n1 == 1 && flowerbed[0] == 1 && n == 0)
		return true;
	if (n1 == 1 && flowerbed[0] == 0)
		return true;
	int num = 0;
	if (flowerbed[1] == 0 && flowerbed[0] == 0)
	{
		num++;
		flowerbed[0] = 1;
	}
	if (flowerbed[n1 - 1] == 0 && flowerbed[n1 - 2] == 0)
	{
		num++;
		flowerbed[n1 - 1] = 1;
	}
	for (int i = 1; i < n1 - 1; i++)
	{
		if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
		{
			num++;
			flowerbed[i] = 1;
		}
	}
	return num>=n;
}