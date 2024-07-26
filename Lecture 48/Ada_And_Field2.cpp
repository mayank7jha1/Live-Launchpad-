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

				if (x.find(b) != x.end()) {
					cout << (*(--sx.end()))*(*(--sy.end())) << endl;
					continue;
				}

				auto small = x.lower_bound(b);
				small--;

				auto larger = x.upper_bound(b);
				int length = (*larger - *small);

				sx.erase(sx.find(length));
				sx.insert(*larger - b);
				sx.insert(b - *small);
				x.insert(b);

				cout << (*(--sx.end()))*(*(--sy.end())) << endl;

			} else {
				//Horizontal Line: a = 1
				if (y.find(b) != y.end()) {
					cout << (*(--sx.end()))*(*(--sy.end())) << endl;
					continue;
				}

				auto small = y.lower_bound(b);
				small--;
				auto larger = y.upper_bound(b);

				int length = (*larger - *small);

				sy.erase(sy.find(length));
				sy.insert(*larger - b);
				sy.insert(b - *small);
				y.insert(b);

				cout << (*(--sx.end()))*(*(--sy.end())) << endl;
			}
		}
	}
}