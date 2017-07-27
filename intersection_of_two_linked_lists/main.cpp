#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

struct ListNode {

	int val;

	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
	ListNode * reverse(ListNode *head) {
		ListNode *p = NULL;

		while (head != NULL) {
			ListNode *t = head->next;
			head->next = p;
			p = head;
			head = t;
		}

		return p;
	}

	public:

		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			if (!headA || !headB)
				return NULL;

			ListNode *p, *lastA = NULL, *lastB = NULL;

			int lA = 0;
			for (p = headA; p != NULL; lastA = p, p = p->next)
				lA++;

			int lB = 0;
			for (p = headB; p != NULL; lastB = p, p = p->next)
				lB++;

			if (lastA != lastB)
				return NULL;

			headB = reverse(headB);

			int lC = 0;
			for (p = headA; p != NULL; p = p->next)
				lC++;

			headB = reverse(headB);

			int len = (lA+lB+lC)/2 - lB;

			int i;
			for (i=0, p = headA; i<len; i++, p = p->next);

			return p;
		}

};

int main() {
	ListNode *headA = NULL, *headB = NULL;
	ListNode *headC = NULL;

	string s;
	int num;

	getline(cin, s);
	cout << "s = " << s << endl;

	stringstream ss(s);

	while (ss >> num) {
		ListNode *p = new ListNode(num);
		p->next = headC;
		headC = p;
	}

	if (headC) {
		headA = headC;
		headB = headC;
	}

	getline(cin, s);

	cout << "s = " << s << endl;

	{
		stringstream ss(s);

		while (ss >> num) {
			ListNode *p = new ListNode(num);
			p->next = headA;
			headA = p;
		}
	}

	getline(cin, s);
	cout << "s = " << s << endl;

	{
		stringstream ss(s);

		while (ss >> num) {
			ListNode *p = new ListNode(num);
			p->next = headB;
			headB = p;
		}
	}

	cerr << "A = ";
	for (ListNode *p = headA; p != NULL; p = p->next)
		cerr << p->val << ' ';

	cerr << endl;

	cerr << "B = ";
	for (ListNode *p = headB; p != NULL; p = p->next)
		cerr << p->val << ' ';

	cerr << endl;

	Solution sol;

	ListNode *intersection = sol.getIntersectionNode(headA, headB);

	int intersectionValue = (intersection)?intersection->val:0;
	cout << intersectionValue << endl;

	return 0;
}
