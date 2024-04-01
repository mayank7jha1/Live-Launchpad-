#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int target;
int ans = INT_MAX;


void Function(int x, int y, int steps) {
	if (x == 1 and y == 1) {
		ans = min(steps, ans);
		return;
	}

	if (x - y > 0) {
		Function(x - y, y, steps + 1);
	}

	if (y - x > 0) {
		Function(x, y - x, steps + 1);
	}
}

void Solve(int target) {

	if (target == 1) {
		ans = 0;
		return;
	}

	for (int i = 1; i < target; i++) {
		Function(i, target - i, 1);
	}

}


int main() {
	cin >> target;
	Solve(target);
	cout << ans << endl;
}