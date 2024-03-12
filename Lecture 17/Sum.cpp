#include<bits/stdc++.h>
using namespace std;
const int N = 0;



//Solve(a,0,x): Sum of array from 0 index to x Index.

//Solve(a,1,x): Sum of Array from 1 index to x index.


//Solve(a,0,x)=a[0]+Solve(a,1,x);


//Sum of Array from 0 index to x index =  a[0]+ Sum of Array from 1 index to x index.

//Sum of Array from i index to x index = a[i] + Sum of Array from i+1 index to
//x index.

//Solve(a,i,x)=a[i]+Solve(a,i+1,x);


int Solve(int* a, int i, int x) {

	if (i == x) {

		//Solve(a,x,x): Sum of Array from x index to x index.
		//Answer to this is : a[x].
		return a[x];

	}

	int ans = a[i] + Solve(a, i + 1, x);

	return ans;
}

int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << Solve(a, 0, n - 1) << endl;
}