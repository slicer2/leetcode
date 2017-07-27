#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {

	public:

		int lengthOfLongestSubstring(string s) {
			if (s.empty())
				return 0;

			unsigned p = 0;
			unsigned longest = 0;
			unordered_map<char, unsigned> charMap;
			charMap[s[0]] = 0;

			for (unsigned q=1; q < s.length(); q++) {
				if (charMap.find(s[q]) != charMap.end()) {
					if (longest < q-p)
						longest = q-p;

					unsigned end = charMap[s[q]];
					for (unsigned i=p; i<=end; i++)
						charMap.erase(s[i]);

					p = end+1;
				}

				charMap[s[q]] = q;
			}

			if (longest < s.length()-p)
				longest = s.length()-p;

			return longest;
		}

};

int main() {
	string s;
	cin >> s;
	cout << s << endl;

	Solution sol;
	cout << sol.lengthOfLongestSubstring(s) << endl;

	return 0;
}
