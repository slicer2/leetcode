#include <iostream>
#include "dan.h"

using namespace std;


class Solution {
	public:
		int maxDepth(TreeNode *root) {
			if (!root)
				return 0;

			int left = maxDepth(root->left);

			int right = maxDepth(root->right);

			if (left > right)
				return left+1;
			else
				return right+1;
		}

};

int main() {
	TreeNode *root;

	string s;

	getline(cin, s);

	cout << " s = " << s << endl;

	root = constructBinaryTree(s);

	preorder(root);

	cout << endl;

	Solution sol;

	cout <<sol.maxDepth(root)<< endl;

	return 0;
}
