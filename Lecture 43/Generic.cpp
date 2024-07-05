#include<bits/stdc++.h>
using namespace std;
const int N = 0;

/*
	Generic Programmin 2 ways:

	1. Default Arguments and Overloading.
	2. Templates:

	template<typename T>




*/


// int sum(int x, int y) {
// 	return x + y;
// }

// int sum(int x, int y, int z) {
// 	return x + y + z;
// }

int sum(int x, int y, int z = 0, int t = 0) {
	return x + y + z + t;
}

double sum3(double x, int y) {
	return x + y;
}



int main() {



	cout << sum(10, 15) << endl;
	cout << sum(10, 4, 71) << endl;
	cout << sum3(12.5, 3) << endl;
	cout << sum(4, 2, 1, 7) << endl;


}