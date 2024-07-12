#include<iostream>
#include<chrono>
using namespace std;
const int N = 0;

int main() {
	int n;
	// cin >> n;
	scanf("%d", &n);

	cout << n << endl;
	cerr << "Time Taken : " << (float)clock() / CLOCKS_PER_SEC << " secs     ";
}