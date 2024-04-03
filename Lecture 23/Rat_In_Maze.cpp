#include<bits/stdc++.h>
using namespace std;
const int N = 0;
/*
	Solution[x][y] = 1 Means this x, y is part of the path reaching to destination.
	visited[x][y]=1 Means you have already visited this x,y box and you don't need to revisit it again.
*/

bool Solution[1001][1001] = {{0}};
bool visited[1001][1001] = {{0}};
int n, m;
char maze[1001][1001];

bool RatInMaze(int x, int y) {


	if (x == n - 1 and y == m - 1) {

		/*
			THis means I have reached the desired box so I have to inform my parent recursion that i have found a solution and i also have to print the solution matrix.
		*/

		Solution[x][y] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << Solution[i][j] << " ";
			}
			cout << endl;
		}

		return true;
	}

	//Currently You are standing at box x,y and there are two ways to move.
	// i.e. you can either move to right i.e. x,y+1 or you can move down i.e. x+1,y.

	/*
		Steps :
		1. Whenever to go to any box: Check weather this is correct box or not
		that means the current box should not be a visited box.
		2. If the above condition satisfies that means you landed at a correct box now make this box part of you solution and also make this box as visited in order to never revisit this box.


	*/

	if (visited[x][y] == 1) {
		return false;
	}

	//Ek Bar main Kar chuka hu baaki kaam recursion karega.
	Solution[x][y] = 1;
	visited[x][y] = 1;

	//I will ask recursion you can go to its right, please go and if you find
	//a path then also tell me and if you don't find a path then also tell me.
	//and If you find a path please print the path up uptill solution.

	if (y + 1 <= m and visited[x][y + 1] == 0) {//Now I can go to right.

		bool rightans = RatInMaze(x, y + 1);
		if (rightans == 1) {
			return true;
		}

	}

	//Ab Main down jaane ki Koshish Karunga.

	if (x + 1 <= n and visited[x + 1][y] == 0) {
		bool downans = RatInMaze(x + 1, y);
		if (downans == 1) {
			return true;
		}
	}
	/*
		If you are standing here that means you tried to find a path to the right of
		x, y and if were not able to and similarly you tried to find a path to the down of x, y and you were not able to hence this box x, y can never be part of your solution and hence make this box 0 in the solution matrix.
	*/

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