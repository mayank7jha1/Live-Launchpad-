#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {

	vector<int>v;
	stack<int>st;//Stack arrays/vector:
	//New element ko daalna is O(1) and Top ke element ke
	//ko pop  karna is O(1).

	int x;
	while (cin >> x) {
		v.push_back(x);
		st.push(x);
	}


	for (auto x : v) {
		cout << x << " ";
	}

	cout << endl;

	while (v.empty() == 0) {
		cout << v.back() << endl;
		v.pop_back();
	}

	// for (auto x : st) {
	// 	cout << x << " ";
	// }

	// cout << st.top() << endl;
	// st.pop();
	// cout << st.top() << endl;

	cout << st.empty() << endl;
	while (st.empty() == 0) {
		cout << st.top() << " ";
		st.pop();
	}

	cout << endl;

	cout << st.size() << endl;

	stack<int>st1 = st;
}