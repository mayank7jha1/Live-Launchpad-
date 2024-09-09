#include<bits/stdc++.h>
using namespace std;
const int N = 0;


class Solution {
public:

	bool Solve(int i, int j, string &s, string &p, vector<vector<int>>&dp) {

		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		if (i == 0 and j == 0) {
			return dp[i][j] = 1;
		}

		if (j == 0 and i > 0) {
			return dp[i][j] = 0;
		}

		if (i == 0 and j > 0) {
			while (j > 0) {
				if (p[j - 1] == '*') {
					j--;
				} else {
					return dp[i][j] = 0;
				}
			}
			return dp[i][j] = 1;
		}


		if (s[i - 1] == p[j - 1] or p[j - 1] == '?') {
			return dp[i][j] = Solve(i - 1, j - 1, s, p, dp);
		}

		if (p[j - 1] == '*') {
			return dp[i][j] = (Solve(i - 1, j, s, p, dp) or Solve(i, j - 1, s, p, dp));
		}

		return dp[i][j] = 0;
	}

	bool isMatch(string s, string p) {
		int n = s.length(), m = p.length();
		vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
		return Solve(n, m, s, p, dp);
	}
};



class Solution2 {
public:
	bool isMatch(string s, string p) {
		int n = s.length(), m = p.length();
		vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, -1));

		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i][0] = 0;
		}

		bool flag = 1;

		for (int j = 1; j <= m; j++) {
			if (p[j - 1] != '*') {
				flag = 0;
			}

			dp[0][j] = flag;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i - 1] == p[j - 1] or p[j - 1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*') {
					dp[i][j] = (dp[i - 1][j] or dp[i][j - 1]);
				} else {
					dp[i][j] = 0;
				}

			}
		}

		return dp[n][m];
	}
};


int main() {

}