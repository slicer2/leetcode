#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		string countAndSay(int n) {
			string s("1");
			string t;

			if (n == 1)
				return s;

			for (int i=2; i<=n; i++) {
				char currCh = s[0];
				int currCount = 1;
				t = "";

				for (int i=1; i<(int)s.length(); i++) {
					if (s[i] == currCh)
						currCount ++;
					else {
						t = t + to_string(currCount) + currCh;
						currCh = s[i];
						currCount = 1;
					}
				}

				s = t + to_string(currCount) + currCh;
			}

			return s;
		}
};

int main() {
	int n;
	cin >> n;
	Solution sol;
	cout << sol.countAndSay(n) << endl;

	return 0;
}
