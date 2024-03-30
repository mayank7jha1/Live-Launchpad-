#include<iostream>
#include<climits>
using  namespace std;
int target;
#define int long long

// 64 bit ka int hain

//TLE: Optimised Code:


int Solve(int x, int y) {

	if (x > target or y > target) {
		//Return something so big that can never
		//become my answer.
		return INT_MAX;
	}

	if (x == target or y == target) {
		return 0;
	}

	long long Op1 = Solve(x + y, y);
	long long Op2 = Solve(x, x + y);

	long long value = min(Op1, Op2) + 1;

	return value;

}


int32_t main() {
	cin >> target;
	long long ans = Solve(1, 1);
	cout << ans << endl;
}

