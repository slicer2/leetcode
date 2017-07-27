#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include "dan.h"

using namespace std;

class Solution {
	private:
	void dfs(vector<int> &partial, int psum, vector<int> &candidates, int q, int target, vector<vector<int>> &res) {
		if (psum > target) return;

		if (psum == target) {
			res.push_back(partial);
			return;
		}

		int sz = candidates.size();
		for (int i=q; i<sz; i++) {
			partial.push_back(candidates[i]);
			psum += candidates[i];
			dfs(partial, psum, candidates, i, target, res);
			psum -= candidates[i];
			partial.pop_back();
		}
	}

	public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>> res;
		vector<int> partial;
		int psum = 0;
		sort(candidates.begin(), candidates.end());
		int q = 0;

		dfs(partial, psum, candidates, q, target, res);

		return res;
	}
};

int main() {
	int target;
	vector<int> candidates;
	cin >> target;
	cin.ignore(100, '\n');
	cin >> candidates;

	Solution sol;
	cout << sol.combinationSum(candidates, target) << endl;

	return 0;
}
