#pragma once
#include <vector>
#include <cassert>

using namespace std;


template <typename T>
class BinaryHeap {
private:
	vector<T> arr;

	void siftDown(int i) {
		int max = i,
			left = i * 2 + 1,
			right = i * 2 + 2;

		if (left < arr.size() && arr[left] > arr[max])
			max = left;
		if (right < arr.size() && arr[right] > arr[max])
			max = right;

		if (max != i) {
			swap(arr[i], arr[max]);
			siftDown(max);
		}
	}
	void siftUp(int i) {
		if (i == 0)
			return;

		int par = (i - 1) / 2;
		if (arr[i] > arr[par]) {
			swap(arr[i], arr[par]);
			siftUp(par);
		}
	}
public:
	BinaryHeap(): 
		BinaryHeap(5){}
	BinaryHeap(int size) {
		arr.reserve(size);
	}

	void push(const T item) {
		arr.push_back(item);
		siftUp(arr.size() - 1);
	}

	T& popMax() {
		assert(!arr.empty());
		T result = arr[0];
		swap(arr[0], arr[arr.size() - 1]);
		arr.pop_back();
		siftDown(0);
		return result;
	}
	T peekMax() {
		assert(!arr.empty());
		return arr[0];
	}
};