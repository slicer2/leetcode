#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		int titleToNumber(string s) {
			int n = 0;

			for (auto &x: s)
				n = n*26 + (x-'A'+1);

			return n;
		}
};

int main() {
	string s;
	cin >> s;

	Solution sol;
	cout << sol.titleToNumber(s) << endl;

	return 0;
}
