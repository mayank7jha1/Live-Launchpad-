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

	int Op1 = diameter(root->left);
	int Op2 = diameter(root->right);


	//Diameter Passes through the root node.
	int Op3 = height(root->left) + height(root->right);


	int ans = max({Op1, Op2, Op3});

	return ans;
}

//Right node Exist nahi kara:



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

	// buildtree(root);

}



