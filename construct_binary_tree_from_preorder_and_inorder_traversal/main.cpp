#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include "dan.h"

using namespace std;

string indent("");

class Solution{
	TreeNode * build(vector<int> &in, int start_in, int end_in, vector<int> &pre, int start_pre) {

		//indent += "  ";

		//cerr<<indent<<"start_in = "<<start_in<<" end_in = "<<end_in<<" start_pre = "<<start_pre<<endl;
		// empty tree
		if (end_in - start_in <= 0) {
			//indent = indent.substr(0, indent.size()-2);
			return NULL;
		}

		// at least one node in the tree, get root
		//cerr<<indent<<"root = "<<pre[start_pre]<<endl;
		TreeNode *root = new TreeNode(pre[start_pre]);


		int pos = start_in;
		while (in[pos] != pre[start_pre])
			pos++;

		// left child (could be empty)
		//cerr<<indent<<"construct left"<<endl;
		root->left = build(in, start_in, pos, pre, start_pre+1);

		// right child (could be empty)
		//cerr<<indent<<"construct right"<<endl;
		root->right = build(in, pos+1, end_in, pre, start_pre+pos-start_in+1);

		//indent = indent.substr(0, indent.size()-2);
		return root;
	}
	public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
		return build(inorder, 0, inorder.size(), preorder, 0);
	}
};

int main()
{
	vector<int> in, pre;
	int n;
	cin >> n ;

	in.resize(n);
	pre.resize(n);

	for (int i=0; i<n; i++) {
		cin >> pre[i] >> in[i];
	}

	Solution sol;

	TreeNode *root = sol.buildTree(pre, in);

	preorder(root);

	cout<<endl;

	return 0;
}
