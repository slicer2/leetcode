#include <iostream>
#include "dan.h"
#include <string>

using namespace std;


class Solution {
	public:
	int countUnivalue(TreeNode *root) {
		if (!root) return 0;

		int left = countUnivalue(root->left);
		int right = countUnivalue(root->right);

		if ((left > 0 && root->val != root->left->val) || (right > 0 && root->val != root->right->val))
			return left+right;
		else
			return left+right+1;
	}
};

int main() {
	string s;
	getline(cin, s);

	TreeNode *root = constructBinaryTree(s);

	Solution sol;
	cout << sol.countUnivalue(root) << endl;

	return 0;
}
