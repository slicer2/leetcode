#include <iostream>
#include <string>
#include "dan.h"
#include <stack>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
	stack<TreeNode *> sta;
	TreeNode *p;

	public:
		BSTIterator(TreeNode *root) {
			TreeNode *p = root;

			while (p) {
				sta.push(p);
				p = p->left;
			}
		}

		/** @return whether we have a next smallest number */
		bool hasNext() {
			return (!sta.empty());
		}

		/** @return the next smallest number */
		int next() {
			TreeNode *p = sta.top();
			sta.pop();

			TreeNode *q = p->right;

			while (q) {
				sta.push(q);
				q = q->left;
			}

			return p->val;
		}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
	string s;
	getline(cin, s);

	TreeNode *root = constructBinaryTree(s);
	//preorder(root);

	BSTIterator i = BSTIterator(root);
	while (i.hasNext()) cout << i.next() << ' ';

	cout << endl;
	return 0;
}
