/*
Reverse bits of a given 32 bits unsigned integer.

Example:

Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
             return 964176192 represented in binary as 00111001011110000010100101000000.
*/
#include<bits/stdc++.h>
using namespace std;
/*
从后向前访问。放入到结果中
*/
uint32_t reverseBits(uint32_t n) {
    uint32_t pointer=1;
    uint32_t res=0;
    for(uint32_t i=0;i<32;i++)
    {
        if((pointer&n)==pointer)//如果当前位为1，则对结果中的当前位赋值1
        {
            res|=1;
        }
        else//否则，结果当前位为0
        {
            res=res&(~1);
        }
        if(i!=31)
        res=res<<1;
        pointer=pointer<<1;
    }
    return res;
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<reverseBits(n);
    }
    return 0;
}