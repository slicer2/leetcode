#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x = 0):val(x), left(NULL), right(NULL) {}
};

TreeNode *constructBinaryTree(string &s) {
	queue<TreeNode **> nodes;

	stringstream ss(s);

	TreeNode *root = NULL;

	int val;

	nodes.push(&root);

	while ((ss>> val) && !nodes.empty()) {
		TreeNode **p = nodes.front();
		nodes.pop();

		if (val) {
			*p = new TreeNode(val);
			nodes.push(&( (*p)->left ));
			nodes.push(&( (*p)->right ));
		}
	}

	return root;
}

void preorder(TreeNode *root){
	if (!root)
		return;

	cout << root->val << " ";

	preorder(root->left);

	preorder(root->right);
}

int main() {
	TreeNode *root;

	string s;

	getline(cin, s);

	cout << "s " << s << endl;

	root = constructBinaryTree(s);

	preorder(root);

	cout << endl;
}
