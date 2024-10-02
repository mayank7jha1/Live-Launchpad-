
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

	void Dfs() {
		map<T, bool>visited;
		for (auto x : mp) {
			visited[x.first] = 0;
		}

		int count = 1;

		for (auto x : mp) {
			T node = x.first;
			list<T>nbr = x.second;

			if (visited[node] == 0) {
				cout << "Component No: " << count << " --> ";
				Dfs_helper(node, visited);
				count++;
				cout << endl;
			}
		}

		cout << "Total Components : " << count - 1 << endl;
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
	gr.Dfs();
}