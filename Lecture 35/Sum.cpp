#include<bits/stdc++.h>
using namespace std;
const int N = 0;


/*
	Print me the sum of the array but if a[i]==3
	skip that number

*/


int main() {

// #ifndef ONLINE_JUDGE
// 	freopen("../inputf.in", "r", stdin);
// 	freopen("../outputf.out", "w", stdout);
// 	freopen("../errorf.out", "w", stderr);
// #endif

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//cerr << "Mayank" << endl;

	int sum = 0;
	for (int i = 0; i < n; i++) {

		// if (a[i] == 3) {
		// 	continue;
		// }

		sum += a[i];
	}
	cout << sum << endl;
}