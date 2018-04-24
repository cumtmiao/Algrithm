/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/
#include<bits/stdc++.h>
using namespace std;
/*
动态规划。
状态转移方程：
dp[i][j]:表示面额下标小于等于i，构成面值为j的使用的最少的硬币数量
dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
一维数组实现
*/
int coinChange(vector<int>& coins, int amount) {
    const int n=coins.size();
    if(n==0)
    {
        if(amount==0)
        return 0;
        else
        return -1;
    }
    if(amount<0)
    return -1;
    if(amount==0)
    return 0;
    vector<int> dp(amount+1,amount+1);//最大面额为coins第i个元素（从1计数）,能够成amount面值的最小方法数。
    dp[0]=0;
  
    for(int j=0;j<=amount;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(j>=coins[i-1])
            {
                dp[j]=min(dp[j],dp[j-coins[i-1]]+1);
            }
        }
    }
    return dp[amount]>amount?-1:dp[amount];
}

/*
动态规划二维数组实现。
*/
int coinChange(vector<int>& coins, int amount) {
    const int n=coins.size();
    vector<vector<int>> dp(n+1,vector<int>(amount+1,amount+1));
    for(int i=0;i<=n;i++)
        dp[i][0]=0;    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=amount;j++)
        {
            if(j>=coins[i-1])
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][amount]>amount?-1:dp[n][amount];
}
int main()
{
    vector<int> data;
    data.push_back(2);
    coinChange(data,3);
    return 0;
}