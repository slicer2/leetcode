#include <iostream>

using namespace std;

class Solution {

	int readRomanDigit(string &s, char L, char M, char S) {
		int p = 0;
		int n = 0;

		if (s[p] == S) {
			n = 1;
			p++;

			while (s[p] == S) {
				n++;
				p++;
			}

			if (s[p] == M) {
				n = 4;
				p++;
			}
			else {
				if (s[p] == L) {
					n = 9;
					p++;
				}
			}
		}
		else {
			if (s[p] == M) {
				n = 5;
				p++;

				while (s[p] == S) {
					n++;
					p++;
				}
			}
		}

		s = s.substr(p, string::npos);

		return n;
	}

	public:
		int romanToInt(string s) {
			int n = 1000 * readRomanDigit(s, 'Y', 'Z', 'M');
			
			n += 100 * readRomanDigit(s, 'M', 'D', 'C');

			n += 10 * readRomanDigit(s, 'C', 'L', 'X');

			n += 1 * readRomanDigit(s, 'X', 'V', 'I');

			return n;
		}
};

int main() {
	string s;
	cin >> s;

	Solution sol;
	cout << sol.romanToInt(s) << endl;

	return 0;
}
