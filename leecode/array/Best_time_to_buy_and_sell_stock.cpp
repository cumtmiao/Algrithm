/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//暴力解法。  超时
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	int maxprofit = INT_MIN;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			maxprofit = max(prices[j] - prices[i], maxprofit);
		}
	}
	if (maxprofit < 0)
		return 0;
	return maxprofit;
}
//一遍扫描.
/*
The points of interest are the peaks and valleys in the given graph. 
We need to find the largest peak following the smallest valley. 
We can maintain two variables - minprice and maxprofit corresponding to 
the smallest valley and maximum profit (maximum difference between selling price and 
minprice) obtained so far respectively.
*/
int maxProfit1(vector<int>& prices){
	int n = prices.size();
	if (n == 0)return 0;
	int minprice = INT_MAX;
	int maxprofit = 0;
	for (int i = 0; i < n; i++)
	{
		if (prices[i] < minprice)
		{
			minprice = prices[i];
		}
		else if (prices[i] - minprice>maxprofit)
		{
			maxprofit = prices[i] - minprice;
		}
			
	}

	return maxprofit;
}