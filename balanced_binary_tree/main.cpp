#include <iostream>
#include "dan.h"
#include <cmath>

using namespace std;


class Solution {
	bool isbalanced(TreeNode *root, int &depth) {
		if (!root) {
			depth = 0;
			return true;
		}

		int left, right;

		if (isbalanced(root->left, left) && isbalanced(root->right, right) && abs(left-right) <= 1) {
			depth = (left>right)?left+1:right+1;
			return true;
		}
		else
			return false;
	}

	public:
		bool isBalanced(TreeNode *root) {
			int depth;

			if (!root)
				return true;
			
			return isbalanced(root, depth);
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

	cout << ( (sol.isBalanced(root))? "yes":"no" )<< endl;
}
