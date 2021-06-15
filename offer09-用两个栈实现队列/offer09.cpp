#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// 两个栈模拟一个队列
class CQueue {
    stack<int> stack1, stack2;
public:
    CQueue() {
        while (!stack1.empty()) {
            stack1.pop();
        }
        while (!stack2.empty()) {
            stack2.pop();
        }
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        } 
        if (stack2.empty()) {
            return -1;
        } else {
            int deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        }
    }
};

// 两个队列模拟一个栈
class CStack {
    queue<int> queue1, queue2;
public:
    CStack() {
        while (!queue1.empty()) {
            queue1.pop();
        }
        while (!queue2.empty()) {
            queue2.pop();
        }
    }
    
    void push(int value) {
        queue1.push(value);
    }
    
    int pop() {
        int node;
        while (queue1.size() > 1)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        node = queue1.front();
        queue1.pop();
        while (queue2.size())
        {
            queue1.push(queue2.front());
            queue2.pop();
        }
        return node;
    }
};
