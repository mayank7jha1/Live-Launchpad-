#include<bits/stdc++.h>
using namespace std;
const int N = 1002;
char grid[N][N];
#define mod 1000000007
#define int long long

int n, m;

int Solve() {
	int dp[1001][1001] {{0}};

	if (grid[1][1] == '#' or grid[n][m] == '#') {
		return 0;
	}

	dp[n][m] = 1;

	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {

			if (i == n and j == m) {
				continue;
			}

			if (grid[i][j] == '#') {
				dp[i][j] = 0;
			} else {

				if (j == m) {
					//This means I am At the first column.
					dp[i][j] = dp[i + 1][j] % mod;
				} else if (i == n) {
					//I am Standing at the first row.
					dp[i][j] = dp[i][j + 1] % mod;
				} else {

					dp[i][j] = (dp[i + 1][j] % mod + dp[i][j + 1] % mod) % mod;
				}
			}
		}
	}

	return dp[1][1] % mod;
}


int32_t main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> grid[i][j];
		}
	}

	cout << Solve() << endl;
}