#include <iostream>
#include <vector>
#include <string>
#include "dan.h"

using namespace std;

string indent("");

class Solution {
	vector<int> sentence;
	vector<vector<int> > sentences;
	void findPathSum(TreeNode *root, int sum) {
		//indent += "  ";
		//cerr << indent << "sentence = " << sentence << endl;
		if (!root)
			return;

		if (root->left || root->right) {
			sentence.push_back(root->val);

			//cerr << indent << root->val << endl;

			if (root->left)
				findPathSum(root->left, sum - root->val);

			if (root->right)
				findPathSum(root->right, sum - root->val);

			sentence.pop_back();
		}
		else {
			//cerr << indent << root->val;
			if (sum == root->val) {
				//cerr << "bingo";
				sentence.push_back(root->val);
				sentences.push_back(sentence);
				sentence.pop_back();
			}

			//cerr << endl;
		}

		//cerr << indent << "sentence = " << sentence << endl;
		//indent = indent.substr(0, indent.length()-2);
	}

	public:
		vector<vector<int> > pathSum(TreeNode *root, int sum) {
			findPathSum(root, sum);
			return sentences;
		}

};

int main() {
	TreeNode *root;
	int sum;

	string s;

	cin >> sum;

	getline(cin, s);
	
	cout << " s = " << s << endl;

	root = constructBinaryTree(s);

	preorder(root);

	cout << endl;

	Solution sol;

	cout << sol.pathSum(root, sum) << endl;
}
