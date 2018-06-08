#pragma once
#include <iostream>

using namespace std;


template <typename T>
class LinkedList{
private:
	struct Node {
	public:
		T value;
		Node *next,
			 *prev;

		Node(const T value, Node* next, Node* prev) :
			value(value),
			next(next),
			prev(prev) {}
	};
	int size = 0;
	Node *head = nullptr,
		 *tail = nullptr;
public:
	LinkedList() {}

	LinkedList(const LinkedList &list) {
		Node *node = list.head;
		for (int i = 0; i < list.size; i++) {
			add(node->value);
			node = node->next;
		}
	}

	void addTail(const T value) noexcept{
		Node *node = new Node(value, nullptr, tail);
		if (size == 0) 
			head = node;
		else 
			tail->next = node;
		tail = node;
		size++;
	}

	void addHead(const T value) noexcept{
		Node *node = new Node(value, head, nullptr);
		if (size == 0)
			tail = node;
		else
			head->prev = node;
		head = node;
		size++;
	}

	int indexOf(T value) noexcept{
		Node *node = head;
		int i = 0;
		while (i++ != size) {
			if (node->value == value)
				return --i;
			node = node->next;
		}
		return -1;
	}

	//T& get(int index) {
	//	if (index < 0 || index >= size)
	//		throw out_of_range("Index out of range of the list");
	//	Node *node = head;
	//	for (int i = 0; i < index; i++, node = node->next);
	//	return node->value;
	//}

	void remove(int index){
//		assert(index >= 0 && index < size);
		if (index < 0 || index >= size)
			throw out_of_range("Index out of range of the list");
		if (index == 0) {
			head = head->next;
			if (head != nullptr)
				head->prev = nullptr;
		}
		else if (index == size - 1) {
			tail = tail->prev;
			if (tail != nullptr)
				tail->next = nullptr;
		}
		else{
			Node *node = head;
			for (int i = 0; i < index; i++, node = node->next);
			node->prev->next = node->next;
			node->next->prev = node->prev;
			delete node;
		}
		size--;
	}
	void removeTail() {
		remove(size - 1);
	}
	void removeHead() {
		remove(0);
	}

	int getSize() noexcept{
		return size;
	}

	void print() {
		if (size != 0) {
			Node *node = head;
			int i = 0;
			cout << "[";
			while (i++ != size - 1) {
				cout << node->value << ", ";
				node = node->next;
			}
			cout << node->value << "]" << endl;
		}
	}

	//T& operator[](int index) {
	//	get(index);
	//}

	LinkedList& operator=(const LinkedList &list) {
		LinkedList *tempList = new LinkedList(list);
		*this = *tempList;

	}

	~LinkedList() {
	}
};

