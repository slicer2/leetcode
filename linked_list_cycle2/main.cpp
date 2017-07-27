/**
 8 The most difficult part of this program is not to damage the linked list
 * So the idea is to restore it if some alteration is necessary along the way
**/


//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//Follow up:
//Can you solve it without using extra space?

//Given a linked list, determine if it has a cycle in it.
//
//Follow up:
//Can you solve it without using extra space?

#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
	public:
		int hasCycle(ListNode *head) {
			int slow_steps = 0;

			if (!head)
				return -1;

			ListNode *slow = head, *fast = head->next;

			while (slow && fast && slow != fast) {
				slow = slow->next;
				slow_steps++;

				fast = fast->next;
				if (fast) 
					fast = fast->next;
				else
					return -1;
			}

			if (!slow || !fast)
				return -1;

			return slow_steps;
		}

		ListNode *detectCycle(ListNode *head) {
			int max_step = hasCycle(head);


			if (max_step >= 0) {

				ListNode *pos = head;

				if (pos == pos->next)
					return pos;

				while ( (long)pos->next % 2 == 0 ) {
					ListNode *t = pos->next;
					pos->next = (ListNode *)( (char *)pos->next + 1 );
					pos = t;
				}

				ListNode *pos2 = head;
				while (pos2 != pos) {
					pos2->next = (ListNode *)((char *)pos2->next - 1);
					pos2 = pos2->next;
				}

				return pos;
			}
			else
				return NULL;
		}
};


int main(){
	int n;
	cin >> n;

	ListNode *lst = new ListNode[n];



	for (int i=0; i<n; i++) {
		int val;
		int nxt;
		cin >> val >> nxt;
		lst[i].val = val;
		if (nxt >= 0)
			lst[i].next = &lst[nxt];
	}




	ListNode *pos;
	int i;

	for (i=0, pos = lst; i<10 && pos; i++) {
		cerr<<pos->val<<"  ";
		pos = pos->next;
	}

	cerr<<endl;

	Solution s;
	ListNode *rst = s.detectCycle(lst);
	if ( rst )
		cerr<<"Cycle starts at value "<<rst->val<<endl;
	else
		cerr<<"No cycle"<<endl;

	delete [] lst;
	return 0;
}
