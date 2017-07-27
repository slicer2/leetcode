#include <iostream>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int sumNumbers(TreeNode *root) {
			if (!root) return 0;
			int total = 0;
			sumNumbers(root ,0, total);
			return total;
		}

		void sumNumbers(TreeNode *root, int sum, int &total) {
			sum = 10*sum + root->val;
			if (root->left) sumNumbers(root->left, sum, total);
			if (root->right) sumNumbers(root->right, sum, total);
			if (!root->left && !root->right) total += sum;
		}
};

int main() {
	TreeNode *root;

	string s;

	getline(cin, s);

	cout << "s " << s << endl;

	root = constructBinaryTree(s);

	Solution sol;

	cout << sol.sumNumbers(root) << endl;

	return 0;
}
