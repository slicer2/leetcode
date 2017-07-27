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
		ListNode *rotateRight(ListNode *head, int k) {
			if (!head)
				return head;

			ListNode *p = head;
			ListNode *q = head->next;
			p->next = NULL;


			int len = 1;

			while (q) {
				ListNode *temp = q->next;
				q->next = p;
				p = q;
				q = temp;

				len++;
			}

			k = k % len;

			q = p;
			head = NULL;

			for (int i=0; i<k; i++) {
				ListNode *temp = p->next;
				p->next = head;
				head = p;
				p = temp;
			}

			ListNode *r = NULL;
			while (p) {
				ListNode *temp = p->next;
				p->next = r;
				r = p;
				p = temp;
			}

			if (k > 0) {
				q->next = r;
				return head;
			}
			else {
				return r;
			}
		}
};

int main() {
	int n, k;
	ListNode *head = NULL;

	cin >> k;

	while (cin >> n) {
		ListNode *p = new ListNode (n);
		p->next = head;
		head = p;
	}

	Solution sol;

	head = sol.rotateRight(head, k);

	for (ListNode *p=head; p != NULL; p = p->next)
		cout << p->val << ' ';
	
	cout << endl;

	return 0;
}
