#include<bits/stdc++.h>
using namespace std;
const int N = 0;
#define int long long

int n, a, b, k, f;

bool cmp(int x, int y) {
	return x > y;
}

void Travel_Cards() {


	map<pair<string, string>, int>mp;
	/*
			map:

			key: pair of sp and ep of the trip.
			value: cost;


	*/

	string Previous = "";


	for (int i = 0; i < n; i++) {

		string SP, EP;
		cin >> SP >> EP;
		int Price = 0;

		if (Previous == SP) {
			//This is a Transhipment.

			Price = b;

		} else {

			Price = a;
		}
		Previous = EP;

		if (EP > SP) {
			swap(EP, SP);
		}

		mp[ {SP, EP}] += Price;
	}

	vector<int>cost;
	int TotalCost = 0;

	for (pair<pair<string, string>, int> x : mp) {
		cost.push_back(x.second);
		TotalCost += x.second;
	}

	// sort(cost.begin(), cost.end());
	// reverse(cost.begin(), cost.end());

	// sort(cost.begin(), cost.end(), cmp);

	// sort(cost.begin(), cost.end(), greater<int>());

	sort(cost.rbegin(), cost.rend());

	//I want to buy travel cards.

	for (int i = 0; i < k and i < cost.size(); i++) {

		if (cost[i] > f) {
			TotalCost = TotalCost - cost[i] + f;
		} else {
			break;
		}
	}

	cout << TotalCost << endl;
}



int32_t main() {
	cin >> n >> a >> b >> k >> f;

	Travel_Cards();
}

/*
	1. less<int>
	2. greater<int>
	3. less_equal<int>
	4. greater_equal<int>
*/