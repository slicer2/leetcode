#include <iostream>
#include "dan.h"
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


string indent("");

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	TreeNode *balance(vector<int> &num, int start, int len){
		//cerr << indent << "start = " << start << "  len = " << len << endl;
		//indent += "  ";

		TreeNode *root = NULL;

		if (len == 1) {
			
			//indent = indent.substr(0, indent.length()-2);
			return new TreeNode(num[start]);
		}

		TreeNode *left_root= balance(num, start, len/2);

		root = new TreeNode(num[start+len/2]);
		root->left = left_root;

		if (len-len/2-1 > 0) {
			TreeNode *right_root = balance(num, start+len/2+1, len-len/2-1);
			root->right = right_root;
		}
		

		//indent = indent.substr(0, indent.length()-2);
		return root;
	}

	public:
		TreeNode *sortedArrayToBST(vector<int> &num) {
			if (num.empty())
				return NULL;

			return balance(num, 0, num.size());
		}
};

int main() {
	int n;
	vector<int> num;

	while (cin >> n) {
		num.push_back(n);
	}


	Solution sol;
	
	TreeNode *root = sol.sortedArrayToBST(num);

	inorder(root);

	cout << endl;

	return 0;
}
