#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N];


//Solve(s,e): Sort Array from s to e index.
int Partion(int s, int e) {

	int i = s - 1;//i represents the last index of the portion containing all the smaller element than pivot.
	int j = s;//j represents a element in the larger element portion.


	int pivot = a[e];
	//e is the pivot index and we want to find the correct pivot index from s to e-1.
	for (; j < e; j++) {

		if (a[j] <= pivot) {
			i++;
			swap(a[i], a[j]);
		}

	}

	//After the above loop end my i should be pointing to the last smaller element index compared to the
	//pivot element and since we want to put the pivot element to its correct position we will swap
	//the next element to i with the pivot element.


	swap(a[i + 1], a[e]);


	return i + 1;

}




void Solve(int s, int e) {

	if (s >= e) {
		return;
	}


	//Task:

	int Pivot_Index = Partion(s, e);
	//Correct Index of the Pivot and It Also puts the pivot to its correct postion.


	Solve(s, Pivot_Index - 1);

	Solve(Pivot_Index + 1, e);

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



//Randomised Quick Sort.