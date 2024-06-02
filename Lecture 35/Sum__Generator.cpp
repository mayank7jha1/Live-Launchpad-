#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	srand(time(0));
	int n = 1 + rand() % 10;

	cout << n << endl;

	for (int i = 0; i < n; i++) {
		cout << 1 + rand() % 10 << " ";
	}
}