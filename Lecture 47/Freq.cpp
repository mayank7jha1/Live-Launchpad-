#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {

	int a[] = {1, 2, 3, 4, 5, 1, 1, 1, 1, 1, 2, 2, 3, 4, 5, 5, 6, 7, 8, 8, 9, 8, 8, 9, 0, 7, 7, 0, 0, 2, 1, 1, 4, 5};
	int n = sizeof(a) / sizeof(int);


	map<int, int>mp;
	unordered_map<int, int>ump;


	for (int x : a) {
		mp[x]++;
		ump[x]++;
	}


	for (auto x : mp) {
		cout << x.first << " " << x.second << endl;
	}


	cout << endl << endl;

	for (auto x : ump) {
		cout << x.first << " " << x.second << endl;
	}

}