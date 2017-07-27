#include <iostream>
#include <vector>
#include <numeric>
#include "dan.h"

using namespace std;


class Solution {
	public:
	int minCut(string str) {
		int sz = str.size(), l, r;
		vector<int> cut(sz+1);
		iota(cut.rbegin(), cut.rend(), 0);
		for (int i=sz-1; i>=0; i--) {
			for (l=i, r=i; l>=0 && r<sz && str[l]==str[r]; l--, r++)
				cut[l] = min(cut[l], cut[r+1]+1);
			for (l=i, r=i+1; l>=0 && r<sz && str[l] == str[r]; l--, r++)
				cut[l] = min(cut[l], cut[r+1]+1);
		}

		return cut[0]-1;
	}
};

int main() {
	string s;

	cin >> s;

	Solution sol;

	cout << sol.minCut(s) << endl;

	return 0;
}
