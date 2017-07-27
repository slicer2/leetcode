#include <iostream>
#include <string>
#include <vector>
#include "dan.h"
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution {
	public:
		vector<int> findSubstring(string S, vector<string> &L) {
			unordered_map<string, int> dict, dict0;
			int totalWords = 0;
			for (auto &x: L) {
				if (dict.find(x) == dict.end())
					dict.insert(make_pair(x, 1));
				else
					dict[x]++;
				totalWords++;
			}
			dict0 = dict;

			int wordLen = L[0].size(), sz = S.size();
			vector<int> res;
			for (int i=0; i<wordLen; i++) {
				int p = i, q = p;
				dict = dict0;

				while (q + wordLen <= sz) {
					if (dict.find(S.substr(q, wordLen)) == dict.end()) {
						q += wordLen; p = q;
						dict = dict0;
					}
					else {
						if (dict[S.substr(q, wordLen)] > 0) {
							dict[S.substr(q, wordLen)]--;
							q += wordLen;
							if (q - p == wordLen * totalWords) {
								res.push_back(p);
								dict[S.substr(p, wordLen)]++;
								p += wordLen;
							}
						}
						else {
							dict[S.substr(p, wordLen)]++;
							p += wordLen;
						}
					}
				}
			}

			return res;
		}
};

int main() {
	string s;
	cin >> s;

	string small;
	vector<string> L;
	while (cin >> small)
		L.push_back(small);

	Solution sol;

	vector<int> result = sol.findSubstring(s, L);

	//abort();

	cout << result << endl;

	return 0;
}
