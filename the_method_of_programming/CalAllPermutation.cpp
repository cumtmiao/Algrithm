/*
����һ���ַ�������ӡ�����ַ������ַ����������С����磺�����ַ���Ϊ��
��abc��,������ɡ�a����b����c���������г����������ַ�����abc������acb������bac������bca������cab����
��cba��
*/
#include<iostream>
#include<algorithm>
using namespace std;
class CalAllPermutation{
public:
	//�ⷨһ���ݹ鷨ʵ�֣��㷨���Ӷ�ΪO(n!)
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
	//�ⷨ�����ֵ�������,num��ʾnum���ַ�.Ѱ���ֵ������һ���ַ���
	void next_permutation(char *perm, int num)
	{
		int i;
		//����һ���ҵ����������һ���������λλ��i,x=perm[i];
		for (i = num - 2; i >= 0 && perm[i] >= perm[i + 1]; i--);
		if (i<0)return;

		int k;
		//��������ҵ���iλ�ұ����һ����perm[i]���λ��j,y=perm[j]
		for (k = num - 1; k>i&&perm[k] <= perm[i]; k--);
		//������������x��y
		swap(perm[i], perm[k]);
		//�����ģ�����i+1λ�����Ĳ��ַ�ת
		reverse(perm + i + 1, perm + num);
		//���
		for (int i = 0; i < num; i++)
			cout << perm[i];
		cout << endl;
	}
	void AllPermutation2(char * perm, int num)
	{
		sort(perm, perm+num - 1);//�㷨��㣬�����ų��ֵ��򣬱���abcd
		for (int i = 0; i < num; i++)
			cout << perm[i];
		cout << endl;
		while (1)
		{
			next_permutation(perm, num);//��������ֵ������һ���ַ���
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