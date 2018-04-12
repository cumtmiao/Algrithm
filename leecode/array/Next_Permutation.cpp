/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1
*/
#include<iostream>
#include<vector>
using namespace std;
void swap(int& a,int& b)//����������
{ 
	int temp = a;
	a = b;
	b = temp;
}
void reverse(vector<int>& nums,int start, int end)//��תһ������
{
	while (start < end)
	{
		swap(nums[start], nums[end]);
		start++;
		end--;
	}
}
void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	int perm = 0;
	int i;
	if (n == 1) return;
	for ( i = n-2; i>=0; i--)//�ҵ����һ�������λ�ü�nums[i]<nums[i+1],perm=i;
	{
		if (nums[i] < nums[i + 1])
		{
			perm = i;
			break;
		}
	}
	if (i < 0)reverse(nums,0, n - 1);//û�ҵ��κ�һ��λ�õ��������������鷭ת
	else{//����Ļ��ұ�nums[perm]������ұ�λ��
		for (int j = n - 1; j>perm; j--)
		{
			if (nums[j] > nums[perm])
			{
				swap(nums[j], nums[perm]);//�ҵ�����
				break;
			}
		}
		reverse(nums, perm + 1, n - 1);//��ת����nums[perm+1...n-1]
	}
	

}
/*
void main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << ' ';
}
*/