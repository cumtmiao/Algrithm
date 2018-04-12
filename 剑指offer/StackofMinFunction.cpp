/*
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/
//我曹！AC过程中居然不识别assert();奇怪
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
stack<int> min_data;
stack<int> min_help;
    void push(int value) {
        if(min_help.empty()||value<=min_help.top())
        {
            min_help.push(value);
        }
        min_data.push(value);
    }
    void pop() {
            //assert(min_data.size()>0);
            if(min_help.size()>0&&min_data.top()==min_help.top())
            min_help.pop();
            min_data.pop();
        
    }
    int top() {
        //assert(min_data.size()>0);
        return min_data.top();
    }
    int min() {
       // assert(min_data.size()>0&&min_help.size()>0);
            return min_help.top();
    }
};