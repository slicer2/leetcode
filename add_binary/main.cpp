#include <iostream>
#include <string>
#include <stack>
#include "dan.h"

using namespace std;

class Solution {
	char add(char b1, char b2, char &carryOver){
		carryOver = '0';

		if (b1 == b2) {
			if (b1 == '1')
				carryOver = '1';

			return '0';
		}
		else
			return '1';
	}

	public:
	string addBinary(string a, string b) {
		string::reverse_iterator ra_it = a.rbegin();
		string::reverse_iterator rb_it = b.rbegin();
		stack<char> sta;

		char carryOver = '0';

		while (ra_it != a.rend() || rb_it != b.rend()) {
			if (ra_it == a.rend()) {
				sta.push(add((*rb_it), carryOver, carryOver));

				rb_it++;
			}
			else
				if (rb_it == b.rend()) {
					sta.push(add((*ra_it), carryOver, carryOver));

					ra_it++;
				}
				else {
					char tc;
					char t = add((*ra_it), (*rb_it), tc);
					sta.push(add(t, carryOver, carryOver));
					carryOver = add(carryOver, tc, tc);

					ra_it++;
					rb_it++;
				}
		}

		if (carryOver == '1')
			sta.push(carryOver);

		string result("");
		while (!sta.empty()) {
			result += sta.top();
			sta.pop();
		}

		return result;
	}
};

int main() {
	string a, b;

	cin >> a >> b;

	Solution sol;

	cout << sol.addBinary(a, b) << endl;

	return 0;
}
