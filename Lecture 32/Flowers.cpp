#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//Flowers(n,k): Total ways to eat n flowers.

int Flowers(int n, int k) {


	if (n == 0) {
		return 1;
	}


	//Nth flower is red.
	int Op1 = Flowers(n - 1, k);//Total Ways to eat n-1 flowers.


	//Nth Flower is White
	int Op2 = 0;
	if (n - k >= 0) {
		Op2 = Flowers(n - k, k);//Total ways to eat n-k flowers.
	}


	int Total_Ways = Op1 + Op2;

	return Total_Ways;

}



int main() {
	int n, k;
	cin >> n >> k;

	cout << Flowers(n, k) << endl;
}