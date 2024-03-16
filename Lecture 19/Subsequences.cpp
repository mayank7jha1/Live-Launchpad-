#include<iostream>
using namespace std;
// const int N = 0;

int count1 = 0;
char input[100];
char output[100];



void Solve(int i, int j) {

	if (input[i] == '\0') {
		count1++;
		output[j] = '\0';
		cout << output << endl;

		return;

	}

	//Choosing the Current Character.
	output[j] = input[i];
	Solve(i + 1, j + 1);


	//Not Choosing the Current Character.
	Solve(i + 1, j);

}

int main() {

	cin >> input;

	Solve(0, 0);

	cout << count1 << endl;
}



// i->i+1
// j->j+1


// i->i+1
// j->j;