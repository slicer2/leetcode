#include <iostream>
#include <queue>
#include <utility>
#include <sstream>

using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x = 0) : val(x), left(NULL), right(NULL), next(NULL) {}
};


TreeLinkNode *constructBinaryTree(string &s) {
	queue<TreeLinkNode **> nodes;

	stringstream ss(s);

	TreeLinkNode *root = NULL;

	int val;

	nodes.push(&root);

	while ((ss>> val) && !nodes.empty()) {
		TreeLinkNode **p = nodes.front();
		nodes.pop();

		if (val>-1000) {
			*p = new TreeLinkNode(val);
			nodes.push(&( (*p)->left ));
			nodes.push(&( (*p)->right ));
		}
	}

	return root;
}

void preorder(TreeLinkNode *root){
	if (!root)
		return;

	cout << root->val << " " << ((root->next)?root->next->val:0) << endl;

	preorder(root->left);

	preorder(root->right);
}

class Solution {
	public:
		void connect(TreeLinkNode *root) {
			if (!root)
				return;

			queue<pair<TreeLinkNode *, int> > q;

			q.push(make_pair(root, 0));


			while (!q.empty()) {
				pair<TreeLinkNode *, int> curr = q.front();
				q.pop();

				if (!q.empty() && q.front().second == curr.second)
					curr.first->next = q.front().first;

				if (curr.first->left)
					q.push(make_pair(curr.first->left, curr.second+1));

				if (curr.first->right)
					q.push(make_pair(curr.first->right, curr.second+1));
			}
		}
};

int main() {
	TreeLinkNode *root;

	string s;

	getline(cin, s);

	cout << "s " << s << endl;

	root = constructBinaryTree(s);

	Solution sol;

	sol.connect(root);

	preorder(root);

	return 0;
}
