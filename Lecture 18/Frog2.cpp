#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//Generalised for Staircase Problem.

int Solve(int i, int* height, int x, int k) {

	if (i == x) {
		return 0;
	}

	//THis variable will store my min cost across all the paths.
	int ans = INT_MAX;

	for (int jump = 1; jump <= k; jump++) {

		int Op = INT_MAX;//Current Path ka answer kya hain.

		if (i + jump <= x) {
			Op = abs(height[i] - height[i + jump]) + Solve(i + jump, height, x, k);
		}

		ans = min(ans, Op);

	}

	return ans;

}


int main() {
	int n, k;
	cin >> n >> k;

	int height[n + 1] = {0};

	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}

	cout << Solve(1, height, n, k) << endl;

}