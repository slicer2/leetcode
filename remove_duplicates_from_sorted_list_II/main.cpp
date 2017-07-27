#include <iostream>

using namespace std;

#define MSG(x) ((x)?(x->val):0)

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

			ListNode *tHead = new ListNode (100);
			tHead->next = head;

			ListNode *p1 = tHead, *p2 = p1->next, *p3 = p1->next->next;

			while (p3) {
				if (p3->val == p2->val) {
					while (p3 && p3->val == p2->val) p3 = p3->next;

					p2 = p3;

					if (p3) {
						p3 = p3->next;
					}
				}
				else {
					p1->next = p2;
					p2 = p3;
					p3 = p3->next;
					p1 = p1->next;
				}
			}

			p1->next = p2;

			return tHead->next;
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
