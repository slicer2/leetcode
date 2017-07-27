#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int longestValidParentheses(string s) {
			int maxLen = 0, sz = s.size();
			stack<int> sta;
			stack<pair<int, int>> completed;

			for (int i=0; i<sz; i++) {
				if (s[i] == '(')
					sta.push(i);
				else {
					if (!sta.empty()) {
						pair<int, int> curr = make_pair(sta.top(), i);
						sta.pop();

						while (!completed.empty()) {
							pair<int, int> prev = completed.top();
							if (prev.second + 1 == curr.first) {
								curr.first = prev.first;
								completed.pop();
							}
							else if (prev.first > curr.first) {
								completed.pop();
							}
							else
								break;
						}

						completed.push(curr);
					}
				}
			}

			while (!completed.empty()) {
				pair<int, int> p = completed.top();
				completed.pop();
				maxLen = max(maxLen, p.second-p.first+1);
			}

			return maxLen;
		}
};

int main() {
	string s;
	cin >> s;

	Solution sol;
	cout << sol.longestValidParentheses(s) << endl;

	return 0;
}
