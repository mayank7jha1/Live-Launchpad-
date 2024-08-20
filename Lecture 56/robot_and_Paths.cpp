#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
#define mod 1000000007
int n, m, p;
int grid[1001][1001];

//grid[x][y]=-1: Blocked Cell.

int Solve() {

	int dp[1001][1001] {{0}};

	if (grid[1][1] == -1 or grid[n][m] == -1) {
		return 0;
	}

	dp[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (i == 1 and j == 1) {
				continue;
			}

			if (grid[i][j] == -1) {
				dp[i][j] = 0;
			} else {

				if (j == 1) {
					//This means I am At the first column.
					dp[i][j] = dp[i - 1][j] % mod;
				} else if (i == 1) {
					//I am Standing at the first row.
					dp[i][j] = dp[i][j - 1] % mod;
				} else {

					dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;
				}
			}
		}
	}

	return dp[n][m] % mod;
}

int32_t main() {

	cin >> n >> m >> p;
	// cout << n << m << endl;
	while (p--) {

		int x, y;
		cin >> x >> y;

		grid[x][y] = -1;
	}

	cout << Solve() << endl;
	//cout << "Mayank";


}