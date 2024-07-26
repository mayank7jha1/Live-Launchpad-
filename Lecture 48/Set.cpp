#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
const int N = 0;

int main() {

	set<int>s;
	unordered_set<int>us;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
		us.insert(x);
	}


	for (int x : s) {
		cout << x << endl;
	}

	cout << endl << endl << endl;

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}

	cout << endl << endl << endl;

	for (int x : us) {
		cout << x << endl;
	}

	cout << endl << endl << endl;

	for (auto it = us.begin(); it != us.end(); it++) {
		cout << *it << endl;
	}


	//THis will bring me the value of the lower bound of 10 inside the set.
	cout << *s.lower_bound(10) << endl;
	cout << *s.upper_bound(10) << endl;


}