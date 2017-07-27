#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *reverseBetween(ListNode *head, int start, int end) {
			ListNode *new_head = new ListNode(0);
			new_head->next = head;

			ListNode *p = new_head;

			start++;
			end++;

			stack<ListNode *> sta;

			for (int i=1; i<start-1; i++)
				p = p->next;

			ListNode *q = p->next;

			for (int i=start; i<=end; i++) {
				sta.push(q);
				q = q->next;
			}

			for (int i=start; i<=end; i++) {
				p->next = sta.top();
				sta.pop();
				p = p->next;
			}

			p->next = q;

			head = new_head->next;

			delete new_head;

			return head;
		}
};

int main() {
	int n;
	int start, end;

	cin >> n >> start >> end;

	ListNode *head = NULL;

	for (int i=n-1; i>=0; i--) {
		ListNode *p = new ListNode(i);
		p->next = head;
		head = p;
	}


	Solution sol;

	head = sol.reverseBetween(head, start, end);

	for (ListNode *p = head; p != NULL; p = p->next)
		cout << p->val << ' ';

	return 0;
}
