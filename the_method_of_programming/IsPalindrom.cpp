/*
����һ���ַ���������ж�����ַ����Ƿ�Ϊ���Ĵ���
*/
#include <iostream>
using namespace std;
class IsPalindrom{
public:
	//�ⷨһ������ͷ���м�ɨ
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
	//�ⷨ�������м�����ͷɨ
	bool Ispalindrom2(const char *s, int n)
	{
		//�жϷǷ���
		if (s == NULL || n < 1)
		{
			return false;
		}
		const char * first, *second;
		//�ҵ��ַ������е�
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