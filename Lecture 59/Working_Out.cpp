#include<bits/stdc++.h>
using namespace std;
const int N = 1001;
#define int long long


/*

	Space: 4*(1000*1000): (10^8)
	Time: (1000*1000*4)+1000*1000=4*10^6+10^6=(5*10^6)

	2*10^8 Computations Allowed hain.

*/


/*
	dp1[i][j]:Maximum From (1,1) to (x,y).
	dp2[i][j]:Maximum from (n,m) to (x,y).
	dp3[i][j]:Maximum from (n,1) to (x,y).
	dp4[i][j]:Maximum from (1,m) to (x,y).
*/


int dp1[N][N];
int dp2[N][N];
int dp3[N][N];
int dp4[N][N];

int cost[N][N];

int32_t main() {
	int n, m;
	cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> cost[i][j];
		}
	}


	//DP1
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (i == 1 and j == 1) {
				dp1[i][j] = cost[i][j];
				continue;
			} else if (i == 1) {
				dp1[i][j] = dp1[i][j - 1] + cost[i][j];
			} else if (j == 1) {
				dp1[i][j] = dp1[i - 1][j] + cost[i][j];
			} else {
				dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + cost[i][j];
			}
		}
	}


	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		cout << dp1[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl << endl;

	//DP2
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {

			if (i == n and j == m) {
				dp2[i][j] = cost[i][j];
				continue;
			} else if (i == n) {
				dp2[i][j] = dp2[i][j + 1] + cost[i][j];
			} else if (j == m) {
				dp2[i][j] = dp2[i + 1][j] + cost[i][j];
			} else {
				dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + cost[i][j];
			}
		}
	}



	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		cout << dp2[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl << endl;

	//DP3
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {

			if (i == n and j == 1) {
				dp3[i][j] = cost[i][j];
				continue;
			} else if (i == n) {
				dp3[i][j] = dp3[i][j - 1] + cost[i][j];
			} else if (j == 1) {
				dp3[i][j] = dp3[i + 1][j] + cost[i][j];
			} else {
				dp3[i][j] = max(dp3[i + 1][j], dp3[i][j - 1]) + cost[i][j];
			}
		}
	}



	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		cout << dp3[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl << endl;



	//DP4
	for (int i = 1; i <= n; i ++) {
		for (int j = m; j >= 1; j--) {

			if (i == 1 and j == m) {
				dp4[i][j] = cost[i][j];
				continue;
			} else if (i == 1) {
				dp4[i][j] = dp4[i][j + 1] + cost[i][j];
			} else if (j == m) {
				dp4[i][j] = dp4[i - 1][j] + cost[i][j];
			} else {
				dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + cost[i][j];
			}
		}
	}


	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		cout << dp4[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl << endl;

	int ans = INT_MIN;

	//Potential (x,y)

	for (int i = 2; i <= n - 1; i++) {
		for (int j = 2; j <= m - 1; j++) {

			//Op1: Boy Comes from Left and Goes Right and Girl Comes from down and Goes up.
			int Op1 = dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j];

			//Op2: Boy Comes from Top and Goes Down and Girl Comes from left and Goes right.
			int Op2 = dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1];


			int Current_Max = max(Op1, Op2);
			ans = max(ans, Current_Max);
		}
	}


	cout << ans << endl;
}





