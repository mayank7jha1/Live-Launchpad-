#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
#define int long long
int Fact[N] {0};

//10^18: Log(n)
//O(n): 10^8

//Time Complexity: O(1)
//Addition Property of Modulo:
int Addition(int x, int y) {
	return (x + y) % P;
}


//Time Complexity: O(1)
//Subtraction Property of Modulo:
int Subtraction(int x, int y) {
	return ((x - y) % P + 1 * P) % P;
}


//Time Complexity: O(1)
//Subtraction Property of Modulo:
int Multiply(int x, int y) {
	return ((x % P) * (y % P) % P);
}


//Iterative Way:
//Time Complexity: O(log(y))
//(x^y)%P

int FastPower(int x, int y) {
	int result = 1;
	while (y > 0) {

		if (y % 2 == 1) {
			result = Multiply(x, result);
		}
		y /= 2;
		x = Multiply(x, x);
	}
	return result;
}


//(x/y)%P

/*
	Inverse of y w.r.t to P:

	(y^-1)%P:

	According to FLT: (y^P-2)%P
*/

// O(log(y)):
int Inverse(int y) {
	return FastPower(y, P - 2);
}

// O(log(y)): Based on Fermat's Little Theoram.
int Division(int x, int y) {
	return (Multiply(x, Inverse(y)));
}


//O(n): Large Factorial:

void Calculate_Factorial() {
	Fact[0] = 1;
	for (int i = 1; i < N; i++) {
		Fact[i] = Multiply(Fact[i - 1], i);
	}
}

/*
	// ncr = (n! / (r!*(n - r)!));

	//ncr=((n!*(r^-1!)*((n-r)^-1)!)

	// int t = Multiply(Fact[n], Inverse[Fact[r]]);
	// return Multiply(t, Inverse(Fact[n - r]));

*/

//O(Log(n))
int ncr(int n, int r) {
	return Multiply(Multiply(Fact[n], Inverse[Fact[r]]), Inverse(Fact[n - r]));
}


//nPr: Homework.



int32_t main() {
	cout << FastPower(3, 5) << endl;
}

//FLT: a^P is congruent to a (mod P)