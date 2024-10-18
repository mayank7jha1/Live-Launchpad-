#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class Graph {

	//Adj. List:
	/*

		This Implementation Only Works when the graph contains integer values.

		Node     :           Neighbour
		(Index)              {Nbr,Weight}


		array of vectors:
		vector<int>gr[10001];
	*/

	vector<pair<int, int>>*mp;
	int vertex;

public:

	Graph(int vertex) {
		this->vertex = vertex;
		mp = new vector<pair<int, int>>[vertex];
	}

	void AddEdge(int x, int y, int weight) {
		mp[x].push_back({y, weight});
		mp[y].push_back({x, weight});
	}

	int Prims() {

		//Min Heap: Weight,Vertex
		priority_queue<pair<int, int>, vector<pair<int, int>>,
		               greater<pair<int, int>>>pq;//Active Edge Set

		// priority_queue<int, vector<int>, greater<int>>pq;
		bool *visited = new bool[vertex] {0};//MST Set


		int Minimum_Weight = 0;
		pq.push({0, 1});

		while (!pq.empty()) {

			pair<int, int> x = pq.top();
			pq.pop();

			int To_Edge = x.second;
			int W = x.first;

			if (visited[To_Edge] == 1) {
				continue;
			}

			Minimum_Weight += W;
			visited[To_Edge] = 1;

			for (auto nbr : mp[To_Edge]) {

				if (!visited[nbr.first]) {
					pq.push({nbr.second, nbr.first});
				}
			}

		}
		return Minimum_Weight;
	}
};




int main() {

}