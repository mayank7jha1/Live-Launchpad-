#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
#define int long long

vector<int>dp;

/*
	Time Complexity: O(100000)*O(1)
	Space Complexity: O(100000)
*/

int Solve(int n, int k) {

	if (n == 0) {
		return 1;
	}

	if (dp[n] != -1) {
		return dp[n];
	}
	int Op1 = Solve(n - 1, k);

	int Op2 = 0;
	if (n - k >= 0) {
		Op2 = Solve(n - k, k);
	}


	return dp[n] = Op1 + Op2;
}

int32_t main() {
	int n, k;
	cin >> n >> k;
	dp.resize(n + 1, -1);

	//dp[3]: Total ways to eat 3 flowers  from index 0 to 2.
	//dp[n]:Total ways to eat flowers from 0 to n-1.
	// size: 0--->n: n+1

	cout << Solve(n, k) << endl;
}