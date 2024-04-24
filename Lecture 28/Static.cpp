#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int x = 10;

void Function(int n) {

	if (n == 0) {
		return;
	}

	static int x = 10;
	x += 1;

	int m = 20;
	m += 20;
	cout << "The Value of x is " << x << " The Value of m is " << m << endl;

	Function(n - 1);
}




int main() {

	Function(5);

	x += 30;

	cout << x << endl;
}