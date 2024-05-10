#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N];

void Merge(int s, int e) {
	int i = s;
	int mid = (s + e) / 2;
	int j = mid + 1;

	int temp[N];
	int k = s;//This represents index in the temp array.



	while (i <= mid and j <= e) {

		if (a[i] <= a[j]) {
			temp[k] = a[i];
			i++;
			k++;

		} else {

			temp[k] = a[j];
			k++;
			j++;

		}

	}

	/*
		Case 1: s=0, e=6;

		a[]={1,2,3,4,5,6,7};

		Portion 1: Left Half: 0 ---- 3 (index)

		1 2 3 4 : i=0;

		Portion 2: Right Half: 4 ---- 6 (index)

		5 6 7   j=4;

		int temp[]={X,X,X,X,X,X,X};
		int k=0;

		Merge by comparison.

		a[0] and a[4] : temp[0]=1;
		a[1] and a[4] : temp[1]=2;
		a[2] and a[4] : temp[2]=3;
		a[3] and a[4] : temp[3]=4;

		Now i is at 5.

		Jo bhi Bache hue element the as it is daal do temp array me.

		temp[4]=a[4]=5;
		temp[5]=a[5]=6;
		temp[6]=a[6]=7;

		Copy the temp array which is sorted into the original a array.


		Case 2: s=0, e=6

		int a[]={4,5,6,7,1,2,3};

		Portion 1: Left Half: 0 ----  (index)

		4 5 6 7 : i=0;

		Portion 2: Right Half: 4 ---- 6 (index)

		1 2 3   j=4;

		int temp[]={X,X,X,X,X,X,X};
		int k=0;

		Merge by comparison.
		a[0] and a[4]: temp[0]=a[4]=1
		a[0] and a[5]: temp[1]=a[5]=2
		a[0] and a[6]: temp[2]=a[5]=3

		j overflows that is j is equal to j=7.

		temp[4]=a[0];
		temp[5]=a[1]
		temp[6]=a[2];
		temp[7]=a[3];

		Copy the temp array which is sorted into the original a array.


	*/

	// Case 1:
	//What if i index reaches its end and j has not reached its end.
	while (j <= e) {
		temp[k] = a[j];
		k++;
		j++;
	}

	//Case 2:
	//What if j index reaches its end and i has not reached its end.
	while (i <= mid) {
		temp[k] = a[i];
		k++;
		i++;
	}


	//You now have your sorted temp array since the user wants it in a array.

	for (int i = s; i <= e; i++) {
		a[i] = temp[i];
	}


}

//Solve(s,e): Sorted Array from s to e index.

void Solve(int s, int e) {

	if (s >= e) {
		return;
	}

	//Divide and Merge.

	//Task First Part: Divide:

	int mid = (s + e) / 2;

	Solve(s, mid);//Sorted Array from s to mid index.
	Solve(mid + 1, e);//Sorted Array from mid+1 to e index.

	//Task Second Part: Merge

	Merge(s, e);

}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	Solve(0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}