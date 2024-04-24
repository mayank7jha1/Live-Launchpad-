#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int main() {
	//Static Arrays.
	int a[5] = {0};

	//Dynamic Arrays:

	int *b = new int[5] {1, 2, 3, 4};
	delete[]b;

	//Sizes of Dynamic Arrays Can be changed.
	b = new int[10] {0};


	for (int i = 0; i < 10; i++) {
		cout << b[i] << endl;
	}

}