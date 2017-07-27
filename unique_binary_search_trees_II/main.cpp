#include <iostream>
#include "dan.h"
#include <vector>
#include <string>

using namespace std;
class Solution {
	vector<TreeNode *> result;
	vector<vector<vector<TreeNode *> > > memoized;
	vector<TreeNode *> nullTree;

	vector<TreeNode *> generate(int start, int end) {
		vector<TreeNode *> res;

		for (int i=start; i<=end; i++) {
			vector<TreeNode *> leftTrees, rightTrees;

			if (i-1 < start)
				leftTrees = nullTree;
			else
				if (memoized[start-1][i-1-1].size() != 0)
					leftTrees = memoized[start-1][i-1-1];
				else
					leftTrees = generate(start, i-1);

			if (end < i+1)
				rightTrees = nullTree;
			else
				if (memoized[i+1-1][end-1].size() != 0)
					rightTrees = memoized[i+1-1][end-1];
				else
					rightTrees = generate(i+1, end);

			for (int j=0; j<(int)leftTrees.size(); j++)
				for (int k=0; k<(int)rightTrees.size(); k++) {
					TreeNode *root = new TreeNode(i);
					root->left = leftTrees[j];
					root->right = rightTrees[k];

					res.push_back(root);
				}
		}

		memoized[start-1][end-1] = res;
		return res;
	}

	public:
	vector<TreeNode *> generateTrees(int n) {

		if (n==0) {
			result.push_back(NULL);
			return result;
		}

		nullTree.push_back(NULL);


		vector<TreeNode *> value;
		vector<vector<TreeNode *> > row(n, value);
		for (int i=0; i<n; i++)
			memoized.push_back(row);

		return generate(1, n);
	}
};

int main() {
	int n;
	cin >> n;

	Solution sol;

	vector<TreeNode *> result = sol.generateTrees(n);

	for (auto &x: result) {
		string s = serializeBinaryTree(x);
		cout << s<< endl;
	}

	return 0;
}
