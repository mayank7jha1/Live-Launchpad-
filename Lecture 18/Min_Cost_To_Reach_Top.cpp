#include<bits/stdc++.h>
using namespace std;
const int N = 0;


//Solve(0,cost,x): Min Cost to reach the xth stair from the 0th stair.

int Solve(int i, int* cost, int x) {

	if (i == x) {
		return 0;
	}

	int Op1 = cost[i] + Solve(i + 1, cost, x);
	int Op2 = INT_MAX;

	if (i + 2 <= x) {
		Op2 = cost[i] + Solve(i + 2, cost, x);
	}

	return min(Op1, Op2);

}


int main() {
	int n;
	cin >> n;

	int cost[n];

	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	//I Can Stand Initially at 0 or at 1.

	//I Will First Calculate My answer when I am Standing at zero.

	int x = Solve(0, cost, n);

	int y = Solve(1, cost, n);

	cout << min(x, y) << endl;
}