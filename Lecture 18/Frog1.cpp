#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int Solve(int i, int* height, int x) {

	if (i == x) {
		return 0;
	}


	int Op1 = abs(height[i] - height[i + 1]) + Solve(i + 1, height, x);


	int Op2 = INT_MAX;
	if (i + 2 <= x) {
		Op2 = abs(height[i] - height[i + 2]) + Solve(i + 2, height, x);
	}


	return min(Op1, Op2);

}


int main() {
	int n;
	cin >> n;

	int height[n + 1] = {0};

	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}

	cout << Solve(1, height, n) << endl;

}