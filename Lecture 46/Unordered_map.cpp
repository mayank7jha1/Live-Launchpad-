#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {

	vector<int>v;
	pair<string, int>p;
	unordered_map<string, int>mp;

	p = make_pair("Mayank", 567);
	p = {"Samyak", 564};

	//cout << p.first << " " << p.second << endl;

	int n;
	cin >> n;


	for (int i = 0; i < n; i++) {

		string s;
		int x;
		cin >> s >> x;

		mp[s] = x;

		// p.first = s;
		// p.second = x;

		// mp.insert(p);
		// //mp.insert(make_pair(s, x));
		// mp.insert({s, x});

		// cin >> mp[i].first >> mp[i].second;
	}

	//By Default any key that is not present inside a map is initialised for the first time with value zero.
	//By Default Every key is initialised with value zero.

	//Iterator:

	//.begin()
	//.end()


	mp["Mayank"] = 786;

	cout << mp["Samyak"] << endl;

	for (unordered_map<string, int>::iterator x = mp.begin(); x != mp.end(); x++) {
		cout << (*x).first << " " << x->second << endl;
	}

	cout << endl << endl << endl;

	for (pair<string, int> x : mp) {
		cout << x.first << " " << x.second << endl;
	}
}