#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>

using namespace std;

string indent("");

template <typename T>
ostream & operator << (ostream &os, const vector<T> &vec) {
	for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
		os<< (*it) <<endl;

	return os;
}


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	class Stack {
		list<pair<TreeNode *, int> > sta;

		public:
		bool empty() { return (sta.size() == 0); }
		pair<TreeNode *, int> pop() {
			pair<TreeNode *, int> tnode = sta.back();
			sta.pop_back(); 
			return tnode;
		}
		void push(pair<TreeNode *, int> tnode) { sta.push_back(tnode); }
	};

	public:
	vector<int> postorderTraversal(TreeNode *root) {
		TreeNode *currNode = root;
		vector<int> post;
		Stack s;

		while (currNode) {
			s.push(make_pair(currNode, 0));
			currNode = currNode->left;
		}

		while (!s.empty()) {
			pair<TreeNode *, int> currPair = s.pop();

			if (currPair.second == 0) {
				s.push(make_pair(currPair.first, 1));
				currNode = currPair.first->right;

				while (currNode) {
					s.push(make_pair(currNode, 0));
					currNode = currNode->left;
				}
			}
			else {
				post.push_back(currPair.first->val);
			}
		}

		return post;
	}
};


TreeNode * constructTree(vector<int>in, int start_in, int end_in, vector<int> pre, int start_pre) {

	indent += "  ";

	//cerr<<indent<<"start_in = "<<start_in<<" end_in = "<<end_in<<" start_pre = "<<start_pre<<endl;
	// empty tree
	if (end_in - start_in <= 0) {
		indent = indent.substr(0, indent.size()-2);
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
	root->left = constructTree(in, start_in, pos, pre, start_pre+1);

	// right child (could be empty)
	//cerr<<indent<<"construct right"<<endl;
	root->right = constructTree(in, pos+1, end_in, pre, start_pre+pos-start_in+1);

	indent = indent.substr(0, indent.size()-2);
	return root;
}

int main()
{
	vector<int> in, pre, post;
	int x, y, n;
	cin >> n ;

	in.resize(n);
	pre.resize(n);
	post.resize(n);

	for (int i=0; i<n; i++) {
		cin >> in[i] >> pre[i] >> post[i];
	}

	//cerr<<"in:"<<endl<<in<<endl;
	//cerr<<"pre:"<<endl<<pre<<endl;
	//cerr<<"post:"<<endl<<post<<endl;

	TreeNode *root = constructTree(in, 0, n, pre, 0);

	Solution s;

	vector<int> post2 = s.postorderTraversal(root);

	//cerr<<( (post2 == post)?"Pass":"Fail" )<<endl;

	return 0;
}
