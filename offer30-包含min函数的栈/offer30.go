package main

import (
	"container/list"
)

type MinStack struct {
	stack    *list.List
	minStack *list.List
}

func Constructor() MinStack {
	return MinStack{
		stack:    list.New(),
		minStack: list.New(),
	}
}

func (this *MinStack) Push(x int) {
	this.stack.PushBack(x)
	if this.minStack.Len() == 0 || this.minStack.Back().Value.(int) >= x {
		this.minStack.PushBack(x)
	}
}

func (this *MinStack) Pop() {
	if this.stack.Back().Value.(int) == this.minStack.Back().Value.(int) {
		this.minStack.Remove(this.minStack.Back())
	}
	this.stack.Remove(this.stack.Back())
}

func (this *MinStack) Top() int {
	return this.stack.Back().Value.(int)
}

func (this *MinStack) Min() int {
	return this.minStack.Back().Value.(int)
}
