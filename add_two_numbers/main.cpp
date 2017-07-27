#include <iostream>
#include <sstream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			ListNode *l = NULL;
			ListNode *p;
			int num, carry = 0;

			while (l1 || l2) {
				if (l1) {
					if (l2) {
						num = l1->val + l2->val + carry;
						l2 = l2->next;
					}
					else
						num = l1->val + carry;

					l1 = l1->next;
				}
				else {
					num = l2->val + carry;
					l2 = l2->next;
				}

				if (num > 9) {
					num -= 10;
					carry = 1;
				}
				else
					carry = 0;

				p = new ListNode(num);
				p->next = l;
				l = p;
			}

			if (carry > 0) {
				p = new ListNode(carry);
				p->next = l;
				l = p;
			}

			p = NULL;
			while (l != NULL) {
				ListNode *t = l->next;
				l->next = p;
				p = l;
				l = t;
			}

			return p;
		}
};

int main() {
	ListNode *l1 = NULL, *l2 = NULL;
	string s;

	int num;

	{
		getline(cin, s);

		stringstream ss(s);

		while(ss >> num) {
			ListNode *p = new ListNode(num);
			p->next = l1;
			l1 = p;
		}
	}

	{
		getline(cin, s);

		stringstream ss(s);

		while (ss >> num) {
			ListNode *p = new ListNode(num);
			p->next = l2;
			l2 = p;
		}
	}

	Solution sol;

	ListNode *l = sol.addTwoNumbers(l1, l2);

	for (ListNode *p = l; p != NULL; p = p->next)
		cout << p->val << ' ';

	cout << endl;

	return 0;
}
