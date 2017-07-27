#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "dan.h"

using namespace std;

class Solution {
	void getCharCount(string &s, vector<int> &result) {
		for (auto &x: s)
			result[x-'a']++;
	}

	public:
		vector<string> anagrams(vector<string> &strs) {
			map<vector<int>, vector<int> > group;

			for (int i=0; i<(int)strs.size(); i++) {
				vector<int> cnt(26, 0);
				getCharCount(strs[i], cnt);

				group[cnt].push_back(i);
			}

			vector<string> result;

			for (auto &x: group) {
				if (x.second.size() > 1)
					for (auto &y: x.second)
						result.push_back(strs[y]);
			}

			return result;
		}
};

int main() {
	vector<string> strs;
	string s;

	while (cin >> s)
		strs.push_back(s);

	Solution sol;

	for (auto &x: sol.anagrams(strs))
		cout << x << endl;

	cout << endl;

	return 0;
}
