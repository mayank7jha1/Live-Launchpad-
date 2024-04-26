#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n;
int grid[10][10] = {0};
int Total_Boxes_Where_Knight_Can_Travel = 0;
int ans = -1;

/*

ans: Maximum No of Boxes where the knight can travel in a single path across all paths;

count : No of boxes where the knight can travel in the current path;

	SP              EP
1. (0, 0)----->(dx[0], dy[0])
2. (0, 0)----->(dx[1], dy[1])
.
.
.
.
.
.
8. (0, 0)---- > (dx[7], dy[7])


1. (x, y)----->(x + dx[0], y + dy[0])
2. (x, y)----->(x + dx[1], y + dy[1])
.
.
.
.
.
.
8. (x, y)---- > (x + dx[7], y + dy[7])

*/
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

// and or && ||


void Knight(int x, int y, int count) {

	ans = max(ans, count);

	for (int i = 0; i < 8; i++) {

		int x_coordinate = x + dx[i];
		int y_coordinate = y + dy[i];

		if (x_coordinate >= 0 and y_coordinate >= 0 and x_coordinate < N and y_coordinate < N and grid[x_coordinate][y_coordinate] == 1) {

			grid[x_coordinate][y_coordinate] = 0;

			Knight(x_coordinate, y_coordinate, count + 1);


			//Backtracking:

			grid[x_coordinate][y_coordinate] = 1;

		}

	}

}


void Input_Grid() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				Total_Boxes_Where_Knight_Can_Travel++;
			}
		}
	}

}

int main() {
	cin >> n;
	Input_Grid();

	grid[0][0] = 0;
	//and count ko 1 se initialise karo.

	Knight(0, 0, 1);
	// cout << ans << endl;
	// cout << Total_Boxes_Where_Knight_Can_Travel << endl;

	cout << Total_Boxes_Where_Knight_Can_Travel - ans << endl;
}



//OA: Online Assessment: