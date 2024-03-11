#include<iostream>
#include<climits>
using  namespace std;

int Solve(int i, int x) {

	if (i == x) {
		return 1;
	}

	int Op1 = Solve(i + 1, x);

	int Op2 = 0;

	if (i + 2 <= x) {
		Op2 = Solve(i + 2, x);
	}

	int ans = Op1 + Op2;

	return ans;
}


int main() {
	int n;
	cin >> n;

	cout << Solve(0, n - 1) << endl;
}