#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long
string a;
int nb, ns, nc;
int pb, ps, pc;
int r;

int sb = 0, ss = 0, sc = 0;


int Hamburger() {

	//First Task is to Calculate How many bread,sausage and cheese is required for making one hambuger.

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == 'B') {
			sb++;
		} else if (a[i] == 'S') {
			ss++;
		} else {
			sc++;
		}
	}

	//Step 1: Define the Search Space.

	int s = 0;
	int e = 1e13;

	int ans = -1;

	//Step 2: Search Within the SS.

	while (s <= e) {

		int mid = (s + e) / 2;

		int Total_Amount_Required_For_Bread = (((((mid * sb) - nb) * pb) < 0) ? 0 : (((mid * sb) - nb) * pb));

		int Total_Amount_Required_For_Sausage = 0;

		if ((((mid * ss) - ns) * ps) > 0) {
			Total_Amount_Required_For_Sausage = (((mid * ss) - ns) * ps);
		}

		int Total_Amount_Required_For_Cheese = (((((mid * sc) - nc) * pc) < 0) ? 0 : (((mid * sc) - nc) * pc));


		int Total_Price = Total_Amount_Required_For_Bread + Total_Amount_Required_For_Sausage + Total_Amount_Required_For_Cheese;


		if (r >= Total_Price) {
			s = mid + 1;
			ans = mid;
		} else {
			e = mid - 1;
		}
	}

	return ans;

}


int32_t main() {
	cin >> a;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;

	cout << Hamburger() << endl;
}