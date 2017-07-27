#include <iostream>
#include "dan.h"

using namespace std;


class Solution {
	public:
		int minDepth(TreeNode *root) {
			if (!root)
				return 0;

			if (!root->left && !root->right)
				return 1;

			int min_left, min_right;

			if (root->left) {
				min_left = minDepth(root->left);

				if (root->right) {
					min_right = minDepth(root->right);
					if (min_left < min_right)
						return min_left + 1;
					else 
						return min_right + 1;
				}
				else
					return min_left + 1;
			}
			else {
				min_right = minDepth(root->right);
				return min_right + 1;
			}
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

	cout <<sol.minDepth(root)<< endl;
}
