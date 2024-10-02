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



vector<int>VVSortedByColumnNoLevelAndSameLevelValue(TreeNode* root) {

	//map<ColumnNo,map<Level,Node->Val>>>mp;
	//queue<pair<Node->Address,pair<ColumnNo,Level>>>q;

	map<int, map<int, multiset<int>>>mp;
	queue<pair<TreeNode*, pair<int, int>>>q;

	q.push({root, {0, 0}});

	while (!q.empty()) {

		// auto f = q.front();
		pair<TreeNode*, pair<int, int>> f = q.front();
		q.pop();

		TreeNode* node = f.first;
		int ColumnNo = f.second.first;
		int Level = f.second.second;


		mp[ColumnNo][Level].insert(node->val);

		if (node->left != NULL) {
			q.push({node->left, {ColumnNo - 1, Level + 1}});
		}

		if (node->right != NULL) {
			q.push({node->right, {ColumnNo + 1, Level + 1}});
		}
	}

	vector<int>ans;

	for (pair <int, map<int, multiset<int>>> x : mp) {
		for (pair<int, multiset<int>> y : x.second) {
			for (int z : y.second) {
				ans.push_back(z);
			}
		}
	}
	return ans;
}

int main() {
	TreeNode*root = Buildtree();
	bfs2(root);

	cout << "Vertical View of the Tree :" << endl;
	vector<int>a = VVSortedByColumnNoLevelAndSameLevelValue(root);
	for (auto x : a) {
		cout << x << " ";
	}
}