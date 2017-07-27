#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cstdlib>
#include <unordered_set>


using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x = 0) : label(x) {};
};

typedef unordered_set<UndirectedGraphNode *> Visited;

void disp(UndirectedGraphNode *node, Visited &vis) {
	if (!node) return;

	cerr << node->label << ' ';

	for (vector<UndirectedGraphNode *>::iterator it = node->neighbors.begin();
		it != node->neighbors.end(); it++) {

		cerr << (*it)->label << ' ';
	}

	cerr << endl;

	vis.insert(node);

	for (vector<UndirectedGraphNode *>::iterator it = node->neighbors.begin();
		it != node->neighbors.end(); it++) {
		
		if (vis.find(*it) == vis.end())
			disp(*it, vis);
	}
}

void display(UndirectedGraphNode *node){
	Visited vis;
	
	disp(node, vis);
}

class Solution {
	private:
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
	public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return NULL;
		UndirectedGraphNode *h = new UndirectedGraphNode(node->label);
		mp.insert(make_pair(node, h));

		for (auto x: node->neighbors) {
			if (mp.find(x) == mp.end())
				h->neighbors.push_back(cloneGraph(x));
			else
				h->neighbors.push_back(mp[x]);
		}

		return h;
	}
};

int main() {
	int n;
	int label;
	int neighbor;

	cin >> n;

	UndirectedGraphNode *node = new UndirectedGraphNode [n];

	int idx = 0;
	while (idx < n) {
		cin >> label;

		node[idx].label = label;

		cin >> neighbor;

		while (neighbor != -1) {
			node[idx].neighbors.push_back(&node[neighbor]);

			cin >> neighbor;
		}

		idx ++;
	}

	cerr << "original" << endl;
	display(node);
	cerr << "copy" << endl;

	Solution s;
	UndirectedGraphNode *new_node = s.cloneGraph(node);
	display(new_node);

	return 0;
}
