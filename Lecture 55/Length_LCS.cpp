#include<bits/stdc++.h>
using namespace std;
const int N = 3001;
#define int long long
int dp[N][N];


string getLCS(string &s, string &t, int LCS) {

	string ans = "";

	int i = 0, j = 0;

	while (LCS > 0) {

		if (s[i] == t[j]) {
			//This character will most definedly be part of my LCS.
			ans.push_back(s[i]);
			i++;
			j++;
			LCS--;
		} else {

			//s[i]!=t[j]: Now i have two options choose the option with
			// longest subsequence using dp.

			if (dp[i][j + 1] > dp[i + 1][j]) {
				j++;
			} else {
				i++;
			}
		}
	}

	return ans;
}




int lengthLCS(string &a, string &b, int i, int j) {
	if (i >= a.length() or j >= b.length()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (a[i] == b[j]) {

		return dp[i][j] = lengthLCS(a, b, i + 1, j + 1) + 1;
	}
	else {

		int op1 = lengthLCS(a, b, i + 1, j);
		int op2 = lengthLCS(a, b, i, j + 1);

		return dp[i][j] = max(op1, op2);
	}
}


string Solve(string &s, string &t) {

	memset(dp, -1, sizeof(dp));

	//I want to Fill the DP Array and Want the Length of LCS.
	int len = lengthLCS(s, t, 0, 0);

	return getLCS(s, t, len);
}


int32_t main() {

	cerr << "ejjjkj" << endl;
	string s, t;
	cin >> s >> t;

	cout << Solve(s, t) << endl;

}