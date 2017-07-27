#include <iostream>
#include <vector>
#include "dan.h"
#include <unordered_set>

#include <algorithm>
using namespace std;

class Solution {
	public:
		void permutateUnique(vector<int>& nums, int start, vector<vector<int> >& res) {
			if (start == nums.size()) {
				res.push_back(nums);
				return;
			}
			unordered_set<int> st;
			for (int i = start; i < nums.size(); i++) {
				if (st.find(nums[i]) != st.end()) continue;
				st.insert(nums[i]);
				swap(nums[i], nums[start]);
				permutateUnique(nums, start + 1, res);
				swap(nums[i], nums[start]);
			}
		}

		vector<vector<int> > permuteUnique(vector<int>& nums) {
			vector<vector<int> > res;
			permutateUnique(nums, 0, res);
			return res;
		}
};

int main() {
	vector<int> num;
	cin >> num;

	Solution sol;

	cout << sol.permuteUnique(num) << endl;

	return 0;
}
