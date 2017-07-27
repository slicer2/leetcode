#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *removeNthFromEnd(ListNode *head, int n) {
			ListNode *t = new ListNode(0), *p = t, *q = t;
			t->next = head;

			for (int i=0; i<n+1; i++) q = q->next;

			while (q) { p = p->next; q = q->next; }

			ListNode *tmp = p->next;
			p->next = p->next->next;
			delete tmp;

			p = t->next;
			delete t;

			return p;
		}
};

int main() {
	int n, num;
	cin >> n;

	ListNode *head = NULL;

	while (cin >> num) {
		ListNode *p = new ListNode(num);
		p->next = head;
		head = p;
	}

	Solution sol;
	head = sol.removeNthFromEnd(head, n);

	for (ListNode *p = head; p != NULL; p = p->next)
		cout << p->val << ' ';
	
	cout << endl;

	return 0;
}
