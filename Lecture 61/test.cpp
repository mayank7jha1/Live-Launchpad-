#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	int n;
	cin >> n;

	map<string, int>mp;
	multimap<string, int>mmp;

	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;

		// pair<string, int>p = make_pair(s, x);
		// mp.insert(p);

		// mp.insert(make_pair(s, x));
		mp.insert({s, x});

		//Updation.
		//mp[s] = x;

		mmp.insert({s, x});

		//No Updation directly since we can have dubplicate keys.
	}


	for (auto x : mp) {
		cout << x.first << " " << x.second << endl;
	}

	cout << endl;

	for (auto x : mmp) {
		cout << x.first << " " << x.second << endl;
	}


	//Range: Function in Multimap to print all the data of the same keys.
}


// 10 1 3 16 -1 -1 11 -1 -1 9 -1 -1 13 2 -1 -1 6 -1 -1