#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <utility>
#include "dan.h"
#include <functional>

using namespace std;

class Solution {
	typedef unordered_set<string>::const_iterator ptrust;
	struct MyHash {
		size_t operator()(const ptrust &x) const {
			hash<string> h;
			return h(*x);
		}
	};

	public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		unordered_map<ptrust, vector<ptrust>, MyHash> prev;
		queue<ptrust> q;
		unordered_set<string>::iterator it;
		pair<unordered_set<string>::iterator, bool> ins;
		ins = wordList.insert(beginWord);
		ptrust pBeginWord = ins.first;
		q.push(pBeginWord);
		ins = wordList.insert(endWord);
		ptrust pEndWord = ins.first;
		ins = wordList.insert("");
		ptrust pDelim = ins.first;
		q.push(pDelim);

		for (ptrust it = wordList.cbegin(); it != wordList.end(); it++) prev.insert(make_pair(it, vector<ptrust>()));
		prev[pBeginWord].push_back(pDelim);

		bool stop = false;
		int wordSize = beginWord.size();

		unordered_set<ptrust, MyHash> next;
		while (!q.empty()) {
			ptrust curr = q.front();
			q.pop();

			if (*curr == "") {
				if (stop) break;
				else {
					next.clear();
					q.push(pDelim);
					continue;
				}
			}


			for (int i=0; i<wordSize; i++) {
				string neighbor = *curr;

				for (int j=0; j<26; j++) {
					if (j == curr->at(i) - 'a') continue;
					neighbor[i] = (char)('a'+j);
					auto it = wordList.find(neighbor);

					if (it != wordList.end() && (prev[it].empty() || next.find(it) != next.end())) {
						prev[it].push_back(curr);
						if (next.find(it) == next.end()) {
							next.insert(it);
							q.push(it);
						}
						if (it == pEndWord) stop = true;
					}
				}
			}
		}

		vector<ptrust> partial;
		vector<vector<string>> res;

		if (stop) {
			partial.push_back(pEndWord);
			dfs(partial, prev, res, wordList, pDelim);
		}

		return res;
	}

	void dfs(vector<ptrust> &partial, unordered_map<ptrust, vector<ptrust>, MyHash> &prev, vector<vector<string>> &res, unordered_set<string> &wordList, ptrust pDelim) {
		if (prev[partial.back()][0] == pDelim) {
			vector<string> row;
			for (auto rit = partial.rbegin(); rit != partial.rend(); rit++)
				row.push_back(**rit);

			res.push_back(row);

			return;
		}

		for (auto x: prev[partial.back()]) {
			partial.push_back(x);
			dfs(partial, prev, res, wordList, pDelim);
			partial.pop_back();
		}
	}
};

int main() {
	unordered_set<string> dict;
	string s;

	string start, end;

	cin >> start >>  end;

	while (cin >> s)
		dict.insert(s);

	Solution sol;

	vector<vector<string> > sentences = sol.findLadders(start, end, dict);

	cout << sentences;

	return 0;
}
