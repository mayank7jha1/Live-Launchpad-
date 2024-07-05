#include<bits/stdc++.h>
using namespace std;
const int N = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

bool Valid_Position(int i, int j, vector<vector<char>>& grid) {
    if ((i < 0) or (j < 0) or (i >= n) or (j >= m)) {
        return false;
    }
    return true;
}

void dfs(int i, int j, vector<vector<char>>& grid) {
    grid[i][j] = '0';
    for (int k = 0; k < 4; k++) {
        int nexti = dx[k] + i;
        int nextj = dy[k] + j;
        if (!Valid_Position(nexti, nextj, grid)) {
            continue;
        }

        if (grid[nexti][nextj] == '1') {
            dfs(nexti, nextj, grid);
        }
    }
}

int Solve(vector<vector<char>>& grid) {

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                ans++;
                dfs(i, j, grid);
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;

    vector<vector<char>>grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << Solve(grid) << endl;
}