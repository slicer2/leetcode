#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			int sz = nums.size();
			sort(nums.begin(), nums.end());

			int csum = nums[0]+nums[1]+nums[sz-1], closest = abs(csum-target);
			for (int p=0; p<sz; p++) {
				if (p > 0 && nums[p] == nums[p-1]) continue;

				int q = p+1, r = sz-1;
				if (q<r && closest > abs(nums[p]+nums[q]+nums[r]-target)) {
					csum = nums[p]+nums[q]+nums[r];
					closest = abs(csum-target);
				}

				while (q < r) {
					if (nums[p]+nums[q]+nums[r]-target>0) {
						while (q<r && nums[p]+nums[q]+nums[r]-target > 0) r--;
						if (closest > abs(nums[p]+nums[q]+nums[r+1]-target)) {
							csum = nums[p]+nums[q]+nums[r+1];
							closest = abs(csum-target);
						}
					}
					else {
						while (q<r && nums[p]+nums[q]+nums[r]-target <= 0) q++;
						if (closest > abs(nums[p]+nums[q-1]+nums[r]-target)) {
							csum = nums[p]+nums[q-1]+nums[r];
							closest = abs(csum-target);
						}
					}
				}
			}

			return csum;
		}
};

int main() {
	vector<int> num;
	int target;

	cin >> target;
	cin.ignore(100,'\n');

	cin >> num;

	cout << target << endl << num << endl;

	Solution sol;

	cout << sol.threeSumClosest(num, target) << endl;

	return 0;
}
