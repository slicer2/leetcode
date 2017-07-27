#include <iostream>

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
	public:
		ListNode *insertionSortList(ListNode *head) {
			ListNode *last = head;

			if (!last) return NULL;

			ListNode *next = last->next;

			while (next) {
				ListNode **p = &head;

				while ((*p)->val <= next->val && (*p) != next) p = &( (*p)->next );

				if ((*p) != next) {
					ListNode *pt = (*p);
					(*p) = next;
					last->next = next->next;
					next->next = pt;
				}
				else {
					last = next;
				}

				next = last->next;
			}


			return head;
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

	lst = s.insertionSortList(lst);

	display(lst);

	return 0;
}
