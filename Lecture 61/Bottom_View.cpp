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


void Solve(TreeNode* root, unordered_map<int, int>&ump, int column) {

	if (root == NULL) {
		return;
	}

	ump[column] = root->val;

	Solve(root->left, ump, column - 1);
	Solve(root->right, ump, column + 1);
}

void Solve2(TreeNode* root, map<int, int>&ump, int column) {

	if (root == NULL) {
		return;
	}

	ump[column] = root->val;

	Solve2(root->left, ump, column - 1);
	Solve2(root->right, ump, column + 1);
}

vector<int>BottomView(TreeNode* root) {

	vector<int>ans;

	if (root == NULL) {
		return ans;
	}

	//Unordered_Map<Column,Node->val>ump;
	//unordered_map<int, int>ump;
	map<int, int>ump;//Sort Karta hain on the basis of Column.

	Solve2(root, ump, 0);

	for (auto x : ump) {
		ans.push_back(x.second);
	}
	return ans;
}

int main() {
	TreeNode*root = Buildtree();
	bfs2(root);

	cout << "Bottom View of the Tree :" << endl;
	vector<int>a = BottomView(root);
	for (auto x : a) {
		cout << x << " ";
	}

}