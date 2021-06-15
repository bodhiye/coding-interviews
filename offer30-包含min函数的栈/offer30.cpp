#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> stack, minStack;
public:
    MinStack() {
        while (!stack.empty()) {
            stack.pop();
        }
        while (!minStack.empty()) {
            minStack.pop();
        }   
    }
    
    void push(int x) {
        stack.push(x);
        if (minStack.empty() || x <= minStack.top())
		    minStack.push(x);
    }
    
    void pop() {
        if (stack.top() == minStack.top())
		    minStack.pop();
        stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int min() {
        return minStack.top();
    }
};
