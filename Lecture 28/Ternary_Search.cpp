#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define PI 3.14159265
#define int long long

double Function(double x, double b, double c) {

	return (x * x + b * x + c) / sin(x);

}

double IsThisJee(double b, double c) {

	double s = 0;
	double e = PI / 2;

	while (e - s > 1e-6) {

		double m1 = s + (e - s) / 3.0;
		double m2 = e - (e - s) / 3.0;

		if (Function(m1, b, c) > Function(m2, b, c)) {

			s = m1;

		} else if (Function(m1, b, c) < Function(m2, b, c)) {

			e = m2;

		} else {

			s = m1, e = m2;
		}

	}

	return s;//x - Co -ordinate where the min value of function lies

}


// 2e7=2*10^7;



int32_t main() {
	int t;
	cin >> t;

	while (t--) {
		double b, c;
		cin >> b >> c;

		double ans = IsThisJee(b, c);

		cout << fixed << setprecision(8) << Function(ans, b, c) << endl;
	}
}



//Aggressive cows: Maximising/Minimising a range.

//https://www.spoj.com/problems/AGGRCOW/

//Book Allocation Problem: Maximising/Minimising a range.

// https://codeforces.com/problemset/problem/279/B
//Don't try to solve it using sliding window and two pointer approach.
//Try to solve it Using BS.
//Hint : Think Prefix Sum and Lower/Upper Bound Concept.


