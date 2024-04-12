//C++ Reference : Algorithms
#include<iostream>
#include<algorithm>
#include<string>
#include<iterator>
using namespace std;

const int N = 0;

//Comparator can only return true/false.
//This is telling my algorithm that how we want the camparison between two elements while perfoming the current algorithm.


bool compare(int x, int y) {

	/*

		If your Function Returns true then you tell the algorithm that the
		current positioning of the elements is correct and you donot have to do
		anything.

	*/

	/*

		If your Function Returns false then you tell the algorithm that the
		current positioning of the elements is not correct and you  have to swap the elements (you tell this to the compiler).

	*/

	/*
		Since WE are sorting this array in descending order .
	*/

	if (x > y) {
		return true;
	} else {
		return false;
	}


}

bool compare2(int x, int y) {
	//return x < y;

	if (x < y) {
		return true;
	} else {
		return false;
	}
}


bool compare3(char x, char y) {
	//return x < y;

	if (x > y) {
		return true;
	} else {
		return false;
	}
}
int main() {

	/*
		1. Sort
		2. Reverse
		3. Binary Search

		//Pending and BS Ki Aplication Pending.
		4. Lower Bound
		5. Upper Bound


		//There are Some Algorithms which are container Specific.
		6. Find
		7. Count

	*/


	int a[] {11, 2, 13, 14, 5, 16, 7};//Direct List Initialistaion.
	int n = 7;
	/*
		You will always have to give atleast these things.
		You Have to Give the starting Address from where you want to perform the current
		algorithm.
		You will have to give (Ending Address + 1) till you want to perform the current
		algorithm.
	*/


	cout << *a << endl;
	cout << *(a + n - 1) << endl;


	//Sort this Array. O(nlogn): Tim Sort,Insertion Sort and Heap Sort
	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	//Comparators:

	//Now you want to sort this array in desc. order.

	sort(a, a + n, compare);

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}


	sort(a, a + n, compare2);

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	string st = "Mayank";

	sort(st.begin(), st.end());
	cout << st << endl;


	sort(st.begin(), st.end(), compare3);
	cout << st << endl;


	int a2[] {3, 1, 2, 3, 45, 6, 7};
	int n2 = 7;
	string st2 = "Samyak";

	reverse(a2, a2 + n2);

	// reverse(a2 + 1, a2 + 6);

	// [Starting Address,Ending Address)

	reverse(st2.begin(), st2.end());

	for (int i = 0; i < n2; i++) {
		cout << a2[i] << " ";
	}

	cout << endl << st2 << endl;

	int a3[] {1, 2, 3, 3, 3, 3, 3, 3, 9, 10};
	int n3 = 10;

	cout << binary_search(a3, a3 + 10, 9) << endl; //Log(n)


	//Upper_Bound and Lower_Bound:


	/*
		There are two aplication:

		You have to minimise/maximise a Range.
		You have to Solve a Mathematical Equation in a Sorted Search Space.

		Search Space Sorted. (Asc and Desc.)

		Lower_Bound and Upper_Bound in STL Return the address in case of
		DS and in Case of Containers they return iterator that means
		if you are using lower and upper bound on ds like array you can print
		the address very easily just by printing lower and upper bound but in case of container you will not be able to print the upper and lower
		bound directly as you cannot print the iterators.


	*/

	cout << (lower_bound(a3, a3 + n3, 3)) << endl;//Statement will/should not work in case of Containers.

	//NOw since I Want the Index of the first element that is greater than/ equal to x ??.

	int Index = lower_bound(a3, a3 + n3, 15) - a3;

	//Iterator Return : .end
	cout << Index << endl;


	int Index2 = upper_bound(a3, a3 + n3, 3) - a3;
	cout << Index2 << endl;


	cout << Index2 - Index << endl;






}



// M : ASCII : 77
// a : 97