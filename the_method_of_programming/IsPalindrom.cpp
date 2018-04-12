/*
给定一个字符串，如何判断这个字符串是否为回文串？
*/
#include <iostream>
using namespace std;
class IsPalindrom{
public:
	//解法一：从两头往中间扫
	bool Ispalindrom1(const char *s, int n)
	{
		if (s == NULL || n < 1)
		{
			return false;
		}
		const char *front = s;
		const char *back = s + n - 1;
		while (front < back)
		{
			if (*front != *back)return false;
			front++;
			back--;

		}
		return true;
	}
	//解法二：从中间往两头扫
	bool Ispalindrom2(const char *s, int n)
	{
		//判断非法串
		if (s == NULL || n < 1)
		{
			return false;
		}
		const char * first, *second;
		//找到字符串的中点
		int m = (n >> 1) - 1 >= 0 ? ((n >> 1) - 1) : 0;
		first = s + m;
		second = s + n - 1 - m;
		while (first>=s)
		{
			if (*first != *second)return false;
			first--;
			second++;
		}
		return true;

	}
};
/*void main()
{
	char a[] = "abcdba";
	IsPalindrom isp;
	cout<<isp.Ispalindrom1(a,6)<<endl;
	cout << isp.Ispalindrom2(a,6);
}*/