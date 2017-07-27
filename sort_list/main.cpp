//Sort a linked list in O(n log n) time using constant space complexity

#include <iostream>
#include <cstdlib>

#define ERRMSG(y, z) \
        cerr << "line " << __LINE__ << ": " \
		<< y << ' ' << z << endl;

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void push_front(ListNode *&head, int n) {
	ListNode * tnode = new ListNode(n);
	tnode->next = head;
	head = tnode;
}

void display(ListNode *head) {
	cout<<"lst: ";
	while (head) {
		cout << head->val << "  ";
		head = head->next;
	}

	cout<<endl;
}

class Solution {
	/**
	 * require: s not NULL
	 * return: start of 2nd lst to be merged
	 *   NULL if 2nd lst not exist
	 **/

	ListNode *locate2nd(ListNode *s, int len){
		ListNode *t = s;
		for (int i=0; i<len && t; i++) {
			t = t->next;
		}

		return t;
	}

	public:
	ListNode *sortList(ListNode *head) {
		int len = 1;
		ListNode *q, *s1, *s2, **p;
		int  loop_count = 0;

		do {
			// *p points to the current node in first
			// list, from the previous node
			p = &head; 

			s1 = locate2nd(*p, len);
			//ERRMSG("s1 points to", ( (s1)? s1->val:0 ));

			while (s1) {
				loop_count ++;

				//ERRMSG("len =", len);

				s2 = locate2nd(s1, len);


				// q is the pointer that points to
				// the current node of second sublist
				q = s1;

				//ERRMSG ("starting with", (*p)->val << " and " << q->val);


				while (*p != s1 && q != s2) {
					if ((*p)->val <= q->val) {
						//cerr << (*p)->val << "<=" << q->val << " advancing *p" << endl;
						p = &( (*p)->next );
					}
					else {
						//cerr << (*p)->val << ">" << q->val << " advancing q" << endl;

						ListNode *pt = (*p);
						//ERRMSG("pt points to", pt->val);
						*p = q;
						//ERRMSG("(*p) points to", (*p)->val);
						q = q->next;
						//ERRMSG("q points to", ( (q)?q->val:0 ));
						(*p)->next = pt;
						//ERRMSG("(*p)->next points to", (*p)->next->val);
						p = &( (*p)->next );
						//ERRMSG("*p points to", (*p)->val);
					}
				}

				if ((*p) == s1) {
					*p = q;
					while (*p != s2) p = &( (*p)->next );
				}
				else {
					// q == s2
					while (*p != s1) p = &( (*p)->next );

					*p = s2;
				}

				display(head);
				
				s1 = locate2nd(*p, len);

				//ERRMSG("s1 points to", ( (s1)?s1->val:0 ));
			}

			len *= 2;

		} while ((*p) != head);

		return head;
	}
};


int main() {
	int n;

	ListNode *lst = NULL;

	while(cin >> n) {
		push_front(lst, n);
	}

	display(lst);

	Solution s;

	lst = s.sortList(lst);

	display(lst);

	return 0;
}
