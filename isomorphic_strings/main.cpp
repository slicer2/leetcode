#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		bool isIsomorphic(string s, string t) {
			if (s.size() != t.size())
				return false;

			unordered_map<char, char> tr, itr;

			for (unsigned i=0; i<s.size(); i++) {
				if (tr.find(s[i]) != tr.end()) {
					if (tr[s[i]] != t[i])
						return false;
				}
				else {
					if (itr.find(t[i]) != itr.end())
						return false;
					else {
						tr[s[i]] = t[i];
						itr[t[i]] = s[i];
					}
				}
			}

			return true;
		}
};

int main() {
	string s, t;
	cin >> s >> t;

	Solution sol;
	if (sol.isIsomorphic(s, t))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}
