#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int n, k;
int *taste, *calorie;

//Solve(0,0): Maximum Taste if you are choosing fruits from 0-n-1 index and
//maintaining sum as 0.

int Solve(int i, int Sum) {

	if (i == n) {
		if (Sum == 0) {
			//This is the path that you have to consider.
			return 0;
		} else {


			//This means sum is not equal to zero, ratio is not maintained.
			//I cannot consider this path in my answer.

			//How do I ensure this path answer i.e this path's total taste
			//can never become my answer.

			return -1e9;
		}
	}



	//Currently you are standing at the ith fruit and You have
	//two options either to choose the current fruit or not choose the
	//current fruit.

	//When You are Choosing the current fruit:

	int Op1 = taste[i] + Solve(i + 1, Sum + taste[i] - k * calorie[i]);


	//Op1 and Op2 are the taste of the current path.


	//When YOu are not choosing the fruit.
	int Op2 = 0 + Solve(i + 1, Sum);

	int ans = max(Op1, Op2);

	return ans;
}

int main() {
	cin >> n >> k;

	taste = new int[n];
	calorie = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	int ans = Solve(0, 0);

	if (ans < 0) {
		cout << "-1" << endl;
	} else {


		cout << ans << endl;
	}
}