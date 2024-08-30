#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int dp[1001][1001] = {{0}}; //Single Array
int n, m;

int32_t main() {
	cin >> n >> m;

	while (m--) {
		int x, y;
		cin >> x >> y;
		dp[x][y]++;
	}

	// int n;
	// cin >> n;

	// //int dp[n + 1][n + 1] = {{0}};

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cin >> dp[i][j];
	// 	}
	// }

	//Precomputation.

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//Prefix Sum Row Wise.
			dp[i][j] = dp[i][j] + dp[i][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//Prefix Sum Column Wise.
			dp[i][j] = dp[i - 1][j] + dp[i][j];
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


	int ans = INT_MIN;//Maximum Gold Coin Sayyam can have across any x,y.

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {

			int Op1 = dp[i][j];
			int Op2 = dp[i][n] - Op1;
			int Op3 = dp[n][j] - Op1;
			int Op4 = dp[n][n] - Op1 - Op2 - Op3;

			int Sayyam = min({Op1, Op2, Op3, Op4});
			ans = max(Sayyam, ans);
		}
	}

	cout << ans << endl;



}



