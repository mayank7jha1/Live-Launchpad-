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
}