#include<bits/stdc++.h>
#include"Hashmap.h"
using namespace std;
const int N = 0;

int main() {
	int n;
	cin >> n;
	Hashmap mp;

	for (int i = 0; i < n; i++) {
		string s; int x;
		cin >> s >> x;
		mp.insert(s, x);
	}

	mp.Print();
}