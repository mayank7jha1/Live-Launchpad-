#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//Solve(a,0,n-1): Check if Array is sorted from 0 to n-1.
//Solve(a,1,n-1): Check if Array is sorted from 1 to n-1.


bool Check(int* a, int index, int x) {

	if (index == x) {
		//Solve(a,x,x): CHeck if Array is sorted from x-x.
		return true;
	}

	int ans = ((a[index] < a[index + 1]) and Check(a, index + 1, x));

	return ans;

}



int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << Check(a, 0, n - 1) << endl;
}






// Check(a,0,4): Check if Array is Sorted from 0 index to 4 index.


//Check(a,0,4): (a[0]<a[1]) and Check(a,1,4);

//Check(a,index,x)=(a[x]<a[x+1]) and Check(a,index+1,x);


//Check(a,1,4): Check if Array is Sorted from 1 index to 4 index.

//Check(a,1,4): (a[1]<a[2]) and Check(a,2,4);

//Check(a,2,4): Check if Array is Sorted from 2 index to 4 index.



// ...........Check(a,4,4);

//Check(a,4,4): Check if Array is sorted from 4 index to 4 index.