#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	queue<int>q;

	int x;

	while (cin >> x) {
		q.push(x);
	}

	// cout << q.front() << endl;
	// q.pop();
	// cout << q.front() << endl;

	while (q.empty() == 0) {
		cout << q.front() << endl;
		q.pop();
	}

	cout << q.size() << endl;
	queue<int>q1 = q;//= is overloaded for every container.
}