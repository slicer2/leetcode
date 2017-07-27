#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;


class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			if (nums.empty()) return 0;
			int term = nums.size();
			if (target > nums.back()) return term;

			int start = 0;
			term--;

			while (start < term) {
				int mid = (start+term)/2;
				if (nums[mid] == target)
					return mid;

				if (nums[mid] < target)
					start = mid+1;
				else
					term = mid;
			}

			return start;
		}
};

int main() {
	vector<int> nums;
	int target;
	cin >> nums >> target;

	Solution sol;
	cout << sol.searchInsert(nums, target);
	return 0;
}
