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

	We need to sort the Data of the Tree on the basis of column first i.e whichever column
	is coming first we are printing the data of that column (left --> right)
	and along with that we are printing the data of the current column also in sorted manner
	manner i.e we are considering the levels but just print the data in sorted manner.

	For This:

	Map<column,multiset<node->val>>ump:

	(Value):
	(Node ki value can be duplicate hence multiset and has to be sorted)


	Key(Column)             :  Value
	-3						:  	16
	-2						:   3
	-1						:   1 11
	0 						:   (10,2,9): (2,9,10)
	1 						:   13
	2                       :   6



	ump[-3].insert(16);
	ump[-2].insert(3);
	ump[-1].insert(1);
	ump[-1].insert(11);
	ump[0].insert(9);
	ump[0].insert(10);
	ump[0].insert(2);
	ump[1].insert(13);
	ump[2].insert(6);

	If We had Used a Multimap: (Not Advised as it will not result in the desired result).

	Multimap me aap directly: mp[key] this is not allowed because dublicate values are there.

	Multimap me Current column ka data hain vo sorted nahi aayega.
	Key(Column)             :  Value
	-3						:  	16
	-2						:   3
	-1						:   1
	-1						:   11
	0 						:   10
	0 						:  	9
	0 						:   2
	1 						:   13
	2                       :   6


*/

void Dfs(TreeNode* root, map<int, multiset<int>>&ump, int column) {

	if (root == NULL) {
		return;
	}

	ump[column].insert(root->val);
	// Main data ko pehle ek multiset me daalu and then usko multimap me daalu.
	//multiset<int>s1;//Put all the data here and then put this multiset in multimap.
	//{}: This means group of elements.(This can be anything)

	ump.insert({column, {root->val}});
	Solve4(root->left, ump, column - 1);
	Solve4(root->right, ump, column + 1);
}

vector<int>VVSortedByColumnNoAndColumnValue(TreeNode* root) {

	vector<int>ans;

	if (root == NULL) {
		return ans;
	}

	map<int, multiset<int>>ump;
	Dfs(root, ump, 0);
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


	cout << "Vertical View of the Tree :" << endl;
	vector<int>a2 = VVSortedByColumnNoAndColumnValue(root);
	for (auto x : a2) {
		cout << x << " ";
	}
	cout << endl << endl;
}
