#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "dan.h"

using namespace std;

class Solution {
	public:
	vector<vector<int>> verticalOrder(TreeNode *root) {
		if (!root) return vector<vector<int>>();

		vector<pair<int, int>> index;
		preorder(root, index, 0);

		sort(index.begin(), index.end(), indexsort);

		vector<vector<int> > res( {vector<int>({index[0].first})} );
		int sz = index.size();
		for (int i=1; i<sz; i++) {
			if (index[i].second != index[i-1].second)
				res.push_back(vector<int>( {index[i].first} ));
			else
				res.back().push_back(index[i].first);
		}


		return res;
	}

	private:
		static bool indexsort(const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.second < p2.second;
		}

		void preorder(TreeNode *root, vector<pair<int, int>> &index, int currpos) {
			if (!root) return;
			index.push_back(make_pair(root->val, currpos)); 
			preorder(root->left, index, currpos-1);
			preorder(root->right, index, currpos+1);
		}
};
int main() {
	string s;

	getline(cin, s);

	TreeNode *root = constructBinaryTree(s);


	Solution sol;
	cout << sol.verticalOrder(root) << endl;

	return 0;
}
