#include <iostream>
#include "dan.h"

using namespace std;

class Solution {
	public:
		bool isSameTree(TreeNode *p, TreeNode *q) {
			if (!p)
				if (!q)
					return true;
				else
					return false;
			else
				if (!q)
					return false;
				else
					return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
		}
};


int main() {
	TreeNode *root1, *root2;

	string s;

	getline(cin, s);

	cout << " s = " << s << endl;

	root1 = constructBinaryTree(s);

	preorder(root1);

	cout << endl;

	getline(cin, s);

	cout << " s = " << s << endl;

	root2 = constructBinaryTree(s);

	preorder(root2);

	cout << endl;

	Solution sol;

	cout <<((sol.isSameTree(root1, root2))? "yes":"no") << endl;

	return 0;
}
