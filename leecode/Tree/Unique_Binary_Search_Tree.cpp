/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

	   1         3     3      2      1
		\       /     /      / \      \
		 3     2     1      1   3      2
		/     /       \                 \
	   2     1         2                 3
*/
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
//���ö�̬�滮�ķ�����
/*
1.�����������и����ʣ�������ߵ������ȸ�С���ұߵ������ȸ���
���⣬��Ŀ˵���������Ľڵ��Ǵ�1��n������������ȷ�������Ϊk�������ߵ�����1��k-1��
���ұߵ�����k+1��n��
2.����ͨ��һ������˵��Ψһ�������������������������������������������������Ǽ򵥵ĳ˷�ԭ��
���ң�������������̬�����Ǹ���������޹صģ�ֻ����������ж��ٽڵ��йء�
��������ѡ���1��n�����������Ψһ�����������������Ǹ�Ϊ1��n�����ܺ���ӡ�
���Ը����⻯��Ϊ��kΪ������Ψһ�����������������ж��٣�
����Ǹ���̬�滮�������ˡ����ǽ���һ������dp[i]������ڵ���Ϊi��Ψһ�����ж��ٸ���
��Ȼdp[0]=dp[1]=1��
*/
int numTrees(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++)//��ʾ��i���ڵ�ʱ�ķ�����
	{
		for (int j = 0; j < i; j++)//��ʾ��i���ڵ㣬������������j���ڵ�ķ�����
		{
			dp[i] += dp[j] * dp[i - 1 - j];//������������*������������
		}
	}
	return dp[n];
}