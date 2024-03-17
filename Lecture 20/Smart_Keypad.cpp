#include<iostream>
using  namespace std;

char table[][10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
char input[15];
char output[15];

//table[3]=def
//table[3][1]=e


void Solve(int i, int j) {

	//Base Condition:
	if (input[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		return;
	}


	int Current_Digit = input[i] - '0';

	// Current_Digit = 49 - 48 = 1;
	// Current_Digit = 50 - 48 = 2;

	// F(0) = table[current_digit][k] + F(1);
	// k will go from 0 to table[current_digit] ka last index.


	for (int k = 0; table[Current_Digit][k] != '\0'; k++) {

		output[j] = table[Current_Digit][k];

		Solve(i + 1, j + 1);

	}

}

int main() {

	cin >> input;

	Solve(0, 0);

}



// table[character] :: ??? Kya index ek character hosakta hain?


// 123: Current_Digit Ko nikaloge kaise?















