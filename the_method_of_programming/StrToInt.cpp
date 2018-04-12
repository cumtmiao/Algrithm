/*
输入一个由数字组成的字符串，请把它转换成整数并输出。
例如：输入字符串“123”，输出整数123
*/
#include<iostream>
#include<string>
using namespace std;
class StrToInt
{
public :
	int StringToInt(const char * str)
	{
		int n = 0;
		static const int MAX_INT = (int)((unsigned) ~ 0 >> 1);
		static const int MIN_INT = -(int)((unsigned)~0 >> 1)-1;
		//判断输入是否为空；
		if (str == 0)return 0;
		//处理空格
		while (isspace(*str))++str;
		//处理正负
		int sign = 1;
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				sign = -1;
			str++;
		}
		//确定是数字后再执行
		while (isdigit(*str))
		{
			//处理溢出：
			int c = *str - '0';
			if (sign > 0 && ((n > MAX_INT / 10) || (n == MAX_INT / 10 && c > MAX_INT % 10)))
			{
				n = MAX_INT;
				break;
			}
			else if (sign < 0 && ((n >(unsigned)MIN_INT / 10) || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10)))
			{
				n = MIN_INT;
				break;
			}
			n = n * 10 + c;
			++str;
		}
		return sign > 0 ? n : -n;
	}
};
/*void main()//测试
{
	char test1[] = "123456789";
	char test2[] = "2147483648";//比最大值大
	char test3[] = "2147483646";//比最大值小
	char test4[] = "-2147483646";//比最小值大
	char test5[] = "-2147483649";//比最小值小
	char test7[] = " ";//空串
	char test8[] = " 5165  ";//处理空格
	StrToInt sti;
	cout << sti.StringToInt(test1)<<endl;
	cout << sti.StringToInt(test2) << endl;
	cout << sti.StringToInt(test3) << endl;
	cout << sti.StringToInt(test4) << endl;
	cout << sti.StringToInt(test5) << endl;
	cout << sti.StringToInt(test7) << endl;
	cout << sti.StringToInt(test8) << endl;
	
}
*/