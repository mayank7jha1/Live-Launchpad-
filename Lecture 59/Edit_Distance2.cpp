#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class Solution {
public:
	int minDistance(string s, string p) {
		int dp[501][501];

		int n = s.length();
		int m = p.length();

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {

				if (i == 0) {
					dp[i][j] = j;

				} else if (j == 0) {

					dp[i][j] = i;

				} else if (s[i - 1] == p[j - 1]) {

					dp[i][j] = dp[i - 1][j - 1];

				} else {

					dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});

				}
			}
		}

		return dp[n][m];
	}
};





int main() {

}