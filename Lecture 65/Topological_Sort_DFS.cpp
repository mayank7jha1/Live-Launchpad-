#include<bits/stdc++.h>
using namespace std;
const int N = 0;


template<typename T>

class Graph {
	map < T, multiset<T>>mp; //Adjacency List : Will be same even if you change the order of the edges.
public:

	void addEdge(T x, T y) {
		// mp[x].push_back(y);
		mp[x].insert(y);
	}


	void Dfs_helper(T node, map<T, int>&visited, list<T>&ordering) {
		visited[node] = 1;

		for (auto nbr : mp[node]) {
			if (visited[nbr] == 0) {
				Dfs_helper(nbr, visited, ordering);
			}
		}

		ordering.push_front(node);
		return;
	}

	void Dfs() {
		map<T, int>visited;
		list<T>ordering;

		for (auto x : mp) {
			visited[x.first] = 0;
		}

		for (auto x : mp) {
			T node = x.first;
			if (!visited[node]) {
				Dfs_helper(node, visited, ordering);
			}
		}

		for (auto x : ordering) {
			cout << x << " ";
		}
	}

	void Print() {
		for (auto x : mp) {
			T node = x.first;
			auto nbr = x.second;
			cout << node << " ---> ";
			for (int y : nbr) {
				cout << y << " ";
			}
			cout << endl;
		}
	}
};


int main() {
	int n, m;
	cin >> n >> m;
	Graph<int>gr;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.addEdge(x, y);
	}
	gr.Print();
	cout << endl;
	gr.Dfs();
}


//Topological Sort (Scr node is not given)