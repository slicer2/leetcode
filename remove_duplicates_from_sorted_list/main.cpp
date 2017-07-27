#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *deleteDuplicates(ListNode *head) {
			if (!head)
				return head;

			ListNode *p1 = head, *p2 = p1->next;

			while (p2) {
				if (p1->val == p2->val) {
					p2 = p2->next;
				}
				else {
					p1->next = p2;
					p1 = p2;
					p2 = p2->next;
				}
			}

			p1->next = p2;

			return head;
		}
};

int main() {
	int n;
	ListNode *head = NULL;

	while (cin >> n) {
		ListNode *p = new ListNode (n);
		p->next = head;
		head = p;
	}

	Solution sol;

	head = sol.deleteDuplicates(head);

	for (ListNode *p = head; p != NULL; p = p->next)
		cout << p->val << ' ';

	cout << endl;

	return 0;
}
