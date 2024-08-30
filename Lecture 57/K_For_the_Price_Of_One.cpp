#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
int n, p, k;
int cost[200002];

//Greedy+DP: Sort: Greedy Approach: If i want to buy 10 items and k=3 is given
// i want to apply the offer on the most expensive items for that i have sorted the data.


//Dp : Even though maine data sort kardiya hain kya aap mujhe directly bata sakte ho ki kitne itmes main khareed sakta hu?

//DP: Because we have calculated the answer answer for every state.
//Matlab main 5 item , 10 item 20

int Solve() {

	int dp[200002];

	sort(cost + 1, cost + n + 1);


	for (int i = 1; i <= n; i++) {

		if (i < k) {
			dp[i] = dp[i - 1] + cost[i];
		} else if (i == k) {
			dp[i] = cost[i];
		} else {
			dp[i] = dp[i - k] + cost[i];
		}
	}

	int ans = 0;//Maximum itmes i can buy with the price i have.

	for (int i = 1; i <= n; i++) {
		if (dp[i] <= p) {
			//You can buy items till i index
			ans = i;
		}
	}

	return ans;

}

int32_t main() {
	int t;
	cin >> t;

	while (t--) {

		cin >> n >> p >> k;

		for (int i = 1; i <= n; i++) {
			cin >> cost[i];
		}

		cout << Solve() << endl;

	}
}




//Standard Question of Leetcode.