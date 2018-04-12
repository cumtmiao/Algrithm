/*
��Ŀ��
Given an unsorted integer array, find the first missing positive integer.
For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
Your algorithm should run in O(n) time and uses constant space.
˼·��
Ϊ�˽�ʡ�ռ䣬������Ҫ����bitmap����hash table�Ŀռ���Ҫ�����ݳ���ԭ��
�������г���Ϊn�����ݣ�n�����룩��ʱ����ʧ����������1��n+1֮�䣬
��������ֻ��Ҫ��n+1���ȵ�hash table���洢�����⣬���������Ѿ���nλ��
������ʵ���Խ���Ӧ����ֱ��hash����Ӧ��λ�ô洢���ɡ���������2�ŵ�2-1���λ�á�
������һ�η���ĳ��λ�õ�������洢��ֵ����ƥ���ʱ����ҵ�����ʧ�ĵ�һ��������
*/
#include<iostream>
using namespace std;
class First_Missing_Positive{
public:
	void swap(int &a, int &b)//�˴�ע�����á�
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
				i--;//����֮�������ж�iλ�á�
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
