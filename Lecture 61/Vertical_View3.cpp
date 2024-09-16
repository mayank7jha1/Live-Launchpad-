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
			of the Respective Column in Multimap.

	2. Implementation:
			We are Here Using a Mutimap Because there can be Multiple Column
			with the same values and Since We are using a Multimap, Data are
			sorted by Column wise and there is no issue with
			dealing with dubplicate values.

			Multimap<column,Node>mp

			Key(int) 		: 		Value(int)
			Column Number	: 		Value
			Same Column No  :       Different Value

		MultiMap is Used Because Keys are sorted. i.e. Data is Sorted Column Wise.


		Obsertion: Data is also sorted Level Wise. i.e. All the Nodes
				   at the same column the nodes at the lowest level will be
				   printed first.

		But How?

		Because By Default We are Going From Top to Bottom and Using Preorder Traversal.
		So By Default you are vising nodes in Sorted Manner Only.
*/

void Dfs(TreeNode* root, multimap<int, int>&ump, int column) {

	if (root == NULL) {
		return;
	}

	ump.insert({column, root->val});

	Dfs(root->left, ump, column - 1);
	Dfs(root->right, ump, column + 1);
}

vector<int>VVSortedByColumnNoAndLevel12(TreeNode* root) {

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
	vector<int>a1 = VVSortedByColumnNoAndLevel12(root);
	for (auto x : a1) {
		cout << x << " ";
	}
	cout << endl;
}
