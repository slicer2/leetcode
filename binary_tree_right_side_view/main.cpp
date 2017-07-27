#include <iostream>
#include "dan.h"
#include <queue>

using namespace std;

class Solution {
	public:
		vector<int> rightSideView(TreeNode *root) {
			queue<pair<TreeNode *, int> > q;

			vector<int> result;

			if (!root)
				return result;

			q.push(make_pair(root, 0));

			while (!q.empty()) {
				pair<TreeNode *, int> p = q.front();
				q.pop();

				if (p.first->left)
					q.push(make_pair(p.first->left, p.second+1));

				if (p.first->right)
					q.push(make_pair(p.first->right, p.second+1));

				if (q.empty()) {
					result.push_back(p.first->val);
					break;
				}
				else {
					pair<TreeNode *, int> pp = q.front();
					if (pp.second > p.second)
						result.push_back(p.first->val);
				}
			}

			return result;
		}
};

int main() {
	string s;
	getline(cin, s);
	TreeNode *root = constructBinaryTree(s);

	preorder(root);

	Solution sol;
	cout << sol.rightSideView(root) << endl;


	return 0;
}
