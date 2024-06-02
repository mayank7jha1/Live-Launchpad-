#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {

	srand(time(0));

	// int x = 1 + rand() % 500;//Now numbers can repeat

	// cout << x << endl;
	// cout << x << endl;


	int n = 1 + rand() % 10;

	cout << n << endl;

	for (int i = 0; i < n; i++) {
		cout << 100 + rand() % 200 << " ";
	}
}


// rand(): Random Function Generator: (Seed);