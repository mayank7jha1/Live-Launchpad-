#include<bits/stdc++.h>
using namespace std;
const int N = 0;

/*

	Check If the current Problem contains OVerlapping Sub Problems:
	if Yes then Apply Dynamic Programming.

	Changing Parameter: One Changing Parameter:
	Meri State Only One thing par dependent hain and Meri State 2 other states
	par dependent hain.


	ith state ka answer dp[i+34]

	i+3 rd  state ka answer dp[i+37]

	ith state ka answer main : dp[i] me store karta hain.

	f(i): Min Cost of frog going from ith stone to n th stone.

	which is stored in dp[i].

	so I can say:

	dp[i]= Min COst of Frog Going from ith stone to nth stone.

	dp[i] ek state ka answer hain.

*/

vector<int>dp;

int Solve(int i, int* height, int x) {

	if (i == x) {
		return 0;
	}

	//Currently We are calculating the answer for the state:
	//i.
	//Before Calculating check if you have already calculated its answer.

	//Maine Agar current state i.e. ith state ka answer agar calculate kiya
	//hoga toh store kiya hain and store kiya hoga dp[i] me.

	if (dp[i] != INT_MIN) {
		return dp[i];//YOu donot need to calculate its answer return directly.
	}


	int Op1 = abs(height[i] - height[i + 1]) + Solve(i + 1, height, x);


	int Op2 = INT_MAX;
	if (i + 2 <= x) {
		Op2 = abs(height[i] - height[i + 2]) + Solve(i + 2, height, x);
	}


	//YOu are returning the answer for the current state:
	//Store this answer before returning because else it will be lost and
	//I might need this answer again as there are overlapping sub problems
	//or mutiple states repeating.

	return dp[i] = min(Op1, Op2);
}


int main() {
	int n;
	cin >> n;

	int height[n + 1] = {0};

	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}

	for (int i = 0; i < n; i++) {
		cout << height[i] << " ";
	}

	dp.resize(n, INT_MIN);//I have Initialised it with value that can never become an
	//answer for a state.

	cout << Solve(1, height, n) << endl;

}