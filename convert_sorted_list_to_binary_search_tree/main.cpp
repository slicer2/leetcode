#include <iostream>
#include "dan.h"
#include <cstdlib>
#include <string>

using namespace std;


string indent("");

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	TreeNode *balance(ListNode *head, ListNode * &next_head, int len){
		//cerr << //indent << "head->" << head->val << "  len = " << len << endl;
		//indent += "  ";

		TreeNode *root = NULL;
		ListNode *right_head= NULL;


		if (len == 1) {
			next_head = head->next;
			
			//indent = //indent.substr(0, //indent.length()-2);
			return new TreeNode(head->val);
		}

		TreeNode *left_root= balance(head, right_head, len/2);

		root = new TreeNode(right_head->val);
		root->left = left_root;
		right_head = right_head->next;

		if (len-len/2-1 > 0) {
			TreeNode *right_root = balance(right_head, next_head, len-len/2-1);
			root->right = right_root;
		}
		else
			next_head = right_head;
		

		//indent = //indent.substr(0, //indent.length()-2);
		return root;
	}

	public:
		TreeNode *sortedListToBST(ListNode *head) {
			if (!head)
				return NULL;

			int len = 0;

			ListNode *p = head;

			while (p) {
				len++;
				p = p->next;
			}

			ListNode *dummy;

			return balance(head, dummy, len);
		}
};

int main() {
	int n;
	ListNode *head = NULL;

	while (cin >> n) {
		ListNode *p = new ListNode(n);
		p->next = head;
		head = p;
	}


	Solution sol;
	
	TreeNode *root = sol.sortedListToBST(head);

	inorder(root);

	cout << endl;

	return 0;
}
