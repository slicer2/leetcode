#include <iostream>
#include "dan.h"

using namespace std;

class Solution {
	public:
		TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
			bool flagp, flagq;
			return lowestCommonAncestor(root, p, q, flagp, flagq);
		}

		TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q, bool &flagp, bool &flagq) {
			if (!root) {
				flagp = false; 
				flagq = false;
				return NULL;
			}

			TreeNode *anc = lowestCommonAncestor(root->left, p, q, flagp, flagq);
			if (anc) return anc;
			bool fp, fq;
			anc = lowestCommonAncestor(root->right, p, q, fp, fq);
			if (anc) return anc;
			flagp = flagp || fp || (root == p);
			flagq = flagq || fq || (root == q);
			if (flagp && flagq) return root;
			else return NULL;
		}
};

int main() {
	string s;
	getline(cin, s);
	TreeNode *root = constructBinaryTree(s);
	Solution sol;
	TreeNode *p, *q;
	cout << sol.lowestCommonAncestor(root, p, q)->val << endl;
	return 0;
}
