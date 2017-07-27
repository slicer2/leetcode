#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "dan.h"

using namespace std;

class Solution {
	public:
		string removeDuplicateLetters(string s) {
			vector<vector<int>> pos(26, vector<int>());
			unordered_set<char> distinctChars;

			int sz = s.size();
			for (int i = sz-1; i >= 0; i--) {
				pos[s[i]-'a'].push_back(i);
				if (distinctChars.find(s[i]) == distinctChars.end())
					distinctChars.insert(s[i]);
			}

			string res;
			
			int left = 0;
			while (!distinctChars.empty()) {
				int right = sz;

				for (auto x: distinctChars)
					right = min(right, pos[x-'a'][0]);

				char lowestChar = 'z';
				for (auto x: distinctChars) {
					while (!pos[x-'a'].empty() && pos[x-'a'].back() < left) pos[x-'a'].pop_back();
					if (!pos[x-'a'].empty() && pos[x-'a'].back() <= right)
						lowestChar = min(lowestChar, x);
				}

				res.push_back(lowestChar);
				distinctChars.erase(lowestChar);
				left = pos[lowestChar-'a'].back() + 1;
			}

			return res;
		}
};

int main() {
	string s;
	cin >> s;

	Solution sol;
	cout << sol.removeDuplicateLetters(s) << endl;

	return 0;
}
