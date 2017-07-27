#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		void flatten(TreeNode *root) {
			if (!root) return;

			stack<TreeNode *> sta;

			TreeNode *curr = root;
			
			if (root->right)
				sta.push(root->right);

			if (root->left)
				sta.push(root->left);

			while (!sta.empty()) {
				TreeNode *p = sta.top();
				sta.pop();

				curr->left = NULL;
				curr->right = p;
				curr = curr->right;

				if (curr->right)
					sta.push(curr->right);

				if (curr->left)
					sta.push(curr->left);
			}
		}
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

void display(TreeNode *root) {
	while (root) {
		cout << root->val << ' ';
		root = root->right;
	}
}

int main() {
	string s;

	getline(cin, s);

	TreeNode *root = constructBinaryTree(s);

	preorder(root);

	cout << endl;

	Solution sol;

	sol.flatten(root);

	display(root);

	return 0;
}
