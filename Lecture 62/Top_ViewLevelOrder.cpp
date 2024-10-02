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

vector<int>TopViewLevel(TreeNode* root) {


	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	map<int, int>mp;
	queue<pair<TreeNode*, int>>q;

	q.push({root, 0});

	while (!q.empty()) {

		pair<TreeNode*, int>p = q.front();
		q.pop();

		TreeNode* node = p.first;
		int Column_No = p.second;

		if (mp.count(Column_No) == 0) {
			mp[Column_No] = node->val;
		}

		if (node->left != NULL) {
			q.push({node->left, Column_No - 1});
		}

		if (node->right != NULL) {
			q.push({node->right, Column_No + 1});
		}
	}


	for (pair<int, int>p1 : mp) {
		ans.push_back(p1.second);
	}

	return ans;
}

int main() {
	TreeNode*root = Buildtree();
	bfs2(root);

	cout << "Top View of the Tree :" << endl;
	vector<int>a = TopViewLevel(root);
	for (auto x : a) {
		cout << x << " ";
	}

}