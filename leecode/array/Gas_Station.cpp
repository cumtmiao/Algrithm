/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i 
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, 
otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
Example 1:

Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: 
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
*/
#include<bits/stdc++.h>
using namespace std;
/*
较为暴力的方法：
1.如果总花费大于总油量，返回-1；
2.否则，对每一个可能开始的位置求解。如果求出一个解则返回。遍历完所有的位置如果没有求出解则返回-1.
AC时间278ms
*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sumofgas=0;
    int sumofcost=0;
    for(int i=0;i<gas.size();i++)
    {
        sumofgas+=gas[i];
    }
    for(int i=0;i<cost.size();i++)
    {
        sumofcost+=cost[i];
    }
    if(sumofcost>sumofgas)
    return -1;
    for(int i=0;i<gas.size();i++)
    {
        if(gas[i]<cost[i])
        continue;
        else
        {
            int shengyu=0;
            int j;
            for(j=0;j<gas.size();j++)
            {
                int index=(i+j)%gas.size();
                shengyu+=gas[index]-cost[index];
                if(shengyu<0)
                break;
            }
            if(j==gas.size())
            return i;
        }
    }
    return -1;
}
/*
改善后的思路：参考网上解题思路
只需要O(n)的时间复杂度
*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start=gas.size()-1;
    int end=0;
    int sum=gas[start]-cost[start];
    while(end<start)
    {
        if(sum>=0)
        {
            sum+=gas[end]-cost[end];
            end++;
        }
        else
        {
            start--;
            sum+=gas[start]-cost[start];
        }
    }
    return sum>=0?start:-1;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> gas;
        vector<int> cost;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            gas.push_back(temp);
        }
        for(int i=0;i<m;i++)
        {
            int temp;
            cin>>temp;
            cost.push_back(temp);
        }
        cout<<canCompleteCircuit(gas,cost);
    }
    return 0;
}