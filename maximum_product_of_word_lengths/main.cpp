#include <iostream>
#include "dan.h"
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
	struct GraphNode {
		int len;
		unsigned long used;
		vector<int> neighbors;
	};

	vector<GraphNode> g;
	vector<int> visited;
	unordered_map<unsigned long, int> mp;

	public:
		int maxProduct(vector<string>& words) {
			buildGraph(words);

			int prod = 0, sz = g.size();
			visited.resize(sz, 0);

			for (int i=0; i<sz; i++) dfs(i, prod);

			return prod;
		}

		void dfs(int idx, int &prod) {
			if (!visited[idx]) {
				visited[idx] = 1;

				for (auto y: g[idx].neighbors) {
					if (visited[y] != 2) prod = max(prod, g[idx].len * g[y].len);
					dfs(y, prod);
				}

				visited[idx] = 2;
			}
		}

		void buildGraph(vector<string> &words) {
			for (auto x: words) {
				unsigned long char_used = 0;
				for (auto y: x) char_used |= 1 << (y-'a');

				if (mp.find(char_used) == mp.end()) {
					GraphNode tmp;
					tmp.len = x.size();
					tmp.used = char_used;

					int gsize = g.size();
					for (int i=0; i<gsize; i++)
						if (!(g[i].used & char_used)) {
							tmp.neighbors.push_back(i);
							g[i].neighbors.push_back(gsize);
						}

					g.push_back(tmp);
					mp[char_used] = gsize;
				}
				else
					g[mp[char_used]].len = max(g[mp[char_used]].len, (int)x.size());
			}
		}
};

int main() {
	vector<string> words;
	cin >> words;

	Solution sol;
	cout << sol.maxProduct(words) << endl;
	return 0;
}
