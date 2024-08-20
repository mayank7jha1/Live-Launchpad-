#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
#define int long long

int n, k;
vector<int>taste, calorie;
int dp[100][2 * N];


/*
	Time Complexity: O(State)*O(Transition Time)
	Space Complexity: O(State)

	Time Complexity: O(100*100000)*O(1): ~~10^7
	Space Complexity: O(100*100000):     ~~10^7

*/

int Solve(int i, int sum) {

	if (i == n) {
		if (sum == 0) {
			return 0;
		} else {
			return -1e12;
		}
	}

	if (dp[i][sum + N] != -1) {
		return dp[i][sum + N];
	}

	int Op1 = taste[i] + Solve(i + 1, sum + (taste[i] - (k * calorie[i])));
	int Op2 = 0 + Solve(i + 1, sum);

	return dp[i][sum + N] = max(Op1, Op2);
}


int32_t main() {

	cin >> n >> k;
	taste.resize(n);
	calorie.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	memset(dp, -1, sizeof(dp));

	int ans = Solve(0, 0);

	if (ans <= 0) {
		cout << "-1" << endl;
	} else {
		cout << ans << endl;
	}

}