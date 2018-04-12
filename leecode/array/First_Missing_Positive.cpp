/*
题目：
Given an unsorted integer array, find the first missing positive integer.
For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
Your algorithm should run in O(n) time and uses constant space.
思路：
为了节省空间，我们需要考虑bitmap或者hash table的空间需要。根据抽屉原理，
当我们有长度为n的数据（n个抽屉）的时候，消失的数总是在1到n+1之间，
所以我们只需要用n+1长度的hash table来存储。另外，由于数组已经有n位，
我们其实可以将对应的数直接hash到对应的位置存储即可。例如数据2放到2-1这个位置。
最后遍历一次发现某个位置的索引与存储的值不相匹配的时候就找到了消失的第一次正数。
*/
#include<iostream>
using namespace std;
class First_Missing_Positive{
public:
	void swap(int &a, int &b)//此处注意引用。
	{
		int temp=0;
		temp = a;
		a = b;
		b = temp;
			
	}
	int FisrtMissingPositive(int A[],int n)
	{
		for (int i = 0; i < n; i++)
		{
			int val = A[i];
			if (val>0 && val <= n&&A[val - 1] != val)
			{
				swap(A[i],A[val-1]);
				i--;//交换之后重新判断i位置。
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (A[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
	
};

void main()
{
	First_Missing_Positive fmp;
	int B[8] = { 5, 2, 4, 3, 1, 6,8,9 };
	cout<<fmp.FisrtMissingPositive(B,8);

}
