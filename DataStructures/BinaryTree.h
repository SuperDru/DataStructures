#pragma once
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <xtree>
#include "Queue.h"


#define RIGHT_LEFT (value > value_ ? right : left)

using namespace std;

template <typename T>
class BinaryTree {
private:
	struct Node : enable_shared_from_this<Node>{
		T value_;
		shared_ptr<Node> left, right;
		Node() {};
		Node(T value): value_(value){}
		~Node() {}

		void add(const T value) _NOEXCEPT {
			RIGHT_LEFT == nullptr ? RIGHT_LEFT.reset(new Node(value)) : RIGHT_LEFT->add(value);
		}

		bool contains(const T value) _NOEXCEPT {
			if (value == value_) 
				return true;
			return RIGHT_LEFT == nullptr ? false : RIGHT_LEFT->contains(value);
		}

		shared_ptr<Node> remove(const T value) _NOEXCEPT {
			if (value_ == value) {
				if (movePtr() == nullptr)
					return nullptr;
			}
			else {
				assert(RIGHT_LEFT != nullptr);
				RIGHT_LEFT = RIGHT_LEFT->remove(value);
			}
			return shared_from_this();
		}
		shared_ptr<Node> movePtr() {
			if (right != nullptr) {
				value_ = move(right->value_);
				if (right->movePtr() == nullptr) {
					right = nullptr;
					return make_shared<Node>(value_);
				}
				return right;
			}
			else if (left != nullptr) {
				value_ = move(left->value_);
				if (left->movePtr() == nullptr) {
					left = nullptr;
					return make_shared<Node>(value_);
				}
				return left;
			}
			return nullptr;
		}

		void print(int level) {
			if (this != nullptr){
				right->print(level + 1);
				for (int i = 0; i< level; i++) cout << "   ";
				cout << value_ << endl;
				left->print(level + 1);
			}
		}

		int getCount(int current, int level) {
			int result = 0;
			if (current == level) {
				if (right != nullptr) result++;
				if (left != nullptr) result++;
			}
			else {
				if (right != nullptr)
					result += right->getCount(current + 1, level);
				if (left != nullptr)
					result += left->getCount(current + 1, level);
			}
			return result;
		}
	};

	vector<T*> getSortedArray() {
		vector<T*> result;
		if (root == nullptr)
			return result;
		Stack<Node*> stack;
		Node* top = root.get();
		while (top != nullptr || !stack.isEmpty()) {
			if (!stack.isEmpty()) {
				top = stack.pop();
				result.push_back(&top->value_);
				if (top->right != nullptr)
					top = top->right.get();
				else
					top = nullptr;
			}
			while (top != nullptr) {
				stack.push(top);
				if (top->left != nullptr)
					top = top->left.get();
				else
					top = nullptr;
			}
		}
		return result;
	}

	shared_ptr<Node> root;
	int count_ = 0;
public:
	BinaryTree() {}

	void insert(const T value) _NOEXCEPT {
		count_++;
		root == nullptr ? root.reset(new Node(value)) : root->add(value);
	}

	bool contains(const T value) _NOEXCEPT {
		return root->contains(value);
	}

	void remove(const T value) _NOEXCEPT {
		assert(root != nullptr);
		count_--;
		root = root->remove(value);
	}

	void print() {
		root->print(0);
	}

	void printByQueue() {
		if (root == nullptr)
			return;
		QueueCircle<Node*> queueS(count_);
		queueS.push(root.get());
		Node* node;
		while (!queueS.isEmpty()) {
			node = queueS.pop();
			cout << node->value_ << " ";
			if (node->left != nullptr)
				queueS.push(node->left.get());
			if (node->right != nullptr)
				queueS.push(node->right.get());
		}
		cout << endl;
	}

	void printByStack() {
		if (root == nullptr)
			return;
		vector<T*> sArr = getSortedArray();
		for (int i = 0; i < sArr.size(); i++)
			cout << *sArr[i] << " ";
 	}

	bool compare(const BinaryTree &tree) {
		vector<T*> sArr1 = getSortedArray();
		vector<T*> sArr2 = const_cast<BinaryTree&>(tree).getSortedArray();
		if (sArr1.size() != sArr2.size())
			return false;
		for (int i = 0; i < sArr1.size(); i++)
			if (*sArr1[i] != *sArr2[i]) 
				return false;
		return true;
	}

	int getCount(int level) {
		if (level == 0 && root != nullptr)
			return 1;
		return root->getCount(1, level);
	}

	void clear() {
		root = nullptr;
		count_ = 0;
	}

	int count() { 
		return count_; 
	}

};