#include <iostream>
#include "dan.h"
#include <stack>

using namespace std;

#define SHOW(x) ((x)?x->val:0)


class Solution {

	public:
		void recoverTree(TreeNode *root) {
			TreeNode *prev = NULL, *left = NULL, *right;
			while (root) {
				if (root->left) {
					TreeNode *h = root->left;
					while (h->right && h->right != root) h = h->right;
					if (!h->right) {
						h->right = root;
						root = root->left;
					}
					else {
						h->right = NULL;
						if (prev && root->val< prev->val){
							if (!left) left = prev;
							right = root;
						}
						prev = root;
						root = root->right;
					}
				}
				else {
					if (prev && root->val< prev->val){
						if (!left) left = prev;
						right = root;
					}
					prev = root;
					root = root->right;
				}
			}

			swap(left->val, right->val);
		}

};

int main() {
	TreeNode *root;

	string s;

	getline(cin, s);

	cout << " s = " << s << endl;

	root = constructBinaryTree(s);

	cout << "before: " << endl;
	inorder(root);

	cout << endl;

	Solution sol;

	sol.recoverTree(root);

	cout << "after: " << endl;
	inorder(root);

	cout << endl;
}
