#include<iostream>
using  namespace std;

int n;
char output[15];


void Solve(int i, char Max_Character) {


	if (i == n) {
		output[i] = '\0';
		cout << output << endl;
		return;
	}



	for (char ch = 'a'; ch <= Max_Character; ch++) {

		output[i] = ch;

		if (ch == Max_Character) {

			Solve(i + 1, Max_Character + 1);

		} else {

			Solve(i + 1, Max_Character);
		}

	}


}



int main() {
	cin >> n;

	Solve(0, 'a');

}