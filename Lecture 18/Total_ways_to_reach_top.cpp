#include<bits/stdc++.h>
using namespace std;
const int N = 0;


//Solve(0,x): Total Ways to reach the xth stair from 0th stair.
//Solve(1,x): Total ways to reach the xth stair from 1st stair.

//Solve(i,x): Total ways to reach the xth stair from ith stair.


int Solve(int i, int x) {

	if (i == x) {
		return 1;
	}


	int Option1 = Solve(i + 1, x);

	int Option2 = 0;

	if (i + 2 <= x) {
		Option2 = Solve(i + 2, x);
	}

	int ans = Option1 + Option2;
	return ans;

}


int main() {
	int n;
	cin >> n;

	cout << Solve(0, n) << endl;
}