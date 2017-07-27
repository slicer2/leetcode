#include <iostream>
#include <vector>
#include <algorithm>
#include "dan.h"

using namespace std;

class Solution {
	vector<vector<int> > twoSum(vector<int> &num, int start) {
		vector<vector<int> > res;
		int target = num[start-1];

		int i, j;
		int prev = num[start]-1;

		for (i=start, j = num.size()-1; i < j; i++) {
			if (num[i] != prev) {
				while (j > i && num[j] > -target - num[i])
					j--;

				if (j > i && num[j] == -target - num[i])
					res.push_back(vector<int> ({num[i], num[j]}));

				prev = num[i];
			}
		}

		return res;
	}

	public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > res;

		if (num.size() < 3)
			return res;

		sort(num.begin(), num.end());

		//cerr << num << endl;

		int target = num[0]-1;

		for (unsigned i=0; i<num.size()-2; i++) {
			if (num[i] != target) {
				target = num[i];
				vector<vector<int> > partial = twoSum(num, i+1);

				for (auto &x: partial) {
					res.push_back(vector<int> ({num[i]}));
					res.back().insert(res.back().end(), x.begin(), x.end());
				}
			}
		}

		return res;
	}
};

int main() {
	vector<int> num;

	cin >> num;

	Solution sol;

	cout << sol.threeSum(num) << endl;

	return 0;
}
