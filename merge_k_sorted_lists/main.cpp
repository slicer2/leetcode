#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "dan.h"
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	struct myLess {
		bool operator () (const pair<int, ListNode *> &p1, const pair<int, ListNode *> &p2) {
			return (p1.second->val > p2.second->val);
		}
	};

	public:
		ListNode *mergeKLists(vector<ListNode *> &lists) {
			ListNode *head = new ListNode(0);
			ListNode *tail = head;
			unordered_map<int, ListNode *> curr;
			priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *> >, myLess> pq;

			for (unsigned i=0; i<lists.size(); i++) {
				if (lists[i]) {
					pq.push(make_pair(i, lists[i]));
					curr[i] = lists[i]->next;
				}
			}

			while (!pq.empty()) {
				pair<int, ListNode *> p = pq.top();
				tail->next = p.second;
				tail = tail->next;
				pq.pop();

				if (curr[p.first]) {
					pq.push(make_pair(p.first, curr[p.first]));
					curr[p.first] = curr[p.first]->next;
				}
				else
					curr.erase(p.first);
			}

			tail->next = NULL;

			tail = head;
			head = head->next;
			delete tail;

			return head;
		}
};

int main() {
	vector<int> row;
	vector<ListNode *> lists;

	while (cin >> row) {
		//cout << row << endl;
		ListNode *head = NULL;
		for (auto &x: row) {
			ListNode *p = new ListNode(x);
			p->next = head;
			head = p;
		}

		lists.push_back(head);

		row.clear();
	}

	Solution sol;
	ListNode *merged = sol.mergeKLists(lists);

	ListNode *q;
	for (ListNode *p = merged; p != NULL; q = p, p = p->next, delete q)
		cout << p->val << ' ';

	cout << endl;

	return 0;
}
