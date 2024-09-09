#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class Solution {
public:


	bool Solve(string &s, int i, unordered_set<string>&us, vector<int>&dp) {


		if (i == s.size()) {
			return true;
		}

		if (dp[i] != -1) {
			return dp[i];
		}

		for (int j = i; j < s.size(); j++) {

			if (us.count(s.substr(i, j - i + 1)) == 1 and Solve(s, j + 1, us, dp) == 1) {

				return dp[i] = 1;
			}
		}

		return dp[i] = false;

	}


	bool wordBreak(string s, vector<string>& dic) {

		vector<int>dp(s.size(), -1);
		unordered_set<string>us(dic.begin(), dic.end());
		return Solve(s, 0, us, dp);
	}
};



class Solution2 {
public:

	bool wordBreak(string s, vector<string>& dic) {

		vector<bool>dp(s.size() + 1, 0);
		unordered_set<string>us(dic.begin(), dic.end());
		dp[0] = true;

		for (int i = 1; i <= s.size(); i++) {

			for (int j = 0; j < i; j++) {
				if (dp[j] == 1  and us.count(s.substr(j, i - j)) == 1) {
					dp[i] = true;
				}
			}
		}

		return dp[s.size()];
	}
};

int main() {

}



