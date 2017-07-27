#include "dan.h"
#include <climits>
#include <unordered_map>

using namespace std;

string indent("");

class Solution {
	unordered_map<TreeNode *, int> mp;
	public:
		int maxPathSum(TreeNode *root) {
			int mleft=INT_MIN, mright=INT_MIN, fleft=INT_MIN, fright=INT_MIN;
			if (!root->left && !root->right) return root->val;
			if (root->left) {
				mleft = maxPathSum(root->left);
				fleft = maxRootPathSum(root->left);
			}
			if (root->right) {
				mright = maxPathSum(root->right);
				fright = maxRootPathSum(root->right);
			}

			int m = root->val + ( (fleft > 0)?fleft:0 ) + ( (fright > 0)?fright:0 );
			return max(m, max(mleft, mright));
		}

		int maxRootPathSum(TreeNode *root) {
			if (mp.find(root) != mp.end()) return mp[root];
			int fleft=INT_MIN, fright=INT_MIN;
			if (!root->left && !root->right) return root->val;
			if (root->left) fleft = maxRootPathSum(root->left);
			if (root->right) fright = maxRootPathSum(root->right);

			int m = max(fleft, fright);
			mp.insert(make_pair(root, (m>0)?root->val+m:root->val));
			return mp[root];
		}
};

int main() {
	TreeNode *root;

	string s;

	getline(cin, s);

	root = constructBinaryTree(s);

	Solution sol;

	cout << sol.maxPathSum(root) << endl;

	return 0;
}
