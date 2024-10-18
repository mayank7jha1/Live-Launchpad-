#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class DSU {
	int *parent;
	int *rank;
	int components;

	DSU(int n) {
		parent = new int[n + 1];
		rank = new int[n + 1];
		components = n;
	}

	int find_set(int node) {
		if (parent[node] == -1) {
			return node;
		}

		//Path Compression:
		return parent[node] = find_set(parent[node]);
	}

	void Union_set(int node1, int node2) {

		int S1 = find_set(node1);
		int S2 = find_set(node2);

		if (S1 != S2) {
			//This means they belong in different and
			//hence we can union them.

			//Union By rank

			if (rank[S1] < rank[S2]) {
				parent[S1] = S2;
				rank[S2] += rank[S1];
			} else {
				parent[S2] = S1;
				rank[S1] += rank[S2];
			}
		}

		//else {
		// 	//By making this edge you are creating
		// 	//a cycle.
		// }

		components--;
	}
};

int main() {

}