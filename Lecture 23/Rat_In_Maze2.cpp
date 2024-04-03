#include<bits/stdc++.h>
using namespace std;
const int N = 0;

bool Solution[1001][1001] = {{0}};
bool visited[1001][1001] = {{0}};
int n, m;
char maze[1001][1001];

bool RatInMaze(int x, int y) {

	if (x == n - 1 and y == m - 1) {

		Solution[x][y] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << Solution[i][j] << " ";
			}
			cout << endl;
		}

		return true;
	}



	if (visited[x][y] == 1) {
		return false;
	}


	Solution[x][y] = 1;
	visited[x][y] = 1;


	if (y + 1 <= m and visited[x][y + 1] == 0) {

		bool rightans = RatInMaze(x, y + 1);
		if (rightans == 1) {
			return true;
		}

	}


	if (x + 1 <= n and visited[x + 1][y] == 0) {
		bool downans = RatInMaze(x + 1, y);
		if (downans == 1) {
			return true;
		}
	}

	Solution[x][y] = 0;//Backtracking
	return false;

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];

			if (maze[i][j] == 'X') {
				visited[i][j] = 1;
			}

		}
	}

	bool ans = RatInMaze(0, 0);
	if (ans == 0) {
		cout << "-1" << endl;
	}
}