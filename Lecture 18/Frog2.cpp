#include<iostream>
#include<vector>
#include<climits>
using  namespace std;

int Solve(int i, int* a, int x, int k) {

	if (i == x) {
		return 0;
	}

	int ans = INT_MAX;

	for (int jump = 1; jump <= k; jump += 1) {

		int Op = INT_MAX;

		if (i + jump <= x) {

			Op = abs(a[i] - a[i + jump]) +
			     Solve(i + jump, a, x, k);
		}

		ans = min(ans, Op);
	}

	return ans;
}



int main() {
	int n, k;
	cin >> n >> k;
	int a[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << Solve(1, a, n, k) << endl;

}
