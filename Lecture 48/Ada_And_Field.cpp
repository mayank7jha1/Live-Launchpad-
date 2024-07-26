#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long



int32_t main() {
	int t;
	cin >> t;

	while (t--) {

		int n, m, q;
		cin >> n >> m >> q;

		multiset<int>x, y, sx, sy;

		sx.insert(n);
		sy.insert(m);

		x.insert(0);
		x.insert(n);

		y.insert(0);
		y.insert(m);

		for (int i = 0; i < q; i++) {

			int a, b;
			cin >> a >> b;

			if (a == 0) {
				//Vertical Line.

				if (x.find(b) != x.end()) {
					cout << (*(--sx.end()))*(*(--sy.end())) << endl;
					continue;
				}


				//Mujhe sx me se jin do x co-ordinate ke bich me line marni hain
				//uski length ko sx me se remove karo and do new length daalni hain
				//sx me.

				//How do I find ki correct kin do co -ordinates ke bich me
				//meri current division hogi?

				//Lower and Upper ka use karo.

				//if we have to apply division on b so just smaller
				//co-ordinate than b in x would be lower_bound of b in x
				//minus minus.
				auto small = x.lower_bound(b);
				small--;

				//Now mera small is pointing/ having the address of the block
				//which is just smaller the b.


				auto larger = x.upper_bound(b);

				//Now mera larger is pointing/ having the address of the block
				//which is just larger the b.

				int length = (*larger - *small);

				sx.erase(sx.find(length));

				sx.insert(*larger - b);
				sx.insert(b - *small);


				//Now you have to insert a new co-ordinate in x.

				x.insert(b);

				cout << (*(--sx.end()))*(*(--sy.end())) << endl;

				// sx.end(): Address of the last block + 1 .
				// Address of the last block
				// --sx.end()

				// value of the last block: *(--sx.end())



			} else {
				//Horizontal Line: a = 1
				if (y.find(b) != y.end()) {
					cout << (*(--sx.end()))*(*(--sy.end())) << endl;
					continue;
				}


				//Mujhe sx me se jin do x co-ordinate ke bich me line marni hain
				//uski length ko sx me se remove karo and do new length daalni hain
				//sx me.

				//How do I find ki correct kin do co -ordinates ke bich me
				//meri current division hogi?

				//Lower and Upper ka use karo.

				//if we have to apply division on b so just smaller
				//co-ordinate than b in x would be lower_bound of b in x
				//minus minus.
				auto small = y.lower_bound(b);
				small--;

				//Now mera small is pointing/ having the address of the block
				//which is just smaller the b.


				auto larger = y.upper_bound(b);

				//Now mera larger is pointing/ having the address of the block
				//which is just larger the b.

				int length = (*larger - *small);

				sy.erase(sy.find(length));

				sy.insert(*larger - b);
				sy.insert(b - *small);


				//Now you have to insert a new co-ordinate in x.

				y.insert(b);

				cout << (*(--sx.end()))*(*(--sy.end())) << endl;

				// sx.end(): Address of the last block + 1 .
				// Address of the last block
				// --sx.end()

				// value of the last block: *(--sx.end())
			}
		}
	}
}







