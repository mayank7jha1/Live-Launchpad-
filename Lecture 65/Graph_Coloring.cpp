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


	bool Dfs_helper(T node, T parent, map<T, int>&visited, int color) {
		visited[node] = color;

		/*
			Big Problem : Check graph is Bipartite or not from the current node. (color is represented as color.)

			Ek bar kaam maine kiya baaki recursion ne.

			I am Standing at the current node named as node.
			I will check if the current node(node) ka neighbour is visited or
			not.

			If it is not visited I will ask recursion to check the graph is bipartite
			or not from the neighbour node.


			Check Graph is Bipartite or node from current node = Current node ko color assign karo and ask recursion from the current node ke unvisited neighbour se ki kya vo bipartite hain.


		*/

		for (auto nbr : mp[node]) {

			if (visited[nbr] == 0) {
				bool Check = Dfs_helper(nbr, node, visited, 3 - color);
				if (Check == 0) {
					return false;
				}

			} else if (nbr != parent and visited[nbr] == color) {
				return false;
			}

		}
		return true;
	}

	bool Dfs(T scr) {
		map<T, int>visited;
		/*
			visited[node]=0 (unvisited Node)
			visited[node]=1 (Visited and with a color no 1.)
			visited[node]=2 (Visited and with a color no 2.)

		*/
		for (auto x : mp) {
			visited[x.first] = 0;
		}
		int color = 1;
		return Dfs_helper(scr, -1, visited, color);
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