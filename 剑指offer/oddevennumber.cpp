/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   /* void reOrderArray(vector<int> &array) {//此部分解法仅仅是将奇数移到数组的前面，偶数移到数组的后面，没有考虑奇数与奇数，偶数与偶数的相对顺序。
        int len=array.size();
        int left=0;
        int right=len-1;
        while(left<right)
        {
            while(isodd(array[left]))left++;
            while(!isodd(array[right]))right--;
           exchange(&array[left],&array[right]);
           left++;
           right--;
        }
    }
    void exchange(int* a,int* b)
    {
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }
    bool isodd(int number)
    {
        return number%2==1;
    }*/

    void reOrderArray(vector<int> &array) {
        int len=array.size();
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<len;i++)
        {
            if(isodd(array[i]))
            odd.push_back(array[i]);
            else
            even.push_back(array[i]);
        }
        array.clear();
        for(int i=0;i<odd.size();i++)
        {
            array.push_back(odd[i]);
        }
         for(int i=0;i<even.size();i++)
        {
            array.push_back(even[i]);
        }
    }
    bool isodd(int number)
    {
        return number%2==1;
    }
};