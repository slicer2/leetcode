#include <iostream>
#include <vector>
#include <stack>
#include "dan.h"

using namespace std;

class Solution {
	public:
		vector<int> plusOne(vector<int> &digits) {
			if (digits.empty())
				return digits;

			stack<int> sta;
			vector<int> result;

			vector<int>::reverse_iterator r_it = digits.rbegin();
			int carryOver = 1;

			for (; r_it != digits.rend(); r_it++) {
				if ((*r_it) + carryOver > 9)
					sta.push(0);
				else {
					sta.push((*r_it) + carryOver);
					carryOver = 0;
				}
			}
			
			if (carryOver)
				result.push_back(1);

			while (!sta.empty()) {
				result.push_back(sta.top());
				sta.pop();
			}

			return result;
		}
};

int main() {
	vector<int> digits;

	int n;

	while (cin >> n)
		digits.push_back(n);

	Solution sol;

	cout << sol.plusOne(digits) << endl;

	return 0;
}
