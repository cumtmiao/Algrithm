/*
把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/
#include<bits/stdc++.h>
using namespace std;
bool isUgly(int number)
{
    while(number%2==0)
    {
        number=number/2;
    }
    while(number%3==0)
    {
        number=number/3;
    }
    while(number%5==0)
    {
        number=number/5;
    }
    if(number==1)
    return true;
    else
    return false;
}
int GetUglyNumber_Solution(int index) {//暴力解法：依次判断一个数是不是丑数。没有AC
    int num=0;
    int numberofugly=0;
    while(numberofugly<index)
    {
        num++;
        if(isUgly(num))
        {
            numberofugly++;
        }
    }
    return num;
}
/*
解法二：该方法只计算丑数，而不计算非丑数。新建一个数组包含index个丑数，并且保证这些丑数是排序的。
问题的关键是怎么确保数组中的丑数是排序的。具体解释见剑指offer241页
*/
int Min(int number1,int number2, int number3)
{
    int temp=(number1)<(number2)?(number1):(number2);
    return temp<(number3)?temp:(number3);
}
int GetUglyNumber_Solution1(int index)//返回第index个丑数。
{
    if(index<=0)
    return 0;
    int *numberugly=new int[index];//新建一个index大小的数组来存储排序的丑数
    numberugly[0]=1;
    int *ugly2=numberugly;//ugly2指向数组中刚好乘以2能够大于当前数组最后一个值的位置。
    int *ugly3=numberugly;//ugly3指向数组中刚好乘以3能够大于当前数组最后一个值的位置。
    int *ugly5=numberugly;//ugly5指向数组中刚好乘以5能够大于当前数组最后一个值的位置。
    int nextugly=1;
    while(nextugly<index)
    {
        int val=Min((*ugly2)*2,(*ugly3)*3,(*ugly5)*5);//返回这三个值的最小值。
        numberugly[nextugly]=val;
        while((*ugly2)*2<=val)//分别更新指针ugly2,ugly3,ugly5,使其与相应数的乘积始终大于当前数组末尾的值
        ugly2++;
        while((*ugly3)*3<=val)
        ugly3++;
        while((*ugly5)*5<=val)
        ugly5++;
        nextugly++;
    }
    int res=numberugly[index-1];
    delete[] numberugly;
    return res;
}