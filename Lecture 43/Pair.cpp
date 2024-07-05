#include<bits/stdc++.h>
#include"Pair1.h"
#include<utility>
using namespace std;
// const int N = 0;


int main() {
	Pair1<string, int> p("Atul", 980);

	// p.first = 10;
	// p.second = 20;

	cout << p.first << " " << p.second << endl;

	Pair1<string, int>a[10];

	// //a[0]: variable of type Pair1.

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {

		string x;
		int y;
		cin >> x >> y;
		a[i].first = x;
		a[i].second = y;
	}

	for (int i = 0; i < n; i++) {
		cout << a[i].first << " " << a[i].second << endl;
	}


	// pair<string, int>a[10];
	// int n;
	// cin >> n;

	// for (int i = 0; i < n; i++) {

	// 	string x;
	// 	int y;
	// 	cin >> x >> y;
	// 	a[i].first = x;
	// 	a[i].second = y;
	// }


	// for (int i = 0; i < n; i++) {
	// 	cout << a[i].first << " " << a[i].second << endl;
	// }

	// <>

	string s;
	cout << s << endl;
	int x;
	cout << x << endl;

	pair<string, int>p3;
	cout << p3.second << endl;

}