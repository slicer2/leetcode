#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

class Solution {
	bool match (stack<char> &sta, char x) {
		if (!sta.empty() && ((sta.top() == '(' && x == ')') || (sta.top() == '[' && x == ']') || (sta.top() == '{' && x == '}')))
			return true;
		else
			return false;
	}

	public:
		bool isValid(string s) {
			stack<char> sta;

			for (auto &x: s) {
				switch (x) {
					case '(':
					case '[':
					case '{':
						sta.push(x);
						break;

					default:
						if (match(sta, x))
							sta.pop();
						else
							return false;
				}
			}

			return sta.empty();
		}
};

int main() {
	string s;
	cin >> s;
	cout << s << endl;

	Solution sol;
	cout << sol.isValid(s) << endl;

	return 0;
}
