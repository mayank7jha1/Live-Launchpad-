#include<bits/stdc++.h>
using namespace std;
const int N = 100001;

vector<int>gr[N];//Nodes can only be integers as we are representing them as indices in adjacency list.


void Bfs(int scr, int n, int &SCL) {

	vector<int>distance(n + 1, INT_MAX);//distance of current node from scr.

	queue<int>q;
	q.push(scr);
	distance[scr] = 0;

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		for (auto nbr : gr[node]) {

			if (distance[nbr] == INT_MAX) {
				//This is an unvisited node and hence
				//update its distance also put this node
				//in the queue.
				q.push(nbr);
				distance[nbr] = distance[node] + 1;

			} else if (distance[nbr] >= distance[node]) {

				//This is a Backedge and we have found a cycle.
				//Visited:(True)

				int Current_Cycle_Length = distance[nbr] + distance[node] + 1;
				SCL = min(SCL, Current_Cycle_Length);

			}
		}
	}


}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	int Shortest_Cycle_Length = n + 1;//Why n+1 ? Because a graph having n nodes cannot have a cycle of n+1 length.

	//I can iterate/go to every node like this because my graph only contains integer nodes and that too from 1 to n and hence i can represent them as i.

	for (int i = 1; i <= n; i++) {
		Bfs(i, n, Shortest_Cycle_Length);
	}

	if (Shortest_Cycle_Length == n + 1) {
		cout << "There is no Cycle is Graph" << endl;
	} else {
		cout << Shortest_Cycle_Length << endl;
	}



}