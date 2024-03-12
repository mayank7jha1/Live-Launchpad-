#include<bits/stdc++.h>
using namespace std;


//Task : Calculate a^b.
int a;



int Solve(int b) {

	if (b == 1) { //Stoping Point
		return a;
	}


	int ans = a * Solve(b - 1);//Task and Next Stage.
	cout << ans << endl;
	return ans;
}

int main() {
	int  b;
	cin >> a >> b;

	int ans = Solve(b);//Starting Point
	cout << ans << endl;
}