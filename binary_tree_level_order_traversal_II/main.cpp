#include <iostream>
#include "dan.h"
#include <queue>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
	public:
		vector<vector<int> > levelOrderBottom(TreeNode *root) {
			vector<vector<int> > result;
			vector<int> row;
			int level = 0;

			if (!root) return result;

			queue<pair<TreeNode *, int> > q;

			q.push(make_pair(root, 0));

			while (!q.empty()) {
				pair<TreeNode *, int> p = q.front();
				q.pop();

				if (p.first->left) q.push(make_pair(p.first->left, p.second+1));
				if (p.first->right) q.push(make_pair(p.first->right, p.second+1));

				if (level == p.second) 
					row.push_back(p.first->val);
				else {
					result.push_back(row);
					row.clear();
					row.push_back(p.first->val);
					level++;
				}
			}
			
			result.push_back(row);

			vector<vector<int> > result2(result.size());
			copy(result.rbegin(), result.rend(), result2.begin());
			return result2;
		}
};

int main() {
	TreeNode *root;

	string s;

	getline(cin, s);

	cout << "s " << s << endl;

	root = constructBinaryTree(s);

	preorder(root);

	cout << endl;

	Solution sol;

	cout << sol.levelOrderBottom(root) << endl;
}
