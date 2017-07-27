#include <iostream>
#include <climits>
#include <string>
#include "dan.h"

using namespace std;

class Solution {
	int stripLeading0(string &s, int p) {
		while (s[p] == ' ' || s[p] == '\t' || s[p] == '\n')
			p++;

		return p;
	}

	int stripSign(string &s, int p, char &sign) {
		switch (s[p]) {
			case '-':
				sign = '-';
				p++;
				break;

			case '+':
				sign = '+';
				p++;
				break;

			default:
				sign = '+';
		}

		return p;
	}

	int stripNum(string &s, int p, int &num, char sign) {
		int q;

		while ( s[p] >= '0' && s[p] <= '9') {
			q = (sign=='+')?(int)(s[p] - '0'):-(int)(s[p]-'0');

			if (sign == '+') {

				if (num > (INT_MAX-q)/10) {
					num = INT_MAX;
					return p;
				}
				else {
					num *= 10;
					num += q;
					p++;
				}
			}
			else {
				if (num < (INT_MIN-q)/10) {
					num = INT_MIN;
					return p;
				}
				else {
					num *= 10;
					num += q;
					p++;
				}
			}
		}

		return p;
	}

	public:
	int atoi(string str) {
		int p = 0;
		int num = 0;
		char sign;

		p = stripLeading0(str, p);

		p = stripSign(str, p, sign);

		if(p == stripNum(str, p, num, sign))
			return 0;

		return num;
	}
};

int main() {
	cout << INT_MAX << '\t' << INT_MIN << endl;

	string A;

	cin >> A;

	Solution sol;

	cout << sol.atoi(A) << endl;

	return 0;
}
