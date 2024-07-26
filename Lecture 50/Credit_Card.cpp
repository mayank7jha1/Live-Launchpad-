#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int n, d;
int a[100005] {0};



void Solve() {


	//Check if My Answer Exist or not.

	int BB = 0;

	for (int i = 0; i < n; i++) {

		if (a[i] == 0) {
			//BB check hoga and agar negative hain to min possible non negative banaya
			//jayega in order to check if answer exists or not.

			if (BB < 0) {
				BB = 0;
			}
		} else {

			BB += a[i];

			if (BB > d) {
				//Answer doesn't exit and print -1.
				cout << -1 << endl;
				return ;
			}
		}
	}



	//If YOu are standing at line number 39 that means your answer exists.
	//I want ki ith day par maximum amount of bank balance should be there.


	BB = 0;
	int visits = 0;

	for (int i = 0; i < n; i++) {

		if (a[i] == 0) {
			if (BB < 0) {
				BB = d;
				visits++;
			}

		} else {

			BB += a[i];

			if (BB > d) {
				BB = d;
			}
		}
	}




	cout << visits << endl;
	return;
}

int main() {

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	Solve();

}