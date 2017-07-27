#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	public:
		int numDecodings(string s) {
			int sz = s.size();
			if (!sz) return 0;
			vector<int> ways(sz+1, 0);
			ways[0] = 1;
			for (int i=0; i<sz+1; i++) {
				if (i < sz && s[i] != '0') ways[i+1] += ways[i];
				if (i+1 < sz && s.substr(i, 2) >= "10" && s.substr(i, 2) <= "26") ways[i+2] += ways[i];
			}

			return ways[sz];
		}
};

int main() {
	string s;

	cin >> s;

	Solution sol;

	cout << sol.numDecodings(s) << endl;

	return 0;
}
