#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *partition(ListNode *head, int x) {
			ListNode *p = head, *t_head = NULL;
			ListNode **q = &head, **r = &t_head;

			while (p != NULL) {
				while (p != NULL && p->val < x) {

					(*q) =  p;
					q = &(p->next);
					p = p->next;
				}

				if (p != NULL) {
					ListNode *t = p->next;
					p->next = NULL;
					(*r) = p;
					r = &p->next;

					p = t;
				}
			}

			(*q) = t_head;
			return head;
		}
};

int main() {
	int n, x;
	cin >> n >> x;

	ListNode *head = NULL;

	for (int i=0; i<n; i++) {
		ListNode *p = new ListNode (i);
		p->next = head;
		head = p;

		p = new ListNode (i);
		p->next = head;
		head = p;
	}

	for (ListNode *p = head; p != NULL; p = p->next)
		cout << p->val << ' ';

	cout << endl;

	Solution sol;
	head = sol.partition(head, x);

	for (ListNode *p = head; p != NULL; p = p->next)
		cout << p->val << ' ';

	cout << endl;

	return 0;
}
