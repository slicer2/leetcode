#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *swapPairs(ListNode *head) {
			if (!head || !head->next)
				return head;

			ListNode *prevTail = new ListNode(0);
			ListNode *curr1 = head;
			ListNode *curr2 = curr1->next;
			head = prevTail;

			while (curr2) {
				ListNode *t = curr2->next;
				curr2->next = curr1;
				curr1->next = NULL;
				prevTail->next = curr2;
				prevTail = curr1;

				curr1 = t;

				if (curr1)
					curr2 = curr1->next;
				else
					curr2 = NULL;
			}

			if (curr1) {
				prevTail->next = curr1;
				curr1->next = NULL;
			}

			prevTail = head;
			head = head->next;
			delete prevTail;

			return head;
		}
};

int main() {
	ListNode *head = NULL;
	int num;

	while (cin >> num) {
		ListNode *p = new ListNode(num);
		p->next = head;
		head = p;
	}

	Solution sol;

	head = sol.swapPairs(head);

	for (ListNode *p = head; p != NULL; p = p->next)
		cout << p->val << ' ';

	cout << endl;

	return 0;
}
