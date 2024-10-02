#include<bits/stdc++.h>
using namespace std;
const int N = 0;


template<typename T>

class Graph {
	map < T, list<T>>mp; //Adjacency List
public:

	void addEdge(T x, T y, bool direction) {
		mp[x].push_back(y);
		if (direction == 0) {
			mp[y].push_back(x);
		}
	}


	void Dfs_helper(T node, map<T, bool>&visited) {
		cout << node << " ";
		visited[node] = 1;

		for (auto nbr : mp[node]) {

			if (visited[nbr] == 0) {
				Dfs_helper(nbr, visited);
			}

		}
	}

	void Dfs(T scr) {
		map<T, bool>visited;

		// vector<bool>b;
		//Vector se Ki vector[node] par 0 pada hain ya 1 pada hain.

		for (auto x : mp) {
			visited[x.first] = 0;
		}

		//Start from here only.

		Dfs_helper(scr, visited);
		//dfs Lagana chahte ho:
		//We want to apply dfs on multiple nodes:
	}

	void Print() {
		for (pair<T, list<T>>x : mp) {
			T node = x.first;
			list<T>nbr = x.second;
			cout << node << " ---> ";
			for (int y : nbr) {
				cout << y << " ";
			}
			cout << endl;
		}
	}
};


int main() {
	int n, m, direction;
	cin >> n >> m >> direction;
	Graph<int>gr;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.addEdge(x, y, direction);
	}
	gr.Print();
	cout << endl;
	gr.Dfs(1);
}