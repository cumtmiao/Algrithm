/*
����һ����������ɵ��ַ����������ת���������������
���磺�����ַ�����123�����������123
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
		//�ж������Ƿ�Ϊ�գ�
		if (str == 0)return 0;
		//����ո�
		while (isspace(*str))++str;
		//��������
		int sign = 1;
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				sign = -1;
			str++;
		}
		//ȷ�������ֺ���ִ��
		while (isdigit(*str))
		{
			//���������
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
/*void main()//����
{
	char test1[] = "123456789";
	char test2[] = "2147483648";//�����ֵ��
	char test3[] = "2147483646";//�����ֵС
	char test4[] = "-2147483646";//����Сֵ��
	char test5[] = "-2147483649";//����СֵС
	char test7[] = " ";//�մ�
	char test8[] = " 5165  ";//����ո�
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