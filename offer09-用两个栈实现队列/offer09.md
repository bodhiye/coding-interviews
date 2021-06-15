# offer09-用两个栈实现队列

## 题目描述

　　用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

## 示例

示例 1：

输入：
`["CQueue","appendTail","deleteHead","deleteHead"]`
`[[],[3],[],[]]`
输出：
`[null,null,3,-1]`

示例 2：

输入：
`["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]`
`[[],[],[5],[2],[],[]]`
输出：
`[null,-1,null,null,5,2]`

## 限制

- 1 <= values <= 10000
- 最多会对 appendTail、deleteHead 进行 10000 次调用

## 题解

　　本题利用两个栈模拟一个队列，第一个栈实现插入操作，第二个栈实现删除操作。
　　栈的特点是先入后出，而队列是先进先出。利用第二个栈来保存第一个栈当前所有的元素，依次 pop 出要删除的元素，直到第二个栈为空。当第二个栈为空则又依次把第一个栈的所有元素 push 进栈。
　　下面是模拟过程
　　push stack1　3   stack2
                2
                1
   pop  stack1      stack2  ~~1~~
　　　　　　　　　　　　　　　　　　2
                              3
　　push stack1　4   stack2    2
                              3
   pop  stack1  4   stack2  ~~2~~
                              3
