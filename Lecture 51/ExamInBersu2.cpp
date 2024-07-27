#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long

int n, m;
int t[N] {0};

int freq[101] {0};


void Solve() {

	int TTC = 0;//Total time consumed.

	for (int i = 0; i < n; i++) {

		int diff = TTC + t[i] - m;
		int Fail = 0;

		if (diff > 0) {
			for (int j = 100; j >= 1; j--) {

				if (freq[j] > 0) {

					int contribution = j * freq[j];

					if (contribution >= diff) {
						Fail += ((diff + j - 1 ) / j);
						break;
					}

					Fail += freq[j];
					diff -= contribution;
				}
			}
		}

		freq[t[i]]++;
		TTC += t[i];

		cout << Fail << " ";
	}
	return;
}

int32_t main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	Solve();
}



