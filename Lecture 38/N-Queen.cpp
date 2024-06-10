#include<bits/stdc++.h>
using namespace std;
const int N = 0;


/*

	Solve(0): For Every i check if i can plan queen here or not
				if can then place and ask recursion                + Solve(1);


	Big Problem: Kya main 0 se lekar n-1 row tak queen rakh paaraha hu.
	Small Problem: kya main 1 se lekar n-1 row tak queen rakh paaya?


*/

bool CanPlace(char board[][100], int row, int col, int n) {

	//Current Row me Queen Nahi honi chahiye
	for (int i = 0; i < n; i++) {
		if (board[row][i] == 'Q') {
			return false;
		}
	}


	//Current Col me Queen me Queen nahi honi chahiye.
	for (int i = 0; i < n; i++) {
		if (board[i][col] == 'Q') {
			return false;
		}
	}

	//Diagonals:
	//Top Left Diagonal;

	int i = row, j = col;

	while (i >= 0 and j >= 0) {
		if (board[i][j] == 'Q') {
			return false;
		}
		i--;
		j--;
	}

	//Top Right Diagonal

	i = row, j = col;

	while (i >= 0 and j < n) {
		if (board[i][j] == 'Q') {
			return false;
		}
		i--;
		j++;
	}

	return true;
}

int count = 0;
bool Solve(char board[][100], int row, int n) {


	//base Condition.
	if (row == n) {

		//Print the board:

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		// count++;

		return true;
		// return false;//If False you print all the ways.
	}



	for (int col = 0; col < n; col++) {

		//This Current Col is a Potential place to put queen, can i Put queen
		//here i have to check.

		if (CanPlace(board, row, col, n) == 1) {

			board[row][col] = 'Q';

			bool SmallProblem = Solve(board, row + 1, n);

			if (SmallProblem == 1) {
				return true;
			}

			//That means jo ye current column jo potential queen place tha
			//isse answer nahi mila and hence main isko vapas se dot bana
			// dunga

			board[row][col] = '.';
		}

	}

	//Backtracking
	return false;


}

/*
	I am Taking a board as input where every box is a '.' char . and
	whenever i Will place queen i will put 'Q'.

*/



int main() {

}