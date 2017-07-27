#include <iostream>
#include "dan.h"

using namespace std;

class Solution {
	bool isValid(TreeNode *root, int &min, int &max) {
		bool valid;
		int t_min;

		if (root->left) {
			valid = isValid(root->left, min, max);

			if (!valid)
				return false;

			if (root->val <= max)
				return false;

			t_min = min;
		}
		else {
			t_min = root->val;
		}

		if (root->right) {
			valid = isValid(root->right, min, max);

			if (!valid)
				return false;

			if (root->val >= min)
				return false;
		}
		else
			max = root->val;

		min = t_min;

		return true;
	}

	public:
	bool isValidBST(TreeNode *root) {
		if (!root)
			return true;


		int min, max;

		return isValid(root, min, max);
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

	cout <<((sol.isValidBST(root))? "yes":"no") << endl;

	return 0;
}
