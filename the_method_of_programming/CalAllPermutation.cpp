/*
输入一个字符串，打印出该字符串中字符的所有排列。例如：输入字符串为：
“abc”,则输出由‘a’‘b’‘c’所能排列出来的所有字符串“abc”、“acb”、“bac”、“bca”、“cab”、
“cba”
*/
#include<iostream>
#include<algorithm>
using namespace std;
class CalAllPermutation{
public:
	//解法一：递归法实现，算法复杂度为O(n!)
	void AllPermutation1(char *perm, int from, int to)
	{
		if (to < 1)return;
		if (from == to)
		{
			for (int i = 0; i <= to; i++)
				cout << perm[i];
			cout << endl;
		}

		for (int i = from; i <= to; i++)
		{
			swap(perm[i], perm[from]);
			AllPermutation1(perm, from + 1, to);
			swap(perm[i], perm[from]);
		}
		
	}
	//解法二：字典序排列,num表示num个字符.寻找字典序的下一个字符串
	void next_permutation(char *perm, int num)
	{
		int i;
		//步骤一：找到排列中最后一个升序的首位位置i,x=perm[i];
		for (i = num - 2; i >= 0 && perm[i] >= perm[i + 1]; i--);
		if (i<0)return;

		int k;
		//步骤二：找到第i位右边最后一个比perm[i]大的位置j,y=perm[j]
		for (k = num - 1; k>i&&perm[k] <= perm[i]; k--);
		//步骤三：交换x和y
		swap(perm[i], perm[k]);
		//步骤四：将第i+1位到最后的部分翻转
		reverse(perm + i + 1, perm + num);
		//输出
		for (int i = 0; i < num; i++)
			cout << perm[i];
		cout << endl;
	}
	void AllPermutation2(char * perm, int num)
	{
		sort(perm, perm+num - 1);//算法起点，首先排出字典序，比如abcd
		for (int i = 0; i < num; i++)
			cout << perm[i];
		cout << endl;
		while (1)
		{
			next_permutation(perm, num);//不断输出字典序的下一个字符串
		}

	}

};

/*void main()
{
	CalAllPermutation cap;
	char a[] = "bacd";
	//cap.AllPermutation1(a, 0, 3);
	cap.AllPermutation2(a, 4);
}*/