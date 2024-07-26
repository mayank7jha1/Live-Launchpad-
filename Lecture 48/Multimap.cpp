#include<bits/stdc++.h>
using namespace std;
const int N = 0;




int main() {

	// map<pair<int, char>, int>mp;
	// map<pair<char, int>, int>mp1;

	multimap<char, int>mp2;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		char ch;
		cin >> ch >> x;
		// mp.insert({{i, ch}, x});
		// mp1.insert({{ch, i}, x});

		mp2.insert({ch, x});
	}

	// for (auto x : mp) {
	// 	// pair<pair<int, char>, int>p = x;
	// 	cout << x.first.first << " " << x.first.second << " " << x.second << endl;
	// }

	// cout << endl << endl << endl;

	// for (auto x : mp1) {
	// 	// pair<pair<int, char>, int>p = x;
	// 	cout << x.first.first << " " << x.second << endl;
	// }



	// cout << endl << endl << endl;

	for (auto x : mp2) {
		cout << x.first << " " << x.second << endl;
	}

	//find()
	//count()



	// if (mp.find({4, 'd'}) != mp.end()) {
	// 	cout << "YO" << endl;
	// } else {
	// 	cout << "NO" << endl;
	// }

	// cout << mp[ {4, 'd'}] << endl;

	// if (mp.count({4, 'd'}) == 1) {
	// 	cout << "YO" << endl;
	// } else {
	// 	cout << "NO" << endl;
	// }

	// if (mp2.find('d') != mp2.end()) {
	// 	cout << "TO Check" << endl;
	// } else {
	// 	cout << "NO" << endl;
	// }

	// if (mp2.count('d') == 1) {
	// 	cout << "TO Check" << endl;
	// } else {
	// 	cout << "NO" << endl;
	// }

	//Set ek sorted data ko store karta hain: Binary search me tum set ka instemal karte ho.

	//set has already lower bound and upper bound function hota hain.

	//Iterator hi laake deta hain.

	char key = 'a';
	auto range = mp2.equal_range(key);


	for (auto it = range.first; it != range.second; ++it) {
		std::cout << it->first << ": " << it->second << '\n';
	}



}