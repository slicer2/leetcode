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
		ListNode *reverseKGroup(ListNode *head, int k) {
			if (head == NULL)
				return head;

			ListNode *prevTail= new ListNode(0);
			ListNode *curr= head;
			head = prevTail;

			while (curr != NULL) {
				ListNode *tail = curr;
				ListNode *prev= NULL;
				int i;

				for (i=0; i<k && curr != NULL; i++) {
					ListNode *t = curr->next;
					curr->next = prev;
					prev = curr;
					curr = t;
				}

				if (i == k) {
					prevTail->next = prev;
					prevTail = tail;
				}
				else {
					curr = prev;
					prev = NULL;

					while (curr != NULL) {
						ListNode *t = curr->next;
						curr->next = prev;
						prev = curr;
						curr = t;
					}

					prevTail->next = prev;
				}
			}

			curr = head;
			head = head->next;
			delete curr;

			return head;
		}
};

int main() {
	ListNode *head = NULL;
	int k;
	int num;

	cin >> k;

	while (cin >> num) {
		ListNode *p = new ListNode(num);
		p->next = head;
		head = p;
	}

	//for (ListNode *p = head; p != NULL; p=p->next)
	//	cout << p->val << ' ';

	//cout << endl;

	//abort();

	Solution sol;
	head = sol.reverseKGroup(head, k);

	for (ListNode *p = head; p != NULL; p=p->next)
		cout << p->val << ' ';

	cout << endl;

	return 0;
}
