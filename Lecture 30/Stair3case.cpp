#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int Min_Steps = INT_MAX;//Min Steps to reach the top.


/*
	int Count: Steps to reach the top in the current path.
	int Min_Steps: Min Steps to reach the top across all the paths.


*/

void Solve(int* a, int n, bool* visited, int Stair_No, int Count) {


	if (Stair_No == n) {
		Min_Steps = min(Min_Steps, Count);
		return;
	}

	visited[Stair_No] = 1;


	//Option 1: When from the current stair I am taking one Step ka Jump.
	if (Stair_No + 1 <= n and visited[Stair_No + 1] == 0) {

		Solve(a, n, visited, Stair_No + 1, Count + 1);

	}


	/*	8th Stair_No par khade hain: Magnitude is 10:
		It is not possible to take a jump of 10 steps from 8th staircase as aap aage pahuch jaaoge and question me bola hain ki aapko 10th stair par hi pahuchna hain.
		*/

	//Option2: When we are Jumping the magnitude of the stair ka Jump.
	if (Stair_No + a[Stair_No] <= n and Stair_No + a[Stair_No] >= 0
	        and visited[Stair_No + a[Stair_No]] == 0) {

		Solve(a, n, visited, Stair_No + a[Stair_No], Count + 1);
	}


	visited[Stair_No] = 0;//Backtracking


}


int main() {
	int t;
	cin >> t;

	while (t--) {

		Min_Steps = INT_MAX;

		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		bool visited[100005] = {0};

		Solve(a, n, visited, 0, 0);

		cout << Min_Steps << endl;

	}
}