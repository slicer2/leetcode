#include <iostream>
#include <vector>
#include "dan.h"

#include <algorithm>
using namespace std;

class Solution {

	public:

	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int>> res;
		if (num.empty()) return res;
		permute(num, res, 0);
		return res;
	}

	void permute(vector<int> &num, vector<vector<int>> &res, int start) {
		int sz = num.size();
		if (start + 1 == sz) res.push_back(num);
		vector<int> num0 = num;
		for (int i=start; i<sz; i++) {
			num = num0;
			swap(num[start], num[i]);
			permute(num, res, start+1);
		}
	}

};

int main() {
	vector<int> num;
	cin >> num;

	Solution sol;

	cout << sol.permute(num) << endl;

	return 0;
}
