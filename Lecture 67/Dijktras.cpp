#include<bits/stdc++.h>
using namespace std;
const int N = 0;

template<typename T>
class Graph {
	unordered_map<T, list<pair<T, T>>>mp;
public:
	void addEdge(T x, T y, T w) {
		mp[x].push_back({y, w});
		mp[y].push_back({x, w});



		//Adj. List:

		/*
				Node    			:     Neighbour and Weight
				A                   :     {B,2},{C,5},{D,19}


		*/
	}

	void Dijktras(T scr) {

		unordered_map<T, int>distance;
		set<pair<T, T>>s;//Weight,Vertex

		for (auto x : mp) {
			distance[x.first] = INT_MAX;
		}

		distance[scr] = 0;
		s.insert({0, scr});

		while (!s.empty()) {

			pair<T, T> f = *(s.begin());
			s.erase(s.begin());

			T node = f.second;
			T Parent_weight = f.first;

			for (pair<T, T> nbr : mp[node]) {

				/*
					For Every Element of this map mp[node]:
					You are going to represent it as nbr:

					So Every element of mp[node] is what?

					pair<vertex,weight>

					pair<Vertex,Weight>nbr;
				*/
				T Edge_Weight = nbr.second;
				T child = nbr.first;

				if (distance[child] > Parent_weight + Edge_Weight) {

					//Yes You have found a smaller distance route.

					auto f = s.find({distance[child], child});
					if (f != s.end()) {
						s.erase(f);
					}

					distance[child] = Parent_weight + Edge_Weight;
					s.insert({distance[child], child});
				}
			}
		}

		//Print: Scr to destination: distance[destination]

	}
};

int main() {

}