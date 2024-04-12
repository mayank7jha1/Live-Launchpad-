#include<bits/stdc++.h>
using namespace std;
const int N = 1e8;

int n;
int target;
int a[N];//Static Arrays.


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


int main() {

	cin >> n >> target;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << Binary_Search() << endl;

	//reverse(a, a + n);

	//cout << Binary_Search2() << endl;

	cout << binary_search(a, a + n, target) << endl;//Asc. Order

}