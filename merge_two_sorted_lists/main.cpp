#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			if (!l1) return l2;
			if (!l2) return l1;
			if (l1->val < l2->val) {
				l1->next = mergeTwoLists(l1->next, l2);
				return l1;
			}
			else {
				l2->next = mergeTwoLists(l1, l2->next);
				return l2;
			}
		}
};

int main() {
	ListNode *l1 = NULL, *l2 = NULL;
	int n;
	string s;

	getline(cin, s);

	stringstream ss1(s);

	while (ss1 >> n) {
		ListNode *p = new ListNode (n);
		p->next = l1;
		l1 = p;
	}

	getline(cin, s);

	stringstream ss2(s);

	while (ss2 >> n) {
		ListNode *p = new ListNode (n);
		p->next = l2;
		l2 = p;
	}

	Solution sol;

	ListNode *l = sol.mergeTwoLists(l1, l2);

	for (ListNode *p = l; p != NULL; p = p->next)
		cout << p->val << ' ';

	cout << endl;

	return 0;
}
