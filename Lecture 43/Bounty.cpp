#include<bits/stdc++.h>
using namespace std;
#define int long long
const int m = 10007;


//Log(n):
int FP(int a, int b) {
	int result = 1;
	while (b > 0) {
		if (b & 1) {
			result = (((result % m) * (a % m)) % m);
		}
		a = ((a % m) * (a % m)) % m;
		b = b >> 1;
	}
	return result;
}

int32_t main() {
	int n;
	cin >> n;

	int Part1 = (9 * FP(10, n - 1)) % m;
	int Part2 = FP(9, n) % m;
	int Part3 = ((n - 1) * FP(9, n - 1) + m) % m;

	cout << (Part1 - Part2 - Part3 + m + m) % m << endl;
}




// (a - b - c) % m: