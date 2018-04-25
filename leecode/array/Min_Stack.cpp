/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
#include<bits/stdc++.h>
using namespace std;
//使用两个栈实现最小的栈：
//其中一个栈存储真正的数据，另外一个栈存储目前为止最小的值。
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        t.push(x);
        if(s.empty()||x<=s.top())
        s.push(x);
    }
    
    void pop() {
        int temp=t.top();
        t.pop();
        if(temp==s.top())
        s.pop();
    }
    
    int top() {
        return t.top();
    }
    
    int getMin() {
        return s.top();
    }
private:
    stack<int> s;//存放最小元素的栈
    stack<int> t;//真正的栈；
};
