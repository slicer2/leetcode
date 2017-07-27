#include <iostream>
#include <vector>
#include <algorithm>
#include "dan.h"

using namespace std;

class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			int sz = nums.size();
			vector<vector<int>> res;

			sort(nums.begin(), nums.end());

			for (int p=0; p<sz; p++) {
				if (p > 0 && nums[p] == nums[p-1]) continue;

				for (int q=p+1; q<sz; q++) {
					if (q > p+1 && nums[q] == nums[q-1]) continue;

					int r = q+1, s=sz-1, t = target-nums[p]-nums[q];

					while (r < s) {
						while (r > q+1 && r < s && nums[r] == nums[r-1]) r++;

						if (r < s && nums[r]+nums[s] > t)
							while (r < s && nums[r]+nums[s] > t) s--;
						else
							if (r < s && nums[r]+nums[s] < t)
								while (r < s && nums[r]+nums[s] < t) r++;


						if (r < s && nums[r]+nums[s] == t)
							res.push_back(vector<int>({nums[p], nums[q], nums[r++], nums[s--]}));
					}
				}
			}

			return res;
		}
};

int main() {
	int target;
	vector<int> num;

	cin >> target;
	cin.ignore(100, '\n');

	cin >> num;

	Solution sol;
	cout << sol.fourSum(num, target) << endl;

	return 0;
}
