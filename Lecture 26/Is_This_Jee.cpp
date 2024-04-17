#include<iostream>
#include<cmath>
#include<iomanip>
using  namespace std;
#define PI 3.14159265

//This Represents the F'(x) or the Derivative or the slope.

double Derivative(double x, double b, double c) {
	double value = ((sin(x) * (2 * x + b)) -
	                (cos(x) * (x * x + b * x + c)));

	return value;
}


double IsThisJee(double b, double c) {

	double s = 0;
	double e = PI / 2;

	double ans;


	// while (e - s > 1e6) {

	// }

	// log(n)

	//10^18 : 63 ~ 64
	//s=0
	//e=10^18

	// while (s <= e) {

	// }

	int count = 0;

	while (s <= e) {

		double mid = (s + e) / 2;// Potential x.

		double d = Derivative(mid, b, c);

		if (d < 0) {
			//Slope is Negative.
			s = mid;

			//Is this point a potential ans.
			ans = mid;


		} else {
			//Slope is Positive.
			e = mid;

			//Is this point a potential ans.
			ans = mid;
		}

		count++;
		if (count == 100) {
			break;
		}

	}

	//return Desired F(x) i.e Minimum F(x).

	// The Optimal x where you are able to
	//find the closed min valuee upto 10^-6 range
	//is stored in variable ans.

	return (((ans * ans) + (b * ans) + c) / sin(ans));

}



int main() {
	int t;
	cin >> t;

	int i = 1;
	while (t--) {

		double b, c;
		cin >> b >> c;
		cout << b << " " << c << endl;
		double ans = IsThisJee(b, c);
		cout << setprecision(10) << ans << endl;
	}
}


// setprecision(19)<<

// setw()?


