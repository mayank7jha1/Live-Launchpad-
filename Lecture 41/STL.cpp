#include<bits/stdc++.h>
using namespace std;
const int N = 0;

/*

	Sequence Container:
	Singly Linked List: forward_list
	Doubly Linked List: list

*/


int main() {
	vector<int>v = {1, 2, 3, 4};
	forward_list<int>f = {1, 2, 3, 4};
	list<int>l = {1, 2, 3, 4, 5};

	vector<int>v1 = v;
	forward_list<int>f1 = f;
	list<int>l1 = l;

	f1.push_front(10);
	//f1.push_back(10);

	cout << f1.front() << endl;

	l1.push_front(10);
	l1.push_back(20);

	cout << l1.back() << endl;
	cout << l1.front() << endl;

	for (forward_list<int>::iterator x = f1.begin(); x != f1.end(); x++) {
		cout << (*x) << " ";
	}

	cout << endl;

	for (int x : f1) {
		cout << x << " ";
	}

	cout << endl;


	for (list<int>::iterator x = l1.begin(); x != l1.end(); x++) {
		cout << (*x) << " ";
	}

	cout << endl;

	for (int x : l1) {
		cout << x << " ";
	}

	cout << endl;

	l1.pop_back();
	l1.pop_front();

	f1.pop_front();

	l1.sort();
	l1.reverse();
	f1.sort();
	f1.reverse();
}