#include "dan.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* reverseList(ListNode* head) {
			if (head) {
				ListNode *p = head->next;
				head->next = NULL;

				while (p) {
					ListNode *q = p->next;
					p->next = head;
					head = p;
					p = q;
				}
			}

			return head;
		}
};

int main() {
	int num;
	ListNode *head = NULL;
	ListNode *p;

	while (cin >> num) {
		p = new ListNode(num);
		p->next = head;
		head = p;
	}

	p = head;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	Solution sol;
	head = sol.reverseList(head);

	p = head;
	while (p != NULL) {
		cout << p->val << " " ;
		p = p->next;
	}

	cout << endl;
	return 0;
}
