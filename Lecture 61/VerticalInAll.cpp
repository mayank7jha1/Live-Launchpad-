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


void Dfs3(TreeNode* root, map<int, multiset<int>>&ump, int column) {

	if (root == NULL) {
		return;
	}

	ump[column].insert(root->val);

	Dfs3(root->left, ump, column - 1);
	Dfs3(root->right, ump, column + 1);
}

vector<int>VVSortedByColumnNoAndColumnValue(TreeNode* root) {

	vector<int>ans;
	if (root == NULL) {
		return ans;
	}

	map<int, multiset<int>>ump;
	Dfs3(root, ump, 0);
	for (auto x : ump) {
		for (auto y : x.second) {
			ans.push_back(y);
		}
	}
	return ans;
}

void Dfs2(TreeNode* root, map<int, vector<int>>&ump, int column) {

	if (root == NULL) {
		return;
	}

	ump[column].push_back(root->val);

	Dfs2(root->left, ump, column - 1);
	Dfs2(root->right, ump, column + 1);
}

vector<int>VVSortedByColumnNoAndLevel12(TreeNode* root) {

	vector<int>ans;

	if (root == NULL) {
		return ans;
	}

	map<int, vector<int>>ump;
	Dfs2(root, ump, 0);

	for (pair<int, vector<int>>x : ump) {
		for (int y : x.second) {
			ans.push_back(y);
		}
	}
	return ans;
}

void Dfs(TreeNode* root, multimap<int, int>&ump, int column) {

	if (root == NULL) {
		return;
	}

	ump.insert({column, root->val});

	Dfs(root->left, ump, column - 1);
	Dfs(root->right, ump, column + 1);
}

vector<int>VVSortedByColumnNoAndLevel1(TreeNode* root) {

	vector<int>ans;

	if (root == NULL) {
		return ans;
	}

	multimap<int, int>ump;
	Dfs(root, ump, 0);
	for (auto x : ump) {
		ans.push_back(x.second);
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

	cout << "Vertical View of the Tree :" << endl;
	vector<int>a2 = VVSortedByColumnNoAndLevel12(root);
	for (auto x : a2) {
		cout << x << " ";
	}
	cout << endl;


	cout << "Vertical View of the Tree :" << endl;
	vector<int>a3 = VVSortedByColumnNoAndColumnValue(root);
	for (auto x : a3) {
		cout << x << " ";
	}
	cout << endl;
}




