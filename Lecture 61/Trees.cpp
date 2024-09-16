#include<bits/stdc++.h>
#include"Trees.h"
using namespace std;
const int N = 0;

int main() {
	node<int>*root = Buildtree();
	bfs(root);
	cout << endl;
	bfs2(root);
}