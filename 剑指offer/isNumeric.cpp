/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/
/*
需要考虑到各种情况。
*/
#include<bits/stdc++.h>
using namespace std;
bool isNumeric(char* string)
{
	if (*string == '\0')//字符串为空返回false;
		return false;
	if (*string > '9' || *string<'0')//字符串第一个字符的特殊处理
	{
		if (*string != '+' && *string != '-' && *string != 'e' && *string != 'E'&&*string != '.')//不为‘+’‘-’‘e’'E''.'时返回false
			return false;
		else if ((*string == '+' || *string == '-') && *(string + 1) == '\0')
			return false;
		else
		string++;
	}

	bool point = false;
	bool ise = false;
	while (*string != '\0')
	{
		if (*string<'0' || *string>'9')
		{
			if ((*string == 'E' || *string == 'e') && ise == false)
			{
				ise = true;
				if ((*(string + 1) >= '0'&&*(string + 1) <= '9') || *(string + 1) == '+' || *(string + 1) == '-')
				{
					if (*(string + 1) == '+' || *(string + 1) == '-')
					{
						string++;
					}
					string++;
					continue;
				}
				else
					return false;
			}
			else if (ise == true)
			{
				return false;
			}
			else
			{
				if (*string == '.'&&point == false)
				{
					point = true;
					if (*(string + 1) <= '9'&&*(string + 1) >= '0')
					{
						string++;
						continue;

					}

					else
						return false;
				}
				else if (point == true)
				{
					return false;
				}
				else
					return false;

			}
		}
		string++;

	}

	return true;
}

/*
第二种解法：貌似更加容易理解。
相当于模式匹配:A[.[B]][E|eC]或者.[B][e|EC]
*/
bool isUnsignedNumber(char** str)//扫描字符串中是否存在无符号整型
{
    char* start=*str;
    while((**str)!='\0'&&(**str)>='0'&&(**str)<='9')
    (*str)++;
    return (*str)>start;
}
bool isNumber(char** str)//扫描字符串中是否存在整型数字
{
    if(**str=='+'||**str=='-')
    (*str)++;
    return isUnsignedNumber(str);
}
bool isNumeric2(char* string)
{
    if(*string=='\0')
    return false;
    bool number=isNumber(&string);//判断'.'号之前是不是一个整型数字
    if(*string=='.')
    {
        string++;
        number=isUnsignedNumber(&string)||number;//小数点前面可以有整数部分也可以没有整数部分，前后至少有一个部分有整数
    }
    if(*string=='e'||*string=='E')
    {
        string++;
        number=number&&isNumber(&string);//E e前后必须有数字
    }
    return number&&*string=='\0';//判断该字符串是否扫描到末尾，如果是，则正确结束
}
int main()
{
	char* c = "+500";
	cout<<isNumeric(c);
	getchar();
	return 0;
}
