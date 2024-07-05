#include<bits/stdc++.h>
using namespace std;
const int N = 0;


class node {
public:
	int data;
	node* left;
	node* right;

	node(int inputdata) {
		data = inputdata;
		left = NULL;
		right = NULL;
	}
};


//Input Format Type 1: Preorder / NULL
node* buildtree() {

	int x;
	cin >> x;

	if (x == -1) {
		return NULL;
	} else {

		node* n = new node(x);
		n->left = buildtree();
		n->right = buildtree();
		return n;
	}
}

void Preorder(node* root) {

	if (root == NULL) {
		return;
	}


	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(node* root) {

	if (root == NULL) {
		return;
	}

	Inorder(root->left);

	cout << root->data << " ";
	Inorder(root->right);
}


void Postorder(node* root) {

	if (root == NULL) {
		return;
	}

	Postorder(root->left);
	Postorder(root->right);

	cout << root->data << " ";
}

int CountNodes(node* root) {

	if (root == NULL) {
		return 0;
	}


	int Left_Subtree = CountNodes(root->left);
	int Right_Subtree = CountNodes(root->right);

	int ans = Left_Subtree + Right_Subtree + 1;
	return ans;

}

int Sum(node* root) {

	if (root == NULL) {
		return 0;
	}


	int Left_Subtree = Sum(root->left);
	int Right_Subtree = Sum(root->right);

	int ans = Left_Subtree + Right_Subtree + root->data;
	return ans;

}


//O(n)
int height(node* root) {

	if (root == NULL) {
		return 0;
	}

	int Left_Subtree_height = height(root->left);
	int Right_Subtree_height = height(root->right);

	int ans = max(Left_Subtree_height, Right_Subtree_height) + 1;
	return ans;
}

//Preorder:

void Mirror(node* root) {

	if (root == NULL) {
		return;
	}

	swap(root->left, root->right);
	Mirror(root->left);
	Mirror(root->right);
}


//Diameter in O(n^2):

int diameter(node* root) {

	if ( root == NULL) {
		return 0;
	}

	int Op1 = diameter(root->left);//Left Subtree ka Diameter
	int Op2 = diameter(root->right);//Right Subtree ka Diameter


	//Diameter Passes through the root node.
	int Op3 = height(root->left) + height(root->right);


	int ans = max({Op1, Op2, Op3});

	return ans;
}

class Pair1 {
public:
	int height;
	int diameter;

	Pair1() {
		height = 0;
		diameter = 0;
	}
};

Pair1 p;

//F(Current_node): Height of the current_node
//Store the states that that are repeating so that we don't have to calculate
//it again.
//I will Store current node height.
//dp[current_node]: Stores the value of height of current node.

Pair1 fastDiameter(node* root) {
	if (root == NULL) {
		p.diameter = 0;
		p.height = 0;
		return p;
	}


	Pair1 Left_Subtree = fastDiameter(root->left);
	Pair1 Right_Subtree = fastDiameter(root->right);

	p.height = max(Left_Subtree.height, Right_Subtree.height) + 1;

	int Op1 = Left_Subtree.diameter;//Left Subtree ka Diameter
	int Op2 = Right_Subtree.diameter;//Right Subtree ka Diameter


	int Op3 = (Left_Subtree.height + Right_Subtree.height);
	// int Op3 = dp[Left_Subtree.data] + dp[Right_Subtree.data];

	p.diameter = max({Op1, Op2, Op3});

	return p;
}



pair<int, int>p1;

/*
	first: Represented as Diameter
	second: Represented as Height
*/


pair<int, int>fastDiameter2(node* root) {

	if (root == NULL) {
		p1.first = 0;
		p1.second = 0;
		return p1;
	}

	pair<int, int>Left_Subtree = fastDiameter2(root->left);
	pair<int, int>Right_Subtree = fastDiameter2(root->right);

	p1.second = max(Left_Subtree.second, Right_Subtree.second) + 1;

	int Op1 = Left_Subtree.first;
	int Op2 = Right_Subtree.first;

	int Op3 = (Left_Subtree.second + Right_Subtree.second);


	p1.first = max({Op1, Op2, Op3});
	return p1;

}

class Pair2 {
public:
	int height;
	bool isbalanced;
};

Pair2 p3;

Pair2 IsHeightBalaced(node* root) {

	if (root == NULL) {
		p3.height = 0;
		p3.isbalanced = 1;
		return p3;
	}

	Pair2 Left_Subtree = IsHeightBalaced(root->left);
	Pair2 Right_Subtree = IsHeightBalaced(root->right);

	p3.height = max(Left_Subtree.height, Right_Subtree.height) + 1;

	if (Left_Subtree.isbalanced == 1 and Right_Subtree.isbalanced == 1 and
	        abs(Left_Subtree.height - Right_Subtree.height) <= 1) {

		p3.isbalanced = 1;
	} else {

		p3.isbalanced = 0;
	}

	return p3;

}


//O(n):
node* CreateHBT(int* a, int s, int e) {

	if (s > e) {
		return NULL;
	}

	int mid = (s + e) / 2;
	node* root = new node(a[mid]);
	root->left = CreateHBT(a, s, mid - 1);
	root->right = CreateHBT(a, mid + 1, e);

	return root;
}


void PrintLeftView(node* root, int level, int &mvl) {

	if (root == NULL) {
		return;
	}

	if (mvl < level) {
		cout << root->data << " ";
		mvl = level;
	}

	PrintLeftView(root->left, level + 1, mvl);
	PrintLeftView(root->right, level + 1, mvl);
}



void PrintRightView(node* root, int level, int &mvl) {

	if (root == NULL) {
		return;
	}

	if (mvl < level) {
		cout << root->data << " ";
		mvl = level;
	}

	PrintRightView(root->right, level + 1, mvl);
	PrintRightView(root->left, level + 1, mvl);

}


//O(n):
void PrintkthLevel(node* root, int k) {

	if (root == NULL) {
		return;
	}

	if (k == 1) {
		cout << root->data << " ";
		return;
	}

	PrintkthLevel(root->left, k - 1);
	PrintkthLevel(root->right, k - 1);

}

//Print Tree in Level Order : (BFS): Concept:
////O(n^2):
void PrintAllLevel(node* root) {


	int H = height(root);

	for (int i = 1; i <= H; i++) {
		PrintkthLevel(root, i);
		cout << endl;
	}
}

//BFS: O(n): Level Order Traversal.


int main() {

	//root node:
	node* root = buildtree();
	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;

	cout << CountNodes(root) << endl;
	cout << Sum(root) << endl;

	cout << diameter(root) << endl;

	cout << fastDiameter(root).height << " " << fastDiameter(root).diameter << endl;

	cout << IsHeightBalaced(root).height << " " << IsHeightBalaced(root).isbalanced << endl;

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	node* root2 = CreateHBT(a, 0, n - 1);
	Preorder(root2);
	cout << endl;
	int mvl = -1;
	PrintLeftView(root, 0, mvl);
	mvl = -1;
	cout << endl;
	PrintRightView(root, 0, mvl);
	cout << endl << endl << endl;

	PrintAllLevel(root);

}

