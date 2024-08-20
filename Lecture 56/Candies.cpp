#include<bits/stdc++.h>
using namespace std;
const int N = 103;
#define int long long
#define mod 1000000007
int n, k;
vector<int>a;
int dp[101][N] = {0};

int Solve() {

	//Part 1:

	for (int j = 0; j <= k; j++) {
		if (j <= a[1]) {
			dp[1][j] = 1;
		} else {
			dp[1][j] = 0;
		}
	}


	//Part 2 and Part 3 Ko club kar raha hu.

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {

			//Part 2:
			if (j == 0) {

				dp[i][j] = (dp[i - 1][j]) % mod;

			} else {

				//Part 3:

				int A = dp[i][j - 1] % mod;
				int B = dp[i - 1][j] % mod;

				//j-a[i]-1 <=0

				int C = 0;
				if (j - a[i] - 1 >= 0) {
					C = dp[i - 1][j - a[i] - 1] % mod;
				}

				dp[i][j] = (A + B - C + mod) % mod;
			}

		}
	}


	return dp[n][k];
}


int32_t main() {
	cin >> n >> k;
	a.resize(n + 3);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}



	cout << Solve() << endl;

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j <= k; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

}