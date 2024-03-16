#include<iostream>
using namespace std;

int n;
char output[100];

//Print All the Combination of brackets.

void Solve(int i, int open_count, int close_count) {

	if (i == 2 * n) {
		output[i] = '\0';
		cout << output << endl;
		return;

	}

	//Choosing Cloosing Bracket.
	if (close_count < open_count) {

		output[i] = ')';
		Solve(i + 1, open_count, close_count + 1);
	}


	//Choosing Opening Bracket.
	if (open_count < n) {
		output[i] = '(';
		Solve(i + 1, open_count + 1, close_count);
	}

}

int main() {

	cin >> n;

	Solve(0, 0, 0); //0,1,2,3
}





//n=2:


// _ _ _ _ i=4