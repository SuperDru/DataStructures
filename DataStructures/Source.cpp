#include <conio.h>
#include <iostream>
#include "BinaryTree.h"
#include "Queue.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));

	//QueueCircle<int> qc;

	//for (int i = 0; i < 15; i++)
	//	qc.push(i);

	//qc.print();
	//cout << qc.size() << endl;

	//for (int i = 0; i < 15; i++)
	//	cout << qc.pop() << " ";

	//cout << endl;

	//qc.print();
	//cout << qc.size() << endl;

	//for (int i = 0; i < 3; i++)
	//	qc.push(rand() % 100);

	//qc.print();

	//for (int i = 0; i < 30; i++)
	//	qc.push(rand() % 100);

	//for (int i = 0; i < 3; i++)
	//	cout << qc.pop() << " ";

	//cout << qc.size() << endl;
	//qc.print();

	//for (int i = 0; i < 40; i++)
	//	qc.push(rand() % 100);

	//cout << qc.size() << endl;
	//qc.print();

	//while (!qc.isEmpty()) {
	//	cout << qc.pop() << " ";
	//}

	//cout << endl << qc.size();

	BinaryTree<int> t1, t2;

	//do {
	//	tree.clear();
	//	tree2.clear();
	//	for (int i = 0; i < 5; i++)
	//		tree.add(rand() % 100);

	//	for (int i = 0; i < 5; i++)
	//		tree2.add(rand() % 100);
	//} while (!tree.compare(tree2));

	t1.insert(5);
	t1.insert(1);
	t1.insert(0);
	t1.insert(8);
	t1.insert(9);
	t1.insert(3);
	t1.insert(2);
	t1.insert(6);
	t1.insert(7);

	t2.insert(8);
	t2.insert(6);
	t2.insert(1);
	t2.insert(2);
	t2.insert(3);
	t2.insert(5);
	t2.insert(7);

	//t1.remove(5);
	//t1.remove(2);
	//t2.remove(5);
	//t2.remove(2);

	t1.print();
	cout << endl;
	//t1.printByQueue();
	//cout << endl;
	//t2.printByStack();
	//cout << endl;
	//t1.printByStack();
	//cout << endl << endl;
	//t2.print();
	cout << endl;
	cout << t2.contains(2) << endl;
	cout << t2.contains(1) << endl;

	cout << t1.getCount(0) << endl;
	//cout << (t1.compare(t2) ? "Trees are equal." : "Trees aren't equal.") << endl;

	//Stack<int> stack1;

	//for (int i = 0; i < 10; i++)
	//	stack1.push(i);

	//for (int i = 0; i < 5; i++)
	//	cout << stack1.pop() << " ";

	//cout << "\n";

	//if (stack1.isEmpty())
	//	cout << "stack1 is empty.";
	//else
	//	cout << "stack1 isn't empty.\n";

	//stack1.print();

	//for (int i = 0; i < 5; i++)
	//	cout << stack1.pop() << " ";

	//cout << "\n";

	//if (stack1.isEmpty())
	//	cout << "stack1 is empty.";
	//else
	//	cout << "stack1 isn't empty.";

	_getch();
	return 0;
}
