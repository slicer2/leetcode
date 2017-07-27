#include <iostream>
#include <vector>
#include <string> 
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		string longestCommonPrefix(vector<string> &strs) {
			if (strs.empty())
				return string("");

			unsigned i=0-1;

			while (true) {
				i++;
				if (strs[0].length() < i+1)
					return strs[0].substr(0, i);

				for (unsigned j=1; j<strs.size(); j++) {
					if (strs[j].length() < i+1 || strs[j][i] != strs[0][i])
						return strs[j].substr(0, i);
				}
			}
		}
};

int main() {
	string s;
	vector<string> strs;

	while (cin >> s)
		strs.push_back(s);

	Solution sol;

	cout << sol.longestCommonPrefix(strs) << endl;

	return 0;
}
