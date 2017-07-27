#include <iostream>
#include <vector>
#include <string>
#include "dan.h"

using namespace std;

class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			vector<string> res;
			string partial;

			generateParenthesis(res, partial, n, n);

			return res;
		}

		void generateParenthesis(vector<string> &res, string &partial, int left, int right) {
			if (left + right == 0) {
				res.push_back(partial);
				return;
			}

			if (left > 0) {
				partial.push_back('(');
				generateParenthesis(res, partial, left-1, right);
				partial.pop_back();
			}

			if (right > left) {
				partial.push_back(')');
				generateParenthesis(res, partial, left, right-1);
				partial.pop_back();
			}
		}
};

int main() {
	int n;
	cin >> n;

	Solution sol;

	cout << sol.generateParenthesis(n) << endl;

	return 0;
}
