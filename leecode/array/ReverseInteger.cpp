/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
#include<iostream>
#include<algorithm>
using namespace std;
//考虑到超过范围的情况
int reverse(int x) {
	int temp = 0;
	const int max = INT_MAX;
	const int min = INT_MIN;
	long long sum = 0;
	while (x != 0)
	{
		temp = x % 10;
		if (sum > (max / 10) || (sum == (max / 10)&&temp>=7))return max;
		if (sum < (min/10)||(sum==(min/10)&&temp<=-8))return min;
		sum = sum * 10 + temp;
		x = x / 10;
	}
	return sum;
}
/*
void main()
{
	cout << reverse(123);
}
*/