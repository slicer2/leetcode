#include "dan.h"

using namespace std;

class Solution {
	public:
		int countNodes(TreeNode* root) {
			if (!root) return 0;
			int depth = leftLevel(root);

			return (1<<(depth-1))-1 + getLastLevel(root, depth);
		}   

		int leftLevel(TreeNode *h) {
			if (!h) return 0;

			int n = 1;
			while (h->left) {
				h = h->left;
				n++;
			}   

			return n;
		}   

		int getLastLevel(TreeNode *h, int depth) {
			if (depth == 1) return 1;

			int lastLevel;                                                                                                                                                                            
			if (leftLevel(h->right)+1 == depth)
				lastLevel = (1 << (depth-2)) + getLastLevel(h->right, depth-1);
			else
				lastLevel = getLastLevel(h->left, depth-1);

			return lastLevel;
		}   
};

int main() {
	string s;
	getline(cin, s);
	TreeNode *root = constructBinaryTree(s);
	Solution sol;
	cout << sol.countNodes(root) << endl;
	return 0;
}
