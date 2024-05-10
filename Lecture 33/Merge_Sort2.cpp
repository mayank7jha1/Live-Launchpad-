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

	while (j <= e) {
		temp[k] = a[j];
		k++;
		j++;
	}

	while (i <= mid) {
		temp[k] = a[i];
		k++;
		i++;
	}

	for (int i = s; i <= e; i++) {
		a[i] = temp[i];
	}


}



void Solve(int s, int e) {

	if (s >= e) {
		return;
	}

	int mid = (s + e) / 2;

	Solve(s, mid);
	Solve(mid + 1, e);

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