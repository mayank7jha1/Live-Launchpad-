#include<bits/stdc++.h>
using namespace std;
const int N = 0;
map<int, int>freq;

void Solve(int n) {

	if (n <= 0) {
		return;
	}

	freq[n]++;

	Solve(n - 1);
	Solve(n - 2);
}


int main() {
	int n;
	cin >> n;
	Solve(n);

	for (auto x : freq) {
		cout << x.first << " " << x.second << endl;
	}
}