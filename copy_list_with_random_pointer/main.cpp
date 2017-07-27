#include <iostream>
#include <map>
#include <utility>

using namespace std;


struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x = 0) : label(x), next(NULL), random(NULL) {}
};

ostream & operator<< (ostream & os, RandomListNode *lst) {
	while (lst) {
		os << lst->label << '\t' << ( (lst->random)?lst->random->label:(-1) ) 
		<< '\t' << ( (lst->next)?lst->next->label:(-1) ) << endl;

		lst = lst->next;
	}

	return os;
}

class Solution {

	typedef map<RandomListNode *, RandomListNode *> VisitedList;

	VisitedList visited;

	RandomListNode *traverse(RandomListNode *p, VisitedList &visited_in) {

		RandomListNode *new_p = NULL;

		if (!p) return new_p;

		new_p = new RandomListNode(p->label);

		visited_in.insert(make_pair(p, new_p));

		if (p->random) {
			VisitedList::iterator lookup_it = visited_in.find(p->random);
			if (lookup_it == visited_in.end())
				new_p->random = traverse(p->random, visited_in);
			else
				new_p->random = lookup_it->second;
		}

		if (p->next) {
			VisitedList::iterator lookup_it = visited_in.find(p->next);
			if (lookup_it == visited_in.end())
				new_p->next = traverse(p->next, visited_in);
			else
				new_p->next = lookup_it->second;
		}

		return new_p;
	}

	public:
	RandomListNode *copyRandomList(RandomListNode *head) {

		return traverse(head, visited);
	}
};

int main(){
	int n;
	cin >> n;

	RandomListNode *lst = new RandomListNode[n];



	for (int i=0; i<n; i++) {
		int label;
		int rnd;

		cin >> label >> rnd;
		lst[i].label = label;
		if (i<n-1)
			lst[i].next = &lst[i+1];
		else
			lst[i].next = NULL;

		if (rnd > -1)
			lst[i].random = &lst[rnd];
		else
			lst[i].random = NULL;
	}




	RandomListNode *new_lst;

	Solution s;

	new_lst = s.copyRandomList(lst);

	cout << string("curr") << '\t' << string("rand") << '\t' << string("next") << endl;
	cout << "lst" << endl << lst;

	cout << "new_lst" << endl << new_lst;

	return 0;
}
