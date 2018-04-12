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
//采用动态规划的方法。
/*
1.二叉搜索树有个性质，就是左边的数都比根小，右边的数都比根大。
另外，题目说明二叉树的节点是从1到n，所以我们能确定如果根为k，则根左边的数是1到k-1，
根右边的数是k+1到n。
2.对于通过一个根来说，唯一二叉树的数量是其左子树的数量乘以右子树的数量，这是简单的乘法原理。
并且，左右子树的形态数量是跟具体的数无关的，只跟这个树里有多少节点有关。
而根可以选择从1到n的任意的数，唯一二叉树的总数，就是根为1到n的树总和相加。
所以该问题化简为以k为根，其唯一左子树和右子树各有多少，
这就是个动态规划的问题了。我们建立一个数组dp[i]，代表节点数为i的唯一子树有多少个。
显然dp[0]=dp[1]=1。
*/
int numTrees(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++)//表示有i个节点时的方法数
	{
		for (int j = 0; j < i; j++)//表示有i个节点，其中左子树有j个节点的方法数
		{
			dp[i] += dp[j] * dp[i - 1 - j];//左子树方法数*右子树方法数
		}
	}
	return dp[n];
}