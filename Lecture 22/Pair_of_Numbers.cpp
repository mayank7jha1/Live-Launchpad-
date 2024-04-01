#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int target;
int ans = INT_MAX;//Min Steps to reach target out of all the paths.

/*
	Task In Hand:
	1. Identify which all pairs can make my target.
	2. After this idividually check how many steps do the
	above pairs take to reach (1,1).
	3. Find Min of these steps.
*/

void Function(int x, int y, int steps) {//Steps here is a parameter that counts number of steps in the current path.

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

	if (target == 1) {//1 ko banane me kitne steps lagte hain from (1,1).
		ans = 0;
		return;
	}

	//target: (i,target-i) (where i goes from 1 to target-1).

	for (int i = 1; i < target; i++) {
		//I will Ask Recursion now that in how many steps I will reach 1,1 from the current
		//pair (i,target-i) that make my target.

		Function(i, target - i, 1);//1 Here represents steps and why I have initialised it
		//with 1 because you take 1 step from this pair (i,target-i) to reach target.
	}

}


int main() {
	cin >> target;
	Solve(target);
	cout << ans << endl;
}