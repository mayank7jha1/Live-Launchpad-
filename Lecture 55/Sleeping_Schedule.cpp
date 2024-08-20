#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int n, h, l, r;
int a[20001];
int dp[2001][2001];

// 7
// solve(7, WT): Max good sleep if we want to have 7th sleep 0.

int Solve(int i, int WT) {

	if (i == n) {
		return 0;
	}

	//Current Sleep index is i and Current waking time is WT.
	if (dp[i][WT] != -1) {
		return dp[i][WT];
	}

	/*

		Solve(i,WT)=max(Op1,Op2);

		Op1=  Next Sleep Good Hain ki nahi agar main + Solve(i+1,(WT+ai)%h);
			  ai par sone jaata hu.

		Op2= Next Sleep Good Hain ki nahi agar main + Solve(i+1,(WT+(ai-1))%h);
			  (ai-1) par sone jaata hu.

	*/



	int NSG_OP1 = (WT + a[i]) % h;

	int NSG_OP2 = (WT + a[i] - 1) % h;

	int ans1 = 0, ans2 = 0;

	if (NSG_OP1 >= l and NSG_OP1 <= r) {
		ans1 = 1;
	}

	if (NSG_OP2 >= l and NSG_OP2 <= r) {
		ans2 = 1;
	}


	int Op1 = ans1 + Solve(i + 1, (WT + a[i]) % h);
	int Op2 = ans2 + Solve(i + 1, NSG_OP2);


	return dp[i][WT] = max(Op1, Op2);
}



int32_t main() {
	cin >> n >> h >> l >> r;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << Solve(0, 0) << endl;
}



