#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {

	priority_queue<int>pq;//Max Priority Queue.

	priority_queue<int, vector<int>, greater<int>>mpq;//Min Priority Queue

	int x;

	//nlogn
	while (cin >> x) {
		pq.push(x);
		mpq.push(x);
	}

	//nlogn
	while (pq.empty() == 0) {
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << endl;

	//nlogn
	while (mpq.empty() == 0) {
		cout << mpq.top() << " ";
		mpq.pop();
	}
	cout << endl;
	cout << pq.size() << endl;

}