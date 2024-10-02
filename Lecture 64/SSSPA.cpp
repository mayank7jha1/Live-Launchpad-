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

	void bfs(T scr) {
		map<T, int>distance;
		for (auto x : mp) {
			distance[x.first] = INT_MAX;
		}

		queue<T>q;
		q.push(scr);
		distance[scr] = 0;

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			for (T child : mp[node]) {
				if (distance[child] == INT_MAX) {
					q.push(child);
					distance[child] = distance[node] + 1;
				}
			}
		}


		//I am Printing Out the distance of every node from scr node.
		//I am Iterating over the map/Adjacency List.

		for (pair<T, list<T>> x : mp) {
			cout << scr << " to " << x.first << " distance is : " << distance[x.first] << endl;
		}

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
	gr.bfs(1);
}