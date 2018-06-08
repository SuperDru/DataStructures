#pragma once
#include <assert.h>
#include "StackUsingArray.h"
#include <iostream>

template <typename T>
class Queue {
private:
	Stack<T> outStack, inStack;
	int tail;
public:
	Queue(){
		tail = -1;
	}

	Queue(const Queue& queue) {
		tail = queue.size() - 1;
		inStack = queue.inStack;
		outStack = queue.outStack;
	}

	Queue(int size){
		if (size <= 0) {
			throw out_of_range("Size must be a positive number.");
		}
		tail = -1;
		inStack = { size };
	    outStack = { size };
	}

	~Queue() {}

	void back(const T &item) noexcept{
		tail++;
		inStack.push(item);
	}

	T& pop() {
		if (tail <= -1) {
			throw logic_error("Stack is empty.");
		}
		if (inStack.isEmpty()) {
			tail--;
			return outStack.pop();
		}
		else {
			tail--;
			while (inStack.size() != 0)
				outStack.push(inStack.pop());
			return outStack.pop();
		}
	}

	T& peek() {
		if (tail <= -1) {
			throw logic_error("Stack is empty.");
		}
		if (inStack.isEmpty()) 
			return outStack.top();
		else {
			while (inStack.size() != 0)
				outStack.push(inStack.pop());
			return outStack.top();
		}
	}

	int size() const _NOEXCEPT {
		return tail + 1;
	}

	void print() const _NOEXCEPT {
		if (tail != -1) {
			Stack<T> tempOutStack(outStack),
				tempInStack(inStack);
			while (!tempOutStack.isEmpty()) {
				cout << tempOutStack.pop() << " ";
			}
			while (!tempInStack.isEmpty())
				tempOutStack.push(tempInStack.pop());
			while (!tempOutStack.isEmpty()) {
				cout << tempOutStack.pop() << " ";
			}
			cout << endl;
		}
	}

	bool isEmpty() const _NOEXCEPT {
		return tail == -1;
	}
};

template <typename T>
class QueueCircle {
private:
	T* storage;
	int capacity;
	int head = 0, tail = 0;
	bool full = false;

public:
	QueueCircle(): QueueCircle(3){}

	QueueCircle(const QueueCircle& queue) {
		capacity = queue.capacity;
		head = queue.head;
		tail = queue.tail;
		storage = new T[capacity];
		for (int i = 0; i < capacity; i++) {
			storage[i] = queue.storage[i];
		}
	}

	QueueCircle(int size) {
		if (size <= 0) {
			throw out_of_range("Size must be a positive number.");
		}
		capacity = size;
		storage = new T[size];
	}

	~QueueCircle() {}

	void push(const T item) _NOEXCEPT {
		if (full)
			throw logic_error("Queue is full.");
		storage[tail] = item;
		tail = (tail + 1) % capacity;
		if (tail == head)
			full = true;
	}

	T& pop() {
		if (head == tail)
			throw logic_error("Queue is empty.");
		if (full)
			full = false;
		T* result = &storage[head];
		head = ++head % capacity;
		return *result;
	}

	T& peek() {
		if (head == tail)
			throw logic_error("Queue is empty.");
		return storage[head];
	}

	int size() const _NOEXCEPT {
		return (tail - head + capacity) % capacity;
	}

	void print() const _NOEXCEPT {
		int i = head;
		while (i % capacity != tail) {
			cout << storage[i++ % capacity] << " ";
		} 
		cout << endl;
	}

	bool isEmpty() const _NOEXCEPT {
		return head == tail;
	}
};