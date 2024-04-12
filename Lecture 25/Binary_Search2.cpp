#include<bits/stdc++.h>
using namespace std;
const int N = 1e8;

int n;
int target;
int a[N];


bool Binary_Search() {

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		int mid = (s + e) / 2;

		if (a[mid] == target) {
			return true;
		} else if (a[mid] > target) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return false;
}


bool Binary_Search2() {

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		int mid = (s + e) / 2;

		if (a[mid] == target) {
			return true;
		} else if (a[mid] < target) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return false;
}

int Lower_Bound() {

	int s = 0;
	int e = n - 1;
	int ans = n;//This is the Index that can never become my answer.


	while (s <= e) {

		int mid = (s + e) / 2;

		if (a[mid] >= target) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	return ans;
}


int Upper_Bound() {

	int s = 0;
	int e = n - 1;
	int ans = n;//This is the Index that can never become my answer.


	while (s <= e) {

		int mid = (s + e) / 2;

		if (a[mid] > target) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	return ans;
}



int main() {

	cin >> n >> target;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << Binary_Search() << endl;
	cout << binary_search(a, a + n, target) << endl;


	cout << Lower_Bound() << endl;
	cout << lower_bound(a, a + n, target) - a << endl;


	cout << Upper_Bound() << endl;
	cout << upper_bound(a, a + n, target) - a << endl;


	//Frequency of 3 in Log(n) Computation:

	cout << upper_bound(a, a + n, target) - lower_bound(a, a + n, target) << endl;
}


//Hashing : O(n)*O(constant): O(n); (Average Case Scenerio) : Frequency Array/Unoredered_Map

// 99% : 1: O(nlogn)