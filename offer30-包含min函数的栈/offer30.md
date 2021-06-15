# offer30-包含min函数的栈

## 题目描述

　　定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

## 示例

示例 1：

```html
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();   --> 返回 0.
minStack.min();   --> 返回 -2.
```

## 限制

- 各函数的调用总次数不超过 20000 次

## 题解

　　本题除了维护一个普通栈以为，还需要维护一个单调栈，用来返回最小值。
　　当我们向栈压入一个元素时，如果该数这个数小于或等于单调栈栈顶的元素时，则同时将这个元素压入单调栈，这样可以保证单调栈栈顶元素一定是整个栈的最小元素，当弹出元素时比较该元素和单调栈栈顶元素是否相等，如果相等则弹出。
