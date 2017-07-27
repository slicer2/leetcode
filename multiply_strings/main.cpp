#include <iostream>
#include <string>
#include "dan.h"

using namespace std;

class Solution {
	string mult(const string & num, char n) {
		int multiplicant = n - '0';

		int carry = 0;
		string res(num.length()+1, '0');

		int i;
		for (i=0; i<(int)num.length(); i++) {
			int prod = (num[num.length()-1-i]-'0') * multiplicant + carry;
			//cerr << "digit x digit = " << prod << endl;

			res[res.length()-1-i] = (char)(prod % 10 + '0');
			carry = prod / 10;
		}

		if (carry > 0)
			res[res.length()-1-i] = (char)(carry + '0');


		return res;
	}

	void add(string &a1, const string &a2, int off) {
		int carry = 0;
		int i;
		//cerr << "a1 length = " << a1.length() << "   a2 length = " << a2.length() << endl;
		//cerr << "a1 = " << a1 << "   " << "a2 = " << a2 << endl;
		//cerr << "off = " << off << endl;

		for (i=0; i<(int)a2.length(); i++) {
			int sum = (a1[a1.length()-1-off-i] - '0') + (a2[a2.length()-1-i] - '0') + carry;
			//cerr << "sum = " << sum << endl;
			//cerr << "add + add = " << a1[a1.length()-1-off-i] - '0' << "   " << a2[a2.length()-1-i] - '0' << endl;

			a1[a1.length()-1-off-i] = (char)(sum % 10 + '0');
			carry = sum / 10;
		}

		while (carry > 0) {
			int sum = (a1[a1.length()-1-off-i] - '0') + carry;
			if (a1.length()-1-off-i >= 0)
				a1[a1.length()-1-off-i] = (char)(sum % 10 + '0');
			carry = sum / 10;
			i++;
		}

	}
	public:
	string multiply(string num1, string num2) {
		string result(num1.length() + num2.length(), '0');

		for (int i=num2.length()-1; i>=0; i--) {
			string temp = mult(num1, num2[i]);
			//cerr << "temp = " << temp << endl;

			add(result, temp, num2.length() -1 - i);
		}

		int i=0;
		while (result[i] == '0') i++;

		if (i == (int)result.length())
			return string(1, '0');
		else
			return result.substr(i, result.length()-i);
	}
};

int main() {
	string num1, num2;
	cin >> num1 >> num2;

	Solution sol;
	cout << sol.multiply(num1, num2) << endl;

	return 0;
}
