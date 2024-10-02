
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

	/*
		Dfs_node : Check if there is a cycle in the graph fromt the
		current node.
	*/

	bool Dfs_helper(T node, map<T, bool>&visited, T Parent) {
		visited[node] = 1;

		for (auto nbr : mp[node]) {

			if (visited[nbr] == 0) {
				bool cycle = Dfs_helper(nbr, visited, node);
				if (cycle == 1) {
					return true;
				}
			} else if (nbr != Parent) {
				//This is a Backedge
				return true;
			}
		}

		return false;
	}

	bool Dfs(T scr) {
		map<T, bool>visited;
		for (auto x : mp) {
			visited[x.first] = 0;
		}
		return Dfs_helper(scr, visited, -1);
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
	cout << gr.Dfs(1) << endl;
}