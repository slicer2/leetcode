#include <iostream>
#include <unordered_set>
#include <string>

#define MAX(x, y) ((x>y)?x:y)

using namespace std;

string indent("");

class Solution {
	int max_len(unordered_set<string> &dict) {
		int max_l = 0;

		unordered_set<string>::iterator it = dict.begin();
		for (; it != dict.end(); it++)
			if ( (*it).length() > max_l)
				max_l = (*it).length();

		return max_l;
	}
	public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		bool *breakable = new bool[s.length()];
		int max_l = max_len(dict);

		for (int i=0; i<s.length(); i++)
			breakable[i] = false;

		for (int i=0; i<s.length(); i++) {
			if ( dict.find(s.substr(0, i+1)) != dict.end() ) {
				breakable[i] = true;
				continue;
			}

			for (int j=MAX(0, i-max_l); j<i; j++) {
				if (breakable[j] && dict.find(s.substr(j+1, i-j)) != dict.end() ) {
					breakable[i] = true;
					break;
				}
			}
		}

		return breakable[s.length()-1];
	}
};

int main() {
	string s, longword;
	unordered_set<string> dict;

	cin>>longword;

	while (cin >> s)
		dict.insert(s);

	Solution sol;

	if (sol.wordBreak(longword, dict))
		cout << "pass" << endl;
	else
		cout << "fail" << endl;
	return 0;
}
