#include <iostream>
#include <string>

using namespace std;

class Solution {
	string translateDigit(int n, char L, char M, char S) {
		if (n == 0)
			return string("");

		if (1 <= n && n <= 3)
			return string(n, S);

		if (4 == n)
			return string({S, M});

		if (5 <= n && n <= 8)
			return M+string(n-5, S);

		return string({S, L});
	}

	public:
	string intToRoman(int num) {
		string s;

		s += translateDigit(num / 1000, 'Y', 'Z', 'M');
		num %= 1000;

		s += translateDigit(num / 100, 'M', 'D', 'C');
		num %= 100;

		s += translateDigit(num / 10, 'C', 'L', 'X');
		num %= 10;

		s += translateDigit(num, 'X', 'V', 'I');

		return s;
	}
};

int main() {
	int num;

	cin >> num;

	Solution sol;

	cout << sol.intToRoman(num) << endl;


	return 0;
}
