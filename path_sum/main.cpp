#include <iostream>
#include "dan.h"

using namespace std;


class Solution {
	public:
		bool hasPathSum(TreeNode *root, int sum) {
			if (!root)
				return false;

			if (root->left && hasPathSum(root->left, sum-root->val))
				return true;

			if (root->right && hasPathSum(root->right, sum-root->val))
				return true;

			if (!root->left && !root->right && sum == root->val)
				return true;

			return false;
		}

};

int main() {
	TreeNode *root;
	int sum;

	string s;

	cin >> sum;

	getline(cin, s);
	
	cout << " s = " << s << endl;

	root = constructBinaryTree(s);

	preorder(root);

	cout << endl;

	Solution sol;

	cout << ( (sol.hasPathSum(root, sum))?"Yes":"No" ) << endl;
}
