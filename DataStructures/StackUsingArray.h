#pragma once
#include <assert.h>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

//string getReversePolishEntry(string str) {
//	map<char, int> priority = {
//		{ '(', 0 },
//		{ '+', 1 },
//		{ '-', 1 },
//		{ '*', 2 },
//		{ '/', 2 },
//		{ '^', 3 }
//	};
//	string result = "";
//	Stack<char> symbols;
//
//	str.erase(remove(str.begin(), str.end(), ' '), str.end());
//
//	for (char ch : str) {
//		if (isdigit(ch))
//			result += ch;
//		else if (ch == ')') {
//			while (symbols.top() != '(')
//				result += symbols.pop();
//			symbols.pop();
//		}
//		else {
//			while (!symbols.isEmpty() && ch != '(' && priority.at(ch) <= priority.at(symbols.top()))
//				result += symbols.pop();
//			symbols.push(ch);
//		}
//	}
//
//	while (!symbols.isEmpty())
//		result += symbols.pop();
//
//	return result;
//}
//
//bool isCorrect(string expression) {
//
//	Stack<char> stack;
//	for (char ch : expression) {
//		if (ch == '(' || ch == '{' || ch == '[')
//			stack.push(ch);
//		else if (ch == ')' || ch == '}' || ch == ']') {
//			if (stack.isEmpty())
//				return false;
//			char temp = stack.pop();
//			if (ch == ')' && temp != '(' ||
//				ch == '[' && temp != ']' ||
//				ch == '}' && temp != '{')
//				return false;
//		}
//	}
//	return stack.isEmpty();
//}

template <typename T>
class Stack {
private:
	int capacity,
		current;
	T* storage;

	void rewrite() {
		capacity = capacity * 3 / 2;
		T* temp = new T[capacity];
		for (int i = 0; i < current; i++) {
			temp[i] = storage[i];
		}
		delete[]storage;
		storage = temp;
	}
public:
	Stack() : Stack(3) {}

	Stack(const Stack& stack) {
		capacity = stack.capacity;
		current = stack.current;
		storage = new T[stack.capacity];
		for (int i = 0; i <= current; i++) {
			storage[i] = stack.storage[i];
		}
	}

	Stack(int size) : capacity(size), current(-1) {
		assert(size > 0);
		storage = new T[capacity];
	}

	~Stack() {
		delete[]storage;
	}

	void push(const T &item) {
		if (++current == capacity)
			rewrite();
		storage[current] = item;
	}

	T& pop() {
		assert(current > -1);
		return storage[current--];
	}

	T& top() {
		assert(current > -1);
		return storage[current];
	}

	int size() const {
		return current + 1;
	}

	void print() const {
		if (current > -1) {
			cout << "[";
			for (int i = 0; i < current; i++) {
				cout << storage[i] << ", ";
			}
			cout << storage[current] << "]" << endl;
		}
	}

	bool isEmpty() const {
		return current == -1;
	}

	Stack& operator=(const Stack& stack) {
		capacity = stack.capacity;
		current = stack.current;
		storage = new T[stack.capacity];
		for (int i = 0; i <= current; i++) {
			storage[i] = stack.storage[i];
		}
		return *this;
	}
};