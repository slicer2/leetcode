/**
 * OJ's valid number:
 *   number := zero or more spaces + zero or one sign char + (.+one or more digits | one or more digits + . + zero or more digits) \
 *             + zero or more (e or E + zero or more sign char + one or more digits) + zero or more spaces
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
	bool stripSpace(const char *s, int &p, int &nChar) {
		nChar = 0;

		while (s[p] == ' ' || s[0] == '\t' || s[0] == '\r') {
			p++;
			nChar++;
		}

		if (nChar > 0)
			return true;
		else
			return false;
	}

	bool stripPlusMinus(const char *s, int &p, int &nChar) {
		nChar = 0;

		if (s[p] == '+' || s[p] == '-') {
			nChar = 1;
			p++;
		}

		if (nChar > 0)
			return true;
		else
			return false;
	}

	bool stripDigits(const char *s, int &p, int &nChar) {
		nChar = 0;

		while (s[p] >= '0' && s[p] <= '9') {
			nChar++;
			p++;
		}

		if (nChar > 0)
			return true;
		else
			return false;
	}

	bool stripFrac(const char *s, int &p, int &nChar) {
		nChar = 0;

		if (s[p] == '.') {
			p++;
			nChar++;

			while (s[p] >= '0' && s[p] <= '9') {
				p++;
				nChar++;
			}
		}

		if (nChar > 0) // saw '.'
			return true;
		else
			return false;
	}

	bool stripExp(const char *s, int &p, int &nChar) {
		nChar = 0;

		if (s[p] == 'e' || s[p] == 'E') {
			p++;
			nChar++;

			int n;
			stripPlusMinus(s, p, n);
			nChar += n;

			stripDigits(s, p, n);
			nChar += n;

			if (n == 0)
				return false;
			else
				return true;
		}
		else
			return true;
	}

	public:
		bool isNumber(const char *s) {
			if (s[0] == '\0')
				return false;

			int nChar;

			int p = 0;

			stripSpace(s, p, nChar);

			//cerr << "stripSpace  p = " << p << "  nChar = " << nChar << "  s[p] = " << ((s[p] == '\0')?'#':s[p]) << endl;

			stripPlusMinus(s, p, nChar);

			//cerr << "stripPlusMinus  p = " << p << "  nChar = " << nChar << "  s[p] = " << ((s[p] == '\0')?'#':s[p]) << endl;

			stripDigits(s, p, nChar);
			
			//cerr << "stripDigits  p = " << p << "  nChar = " << nChar << "  s[p] = " << ((s[p] == '\0')?'#':s[p]) << endl;

			if (nChar == 0) {
				stripFrac(s, p, nChar);

				if (nChar < 2)
					return false;
			}
			else
				stripFrac(s, p, nChar);
			
			//cerr << "stripFrac  p = " << p << "  nChar = " << nChar << "  s[p] = " << ((s[p] == '\0')?'#':s[p]) << endl;

			if (!stripExp(s, p, nChar))
				return false;

			//cerr << "stripExp  p = " << p << "  nChar = " << nChar << "  s[p] = " << ((s[p] == '\0')?'#':s[p]) << endl;

			stripSpace(s, p, nChar);

			//cerr << "stripSpace  p = " << p << "  nChar = " << nChar << "  s[p] = " << ((s[p] == '\0')?'#':s[p]) << endl;

			if (s[p] != '\0')
				return false;
			else
				return true;
		}
};

int main() {
	string str;

	getline(cin, str);

	cout << "str = " << str << endl;

	Solution sol;

	cout << ((sol.isNumber(str.c_str()))? "yes":"no") << endl;

	return 0;
}
