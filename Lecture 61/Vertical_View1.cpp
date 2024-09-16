#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class TreeNode {
public:

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int inputvalue) {
		val = inputvalue;
		left = NULL;
		right = NULL;
	}
};

TreeNode*Buildtree() {

	int x;
	cin >> x;

	if (x == -1) {
		return NULL;

	} else {

		//Node with the help of constructer
		TreeNode *r = new TreeNode(x);
		r->left = Buildtree();
		r->right = Buildtree();
		return r;
	}
}


void bfs2(TreeNode*root) {

	queue<TreeNode*>q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		TreeNode* f = q.front();

		if (f == NULL) {
			cout << endl;
			q.pop();

			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << f->val << " ";
			q.pop();

			if (f->left != NULL) {
				q.push(f->left);
			}

			if (f->right != NULL) {
				q.push(f->right);
			}
		}

	}
}

/*
	1. Idea:
			We are Going to Every Column and Storing all the Nodes
			of the Respective Column in a Vector.

	2. Implementation:
			We Can use Here unordered_map/map depending upon the situation.
			If we want to Print all the Nodes in Vertical order in Any
			Randon Order we can use a unordered_map but if we want to sort
			the data in terms of column value i.e. the all the values of the
			nodes in the leftest column should print first and So on.
			i.e. all the nodes in Vertical Order should be printed out in
			left to right column number.
			(Remember: We are saying column wise sorted that doesnot mean
			the values of nodes in the same column will also be sorted out).


			map<column,(All the nodes of the current column)>mp;

			Key(int) 		: 		Value(Vector<int>)
			Column Number	: 		All the Nodes of the Current Column Number.


		Map is Used Because Keys is sorted. i.e. Data is Sorted Column Wise.


		Obsertion: Data is also sorted Level Wise. i.e. All the Nodes
				   at the same column the nodes at the lowest level will be
				   printed first.

		But How?

		Because By Default We are Going From Top to Bottom and Using Preorder Traversal.
		So By Default you are vising nodes in Sorted Manner Only.
*/

void Dfs2(TreeNode* root, unordered_map<int, int>&ump, int column) {

	if (root == NULL) {
		return;
	}

	ump[column] = root->val;

	Dfs2(root->left, ump, column - 1);
	Dfs2(root->right, ump, column + 1);
}

void Dfs(TreeNode* root, map<int, vector<int>>&ump, int column) {

	if (root == NULL) {
		return;
	}

	ump[column].push_back(root->val);

	Dfs(root->left, ump, column - 1);
	Dfs(root->right, ump, column + 1);
}

vector<int>VVSortedByColumnNoAndLevel1(TreeNode* root) {

	vector<int>ans;

	if (root == NULL) {
		return ans;
	}

	//unordered_map<int, int>ump;
	map<int, vector<int>>ump;

	Dfs(root, ump, 0);

	for (pair<int, vector<int>>x : ump) {
		for (int y : x.second) {
			ans.push_back(y);
		}
	}
	return ans;
}

int main() {
	TreeNode*root = Buildtree();
	bfs2(root);

	cout << "Vertical View of the Tree :" << endl;
	vector<int>a1 = VVSortedByColumnNoAndLevel1(root);
	for (auto x : a1) {
		cout << x << " ";
	}
	cout << endl;
}
