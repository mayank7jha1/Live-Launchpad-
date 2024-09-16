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


// void Solve(TreeNode* root, unordered_map<int, int>&ump, int column) {

// 	if (root == NULL) {
// 		return;
// 	}

// 	ump[column] = root->val;

// 	Solve(root->left, ump, column - 1);
// 	Solve(root->right, ump, column + 1);
// }


/*
	What does Map do here?:
	It Sorts the data on the basis of column or it prints the
	data left to right.

	vector: Since a single column can now have multiple values/nodes
	we need to store it inside a vector.


*/

/*
	This map<column,vector<node->val>>mp by defaults brings the data in column wise
	sorted(Meaning least value column data is printed first not the values of the
	column are sorted)as well as level wise sorted.

	This is happening because you are following preorder and going from top to bottom.
*/
// void Solve2(TreeNode* root, map<int, vector<int>>&ump, int column) {

// 	if (root == NULL) {
// 		return;
// 	}

// 	ump[column].push_back(root->val);

// 	Solve2(root->left, ump, column - 1);
// 	Solve2(root->right, ump, column + 1);
// }

// vector<int>VerticalView(TreeNode* root) {

// 	vector<int>ans;

// 	if (root == NULL) {
// 		return ans;
// 	}

// 	//Unordered_Map<Column,All the Node->val>ump;

// 	//unordered_map<int, int>ump;
// 	map<int, vector<int>>ump; //Sort Karta hain on the basis of Column.

// 	Solve2(root, ump, 0);

// 	for (pair<int, vector<int>>x : ump) {

// 		for (int y : x.second) {
// 			ans.push_back(y);
// 		}
// 	}
// 	return ans;
// }

// void Solve3(TreeNode* root, multimap<int, int>&ump, int column) {

// 	if (root == NULL) {
// 		return;
// 	}

// 	ump.insert({column, root->val});

// 	Solve3(root->left, ump, column - 1);
// 	Solve3(root->right, ump, column + 1);
// }

// vector<int>VerticalView2(TreeNode* root) {

// 	vector<int>ans;

// 	if (root == NULL) {
// 		return ans;
// 	}

// 	//Unordered_Map<Column,All the Node->val>ump;

// 	//unordered_map<int, int>ump;
// 	multimap<int, int>ump;

// 	Solve3(root, ump, 0);

// 	for (auto x : ump) {
// 		ans.push_back(x.second);
// 	}
// 	return ans;
// }




/*
	I want data to be sorted column wise and data in the current column should also be sorted.
	for this i am using map and multiset.


	//Why set: Because For the current column my data should be sorted.
	why multiset: because data can be dublicate.

*/


void Solve4(TreeNode* root, map<int, multiset<int>>&ump, int column) {

	if (root == NULL) {
		return;
	}

	// ump.insert({column, root->val});
	ump[column].insert(root->val);


	Solve4(root->left, ump, column - 1);
	Solve4(root->right, ump, column + 1);
}

vector<int>VerticalView3(TreeNode* root) {

	vector<int>ans;

	if (root == NULL) {
		return ans;
	}

	//Unordered_Map<Column,All the Node->val>ump;

	//unordered_map<int, int>ump;
	map<int, multiset<int>>ump;

	Solve4(root, ump, 0);

	for (auto x : ump) {
		for (auto y : x.second) {
			ans.push_back(y);
		}
	}
	return ans;
}


int main() {
	TreeNode*root = Buildtree();
	bfs2(root);

	// cout << "Vertical View of the Tree :" << endl;
	// vector<int>a = VerticalView(root);
	// for (auto x : a) {
	// 	cout << x << " ";
	// }

	// cout << endl << endl;

	// cout << "Vertical View 2 of the Tree :" << endl;
	// vector<int>a1 = VerticalView2(root);
	// for (auto x : a1) {
	// 	cout << x << " ";
	// }


	// cout << endl << endl;


	cout << "Vertical View 3 of the Tree :" << endl;
	vector<int>a2 = VerticalView3(root);
	for (auto x : a2) {
		cout << x << " ";
	}


	cout << endl << endl;

}



//Easy By level Order Traversal.

//Directly COlumn and Level Wise along with superimposed nodes ko sort kar sakte ho.