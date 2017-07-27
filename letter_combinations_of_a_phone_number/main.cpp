#include <iostream>
#include <vector>
#include <string>
#include "dan.h"

using namespace std;

class Solution {
	private:
	vector<vector<string>> dial;
	public:
	vector<string> letterCombinations(string digits) {
		if (digits == "") return vector<string>();
		dial = vector<vector<string>>({{" "}, {"1"}, {"a", "b", "c"}, {"d", "e", "f"},
		{"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}});

		return letterCombinations(digits, digits.size());
	}

	vector<string> letterCombinations(string &digits, int len) {
		if (len == 1) return dial[digits[0]-'0'];

		vector<string> partial = letterCombinations(digits, len-1), res;
		for (auto &x: partial)
			for (auto y: dial[digits[len-1]-'0'])
				res.push_back(x+y);

		return res;
	}
};

int main() {
	string digits;

	cin >> digits;

	Solution sol;

	cout << sol.letterCombinations(digits) << endl;

	return 0;
}
