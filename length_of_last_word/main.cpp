#include <iostream>
#include <string>

using namespace std;

class Solution {
	void stripSpace(const char *s, int &p) {
		while (s[p] == ' ')
			p++;
	}

	string stripWord(const char *s, int &p) {
		string res("");

		while (s[p] != ' ' && s[p] != '\0')
			res += s[p++];

		return res;
	}

	public:
		int lengthOfLastWord(const char *s) {
			int p = 0;
			string word("");

			stripSpace(s, p);

			while (s[p] != '\0') {
				word = stripWord(s, p);
				stripSpace(s, p);
			}

			return word.length();
		}
};

int main() {
	string s;

	getline(cin , s);

	Solution sol;

	cout << sol.lengthOfLastWord(s.c_str()) << endl;

	return 0;
}
