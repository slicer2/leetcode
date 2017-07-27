#include <iostream>
#include <string>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	vector<int> result;

	void inorder(TreeNode *root) {
		if (!root) return;

		inorder(root->left);

		result.push_back(root->val);

		inorder(root->right);

	}

	public:
	vector<int> inorderTraversal(TreeNode *root) {

		this->inorder(root);

		return result;
	}
};

int main() {
	string s;

	getline(cin, s);

	TreeNode *root = constructBinaryTree(s);

	Solution sol;

	cout << sol.inorderTraversal(root) << endl;

	return 0;
}
