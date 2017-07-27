#include <iostream>
#include <list>
#include "dan.h"

using namespace std;

class Solution {
	public:
		vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
			vector<vector<int>> res;
			list<TreeNode *> lst;

			if (!root) return res;
			lst.push_front(NULL);
			lst.push_front(root);

			int lvl = 0;
			while (lst.size() > 1) {
				vector<int> row;

				if (lvl++ % 2 == 0)
					while (lst.front()) {
						TreeNode *h = lst.front();
						lst.pop_front();
						if (h->left) lst.push_back(h->left);
						if (h->right) lst.push_back(h->right);
						row.push_back(h->val);
					}
				else
					while (lst.back()) {
						TreeNode *h = lst.back();
						lst.pop_back();
						if (h->right) lst.push_front(h->right);
						if (h->left) lst.push_front(h->left);
						row.push_back(h->val);
					}

				res.push_back(row);
			}
			return res;
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

	cout <<sol.zigzagLevelOrder(root)<< endl;

	return 0;
}
