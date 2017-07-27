#include <iostream>
using namespace std;

#define ERRMSG(y) cerr << __LINE__ << ": " << #y \
					<< "---" << ( (y)?y->val:0 ) << endl;

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

// require p, p->next, p->next->next
class Solution {
	int get_count(ListNode *p){
		if (!p) return 0;

		int count = 0;
		
		while (p) {
			count++;
			p = p->next;
		}

		return count;
	}

	public:
		void reorderList(ListNode *head) {
			int count = get_count(head);

			if (count < 3) return;

			ListNode *s1 = head, *p1 = head->next;
			for (int i=0; i<count/2-1; i++) {
				ListNode *pt = p1->next;

				//ERRMSG(pt);

				p1->next = s1;

				//ERRMSG(p1->next);

				s1 = p1;

				//ERRMSG(s1);

				p1 = pt;

				//ERRMSG(p1);
			}

			ListNode *s = NULL, *s2 = p1;
			
			if (count % 2) {
				s2 = s2->next;
				s = p1;
				s->next = NULL;
			}
			
			//ERRMSG(s);
			//ERRMSG(s2);

			for (int i=0; i<count/2-1; i++) {
				ListNode *st1 = s1->next, *st2 = s2->next;

				//ERRMSG(st1);
				//ERRMSG(st2);

				s1->next = s2;

				//ERRMSG(s1->next);

				s2->next = s;

				//ERRMSG(s2->next);

				s = s1;

				//ERRMSG(s);

				s1 = st1;

				//ERRMSG(s1);

				s2 = st2;

				//ERRMSG(s2);
			}

			head->next = s2;
			s2->next = s;
		}
};

int main(){

	int n;

	ListNode *lst = NULL;

	while(cin >> n) {
		push_front(lst, n);
	}

	display(lst);

	Solution s;

	s.reorderList(lst);

	display(lst);

	return 0;
}
