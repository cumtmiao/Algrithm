/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/
#include<iostream>
#include<string>
using namespace std;
string addBinary(string a, string b) {
	int na = a.size();
	int nb = b.size();
	string c = na >= nb ? a : b;//结果串等于a b中的长串
	int nc = c.size();
	int i = 1;
	int carry = 0;
	while (na != 0 && nb != 0)
	{
		c[nc - i] = '0' + (((int)(a[na - i] - '0') + (int)(b[nb - i] - '0') + carry) % 2);//算c的[nc-i]位
		carry = ((int)(a[na - i] - '0') + (int)(b[nb - i]-'0') + carry) / 2;//计算进位
		na--;
		nb--;
		nc--;	
	}
	while (na > 0)
	{
		c[nc - i] = '0' + (((int)(a[na - i] - '0') + carry) % 2);
		carry = ((int)(a[na - i]-'0')+ carry) / 2;	
		na--;
		nc--;
	}
	while (nb > 0)
	{
		c[nc - i] = '0' + (((int)(b[nb - i] - '0') + carry) % 2);
		carry = ((int)(b[nb - i]-'0') + carry) / 2;
		
		nb--;
		nc--;
	}
	if (carry > 0)//特殊情况的考虑
		return "1" + c;
	else return c;
}
/*
void main()
{
	string a = "1";
	string b = "1";
	cout<<addBinary(a, b);
}
*/