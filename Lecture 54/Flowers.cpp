#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
#define int long long
#define mod 1000000007

vector<int>dp;
int pre[N];
int k;

/*
	Time Complexity: O(100000)*O(1)
	Space Complexity: O(100000)
*/

/*
	dp[i] : No of ways to eat i flowers.
	pre[i]: Sum of no of ways to eat 1 to i flowers.
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

void Precompute() {

	dp.resize(N, -1);//I am before hand calculating the
	//number of ways to eat flowers upto 10^5.

	pre[0] = 0;

	//Pre[i]=Pre[i-1]+a[i]

	for (int i = 1; i < N; i++) {
		//Solve(i,k): i flowers ko arrange karne ke ways.
		pre[i] = pre[i - 1] + Solve(i, k);
		pre[i] %= mod;
	}
}

int32_t main() {

	int t;
	cin >> t >> k;
	// cout << t << k << endl;
	Precompute();

	while (t--) {

		int l, r;
		cin >> l >> r;

		cout << (pre[r] - pre[l - 1] + mod) % mod << endl;
	}
}