#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include "dan.h"

using namespace std;

class Solution {
	private:
		unordered_map<int, unordered_set<int>> graph;
		vector<string> res;
		string s;
	public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		this->s = s;
		buildGraph(s.size(), dict); 
		string row;
		buildBreak(0, row);

		return res;
	}

	void buildGraph(int start, unordered_set<string> &dict) {
		if (start == 0) return;
		for (int i=start-1; i>=0; i--) {
			if (dict.find(s.substr(i, start-i)) != dict.end()) {
				graph[i].insert(start);
				if (graph[i].size() == 1)
					buildGraph(i, dict);
			}
		}
	}

	void buildBreak(int start, string &row) {
		if (start == s.size()) {
			res.push_back(row.substr(0, row.size()-1));
			return;
		}

		for (auto x: graph[start]) {
			string row0 = row;
			row += s.substr(start, x-start)+" ";
			buildBreak(x, row);
			row = row0;
		}
	}
};

int main() {
	string s, longword;
	unordered_set<string> dict;

	cin>>longword;

	while (cin >> s)
		dict.insert(s);

	Solution sol;

	vector<string> ss = sol.wordBreak(longword, dict);

	for (auto x: ss) cout << x << endl;

	return 0;
}
