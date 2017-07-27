#include <iostream>
#include "dan.h"
#include <vector>
#include <string>

using namespace std;

string flatten(TreeNode *root){
	string s, nulls;

	queue<TreeNode *> q;

	if (root)
		q.push(root);

	while (!q.empty()) {
		TreeNode *p = q.front();
		q.pop();

		if (p) {
			q.push(p->left);
			q.push(p->right);
			s = s +  nulls + to_string(p->val) + " ";
			nulls = "";
		}
		else
			nulls = nulls + "# ";
	}

	if (s[s.length()-1] == ' ') s = s.substr(0, s.length()-1);
	return s;
}


int main() {
	string s;

	getline(cin, s);

	TreeNode *root = constructBinaryTree(s);

	preorder(root);

	cout << endl;

	cout << flatten(root) << endl;

	return 0;
}
