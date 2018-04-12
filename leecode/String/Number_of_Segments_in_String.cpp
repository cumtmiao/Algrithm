/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
*/
#include<string>
using namespace std;
int countSegments(string s) {
	int n = s.size();
	int i = 0;
	int num = 0;
	for (; i < n; i++)
	{
		if (i == 0 && s[0] != ' ')num++;
		if (i>0 && s[i - 1] == ' '&&s[i] != ' ')num++;//前一个元素不为空，且当前元素为空
	}
	return num;

}