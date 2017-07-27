#include "dan.h"

using namespace std;


void minorder(TreeNode *root) {
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
				cout << root->val << " ";
				root = root->right;
			}
		}
		else {
			cout << root->val << " ";
			root = root->right;
		}
	}
	cout << endl;
}


int main() {
	string s;
	getline(cin, s);
	TreeNode *root = constructBinaryTree(s);

	minorder(root);

	return 0;
}
