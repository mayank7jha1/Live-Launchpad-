#include<bits/stdc++.h>
using namespace std;
const int N = 0;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<vector<int>>Final;
	vector<int>Current;

	void FinalPath(TreeNode* root, int sum) {

		if (root == NULL) {
			return;
		}


		Current.push_back(root->val);

		if (root->val == sum and root->left == NULL and root->right == NULL) {

			Final.push_back(Current);

		} else {

			FinalPath(root->left, sum - root->val);
			FinalPath(root->right, sum - root->val);
		}

		// 5 4 11 7

		Current.pop_back();//Backtracking.
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		FinalPath(root, targetSum);
		return Final;
	}
};

int main() {

}

//Leetcode par jo time aata hain that has nothing to do with time complexity
//ya alorithmic time.

//Leetcode ka time represents the server time that server takes to run your
//code.
//That means there are various factors on which this display of time
//depends.