#include <iostream>
#include <string>
#include <vector>
#include "dan.h"

using namespace std;

string ind("");

class Solution {
	public:
		bool search(vector<int>& nums, int target) {
			int first = 0, last = nums.size()-1;

			while (first <= last) {
				while (first < last && nums[first] == nums[first+1]) first++;
				while (first < last && nums[last] == nums[last-1]) last--;
				if (first == last)
					return (nums[first] == target);

				int mid = (first+last)/2;
				if (nums[mid] == target) return true;

				if (nums[mid] <= nums[last])
					if (target > nums[mid] && target <= nums[last])
						first = mid+1;
					else
						last = mid;
				else
					if (target >= nums[first] && target < nums[mid])
						last = mid;
					else
						first = mid+1;
			}

			return false;
		}
};

int main() {
	vector<int> nums;
	int target;
	cin >> nums >> target;

	Solution sol;

	cout << sol.search(nums, target) << endl;

	return 0;
}
