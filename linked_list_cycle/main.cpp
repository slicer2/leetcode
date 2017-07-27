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
		bool hasCycle(ListNode *head) {
			if (!head)
				return false;

			ListNode *slow = head, *fast = head->next;

			while (slow && fast && slow != fast) {
				slow = slow->next;
				fast = fast->next;
				if (fast) 
					fast = fast->next;
				else
					return false;
			}

			if (!slow || !fast)
				return false;

			return true;
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
	cerr<< ( s.hasCycle(lst)? "Yes":"No" )<<endl;
	return 0;
}
