#include <iostream>
#include <vector>

#include "dan.h"

using namespace std;

class Solution {
	public:
	vector<vector<int>> factorCombinations(int n) {
		return factorCombinations(n, 2, n);
	}

	vector<vector<int>> factorCombinations(int n, int start, int largest) {
		vector<vector<int>> res;

		for (int i=start; i*i <= n; i++) {
			if (n % i == 0) {
				vector<vector<int>> tmp = factorCombinations(n/i, i, largest);

				for (auto &x: tmp) {
					res.push_back(vector<int>({i}));
					for (auto y: x)
						res.back().push_back(y);
				}
			}
		}

		if (n < largest) res.push_back(vector<int>{n});
		return res;
	}
};

int main() {
	int n;
	cin >> n;

	Solution sol;
	cout << sol.factorCombinations(n) << endl;

	return 0;
}
