#include<bits/stdc++.h>
using namespace std;
const int N = 0;
int n;
int *a;
int *b;
int *c;

// 5 1 2 3 4 --->O(n)

void Bubble_Sort() {

	bool flag;
	int count = 0;
	for (int i = 0; i < n - 1; i++) {

		flag = 0;//Computation
		// count++;//I am Ignoring this Intialisation

		for (int j = 0; j < n - i - 1; j++) {

			count++;
			if (a[j] > a[j + 1]) {
				count++;
				swap(a[j], a[j + 1]);
				flag = 1;

			}
		}

		count++;
		if (flag == false) {//Computation??
			count++;
			break;
		}
	}

	cout << count << endl;
}


void Selection_Sort() {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (b[j] < b[min]) {
				min = j;
			}
		}
		swap(b[i], b[min]);
	}
}


void Insertion_Sort() {
	int i = 1;//Ignoring this
	int count = 0;
	while (i < n) {
		// count++;//Ignoring as Maine flag vaale me bhi maara tha
		int hpc = c[i];
		int j = i - 1;//Ignoring this.

		while (j >= 0) {
			count++;

			if (hpc < c[j]) {
				count++;
				c[j + 1] = c[j];
				j--;
			}
			else {
				break;
			}
		}
		// count++;//Ignoring this.
		c[j + 1] = hpc;
		i++;
	}

	cout << count << endl;

}

int main() {


	cin >> n;

	a = new int[n];
	b = new int[n];
	c = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}


	Bubble_Sort();
	// Selection_Sort();
	Insertion_Sort();

	//Bubble Sort
	// cout << "Bubble_Sort " << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }

	// cout << endl << endl << "Selection_Sort " << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << b[i] << " ";
	// }


	// cout << endl << endl << "Insertion_Sort " << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << c[i] << " ";
	// }
}