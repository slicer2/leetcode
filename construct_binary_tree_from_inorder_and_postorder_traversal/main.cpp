#include <iostream>
#include <vector>
#include "dan.h"
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
	public:
		TreeNode *build(vector<int> &inorder, int in_pos, int len, vector<int> &postorder, int post_pos) {
			if (inorder.size() == 0) return NULL;

			int value = postorder[post_pos + len - 1];

			//cerr << "value = " << value << endl;
			TreeNode *root = new TreeNode(value);

			int pos = in_pos;
			while (inorder[pos] != value) pos++;

			//cerr << "in_pos = " << in_pos 
			//	<< "  len = " << len
			//	<< "  pos = " << pos
			//	<< "  post_pos = " << post_pos << endl;

			if (pos-in_pos > 0)
				root->left = build(inorder, in_pos, pos-in_pos, postorder, post_pos);

			//if (value == 3) abort();
			if (len > pos-in_pos+1)
				root->right = build(inorder, pos+1, len-(pos-in_pos+1), postorder, post_pos+pos-in_pos);

			return root;

		}

		TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
			return build(inorder, 0, inorder.size(), postorder, 0);
		}
};


int main() {
	string s;
	int n;
	vector<int> inorder, postorder;
	
	getline(cin, s);

	stringstream ss(s);

	while (ss>>n)
		inorder.push_back(n);

	getline(cin, s);
	stringstream sss(s);

	while (sss>>n)
		postorder.push_back(n);

	cout << inorder << endl << postorder << endl;

	Solution sol;

	preorder(sol.buildTree(inorder, postorder));

	cout << endl;

	return 0;
}
