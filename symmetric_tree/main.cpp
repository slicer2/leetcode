#include <iostream>
#include "dan.h"

using namespace std;

class Solution {
	bool isMirror(TreeNode *root1, TreeNode *root2) {
		if (!root1)
			if (!root2)
				return true;
			else
				return false;
		else
			if (!root2)
				return false;
			else
				return (root1->val == root2->val && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left));

	}

	public:
		bool isSymmetric(TreeNode *root) {
			if (!root)
				return true;
			else
				return isMirror(root->left, root->right);
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

	cout <<((sol.isSymmetric(root))? "yes":"no") << endl;

	return 0;
}
