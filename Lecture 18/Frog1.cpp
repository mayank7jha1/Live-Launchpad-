#include<iostream>
#include<vector>
#include<climits>
using  namespace std;

int Solve(int i, int* a, int x) {

	if (i == x) {
		return 0;
	}

	int Option1 = abs(a[i] - a[i + 1]) + Solve(i + 1, a, x);

	int Option2 = INT_MAX;

	if (i + 2 <= x) {
		Option2 = abs(a[i] - a[i + 2]) + Solve(i + 2, a, x);
	}


	int ans = min(Option1, Option2);
	return ans;

}

int main() {
	int n;
	cin >> n;
	int a[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << Solve(1, a, n) << endl;

}



