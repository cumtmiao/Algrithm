/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
  例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
  NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
//本题目实际上考察的是二分查找。要考虑到不同的测试用例！！！
//主要本题目数组中存在相同的元素，造成二分查找时考虑的情况有点多。
#include<bits/stdc++.h>
using namespace std;
int inorder(vector<int> rotateArray,int left,int right)//考虑到特殊的测试用例[1,0,1,1,1]和[1,1,1,0,1]
{
    int minval=INT_MAX;
    for(int i=left;i<=right;i++)
    {
        if(rotateArray[i]<minval)
        minval=rotateArray[i];
    }
    return minval;
}
int minNumberInRotateArray(vector<int> rotateArray)
{
    if(rotateArray.size()==0)
    return 0;
    int left=0;
    int right=rotateArray.size()-1;
    int mid=0;
    while(rotateArray[left]>=rotateArray[right])//这里使rotateArray[left]>=rotateArray[right]也是考虑到特例：[1,2,3,4,5]
    {
        if(right-left==1)
        {
            return rotateArray[right];
        }
        mid=(left+right)>>1;
        if(rotateArray[left]==rotateArray[mid]&&rotateArray[mid]==rotateArray[right])//如果左边，中间，右边元素都相等时无法辨别指针怎么变化，此时只能顺序访问。
        {
            return inorder(rotateArray,left,right);
        }
        if(rotateArray[mid]<=rotateArray[right])//中间元素与最右边元素比，证明中间元素是在后半部分递增序列
        {
            right=mid;
        }
        if(rotateArray[mid]>=rotateArray[left])//证明中间元素在前半部分的递增序列
        {
            left=mid;
        }
    }
    return rotateArray[mid];
}