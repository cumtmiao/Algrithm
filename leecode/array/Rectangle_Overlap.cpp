/*
A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left
 corner, and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive.  To be clear, two rectangles that only
 touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

Example 1:

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
Output: true
Example 2:

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
Output: false
*/
#include<bits/stdc++.h>
using namespace std;
/*
基本思路：判断相反的情况：
以矩形2为参考，如果矩形1在矩形2的上，下，左，右，则不相交，否则相交。
*/
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    bool flag=true;
    int rec1_x_min=rec1[0]<rec1[2]?rec1[0]:rec1[2];
    int rec1_x_max=rec1[0]>rec1[2]?rec1[0]:rec1[2];
    int rec1_y_min=rec1[1]<rec1[3]?rec1[1]:rec1[3];
    int rec1_y_max=rec1[1]>rec1[3]?rec1[1]:rec1[3];

    int rec2_x_min=rec2[0]<rec2[2]?rec2[0]:rec2[2];
    int rec2_x_max=rec2[0]>rec2[2]?rec2[0]:rec2[2];
    int rec2_y_min=rec2[1]<rec2[3]?rec2[1]:rec2[3];
    int rec2_y_max=rec2[1]>rec2[3]?rec2[1]:rec2[3];
    if(rec1_x_max<=rec2_x_min)
    flag=false;
    if(rec1_x_min>=rec2_x_max)
    flag=false;
    if(rec1_y_min>=rec2_y_max)
    flag=false;
    if(rec1_y_max<=rec2_y_min)
    flag=false;
    return flag;
}