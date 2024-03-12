#include<bits/stdc++.h>
using namespace std;
const int N = 0;


//Search an element inside a array and Yes or not if found or not found.


//Task: Compare karne vaale ho bar bar key ko current array ke element ke sath.

//Task: Check if key is found in array from index 0 to n-1.

//Subtask: Check if key is found in array from index 1 to n-1.

//Solve(a,0,x): Check if Key is Found in array from 0 index to x index.

//Solve(a,1,x): Check if key is Found in Array from 1 index to x index.

//Kab ye baat sach hogi: Solve(a,0,x);

//Solve(a,0,x)=1 when (0----n-1)

//Kaam : Compare karo and check karo.

//Solve(a,0,x)= (a[0] ko compare karo key ke sath) ---> Solve(a,1,x).


//Solve(a,i,x)= kya a[i] key ke equal hain. : Agar nahi hain to recursion ko bolo ki aage jaake answer check kare.




bool Solve(int* a, int i, int x, int key) {

	if (i == x) {

		if (a[i] == key) {
			return true;
		} else {
			return false;
		}

	}


	if (a[i] == key) {
		return true;
	}

	bool ans = Solve(a, i + 1, x, key);
	return ans;


}


int main() {
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int key;
	cin >> key;

	cout << Solve(a, 0, n - 1, key) << endl;
}