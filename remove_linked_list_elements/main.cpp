#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* removeElements(ListNode* head, int val) {
			ListNode *head2 = new ListNode(99);
			head2->next = head;

			ListNode *p = head2;

			while (p->next) {
				if (p->next->val == val) {
					ListNode *q = p->next;
					p->next = p->next->next;
					delete q;
				}
				else
					p = p->next;
			}

			head = head2->next;
			delete head2;
			return head;
		}
};


int main() {
	ListNode *head = NULL, *p;

	int val, n;

	cin >> val;

	while (cin >> n) {
		p = new ListNode(n);
		p->next = head;
		head = p;
	}

	cout << "after reading in: " << endl;

	p = head;

	while (p) {
		cout << p->val << " ";
		p = p->next;
	}

	cout << "done" << endl;

	Solution sol;
	head = sol.removeElements(head, val);

	p = head;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;

	while (head) {
		p = head;
		head = head->next;
		delete p;
	}

	return 0;
}
