#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "dan.h"

using namespace std;

class Solution {
	public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> partial;
		vector<string> res;
		bt(partial, 0, s, 0, res);
		return res;
	}

	void bt(vector<string> &partial, int posPartial, string &s, int posS, vector<string> &res) {
		if (posPartial > 0 && (stoi(partial[posPartial-1]) > 255 || (partial[posPartial-1].size() > 1 && partial[posPartial-1][0] == '0'))) return;
		if (posPartial == 4) {
			if (posS == s.size())
				res.push_back(partial[0]+"."+partial[1]+"."+partial[2]+"."+partial[3]);

			return;
		}

		for (int i=0; i<min(3, (int)s.size()-posS); i++) {
			partial.push_back(s.substr(posS, i+1));
			bt(partial, posPartial+1, s, posS+i+1, res);
			partial.pop_back();
		}
	}
};

int main() {
	string s;

	cin >> s;

	Solution sol;

	cout << sol.restoreIpAddresses(s) << endl;

	return 0;
}
