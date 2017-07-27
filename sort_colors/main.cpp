#include <iostream>
#include "dan.h"

using namespace std;

class Solution {
	public:
		void sortColors(vector<int> &nums) {
			int p = 0, q = 1, pivot, sz = nums.size(), r = sz-1;
			while (p < sz && nums[p] == 2) p++;
			if (p == sz) return;
			swap(nums[0], nums[p]);
			pivot = nums[p = 0];
			while (q <= r)
				if (nums[q] == 0) nums[p++] = nums[q++];
				else if (nums[q] == 2) swap(nums[r--], nums[q]);
				else q++;

			nums[p++] = pivot;
			while (p < q) nums[p++] = 1;
		}
};

int main() {
	vector<int> nums;
	cin >> nums;

	Solution sol;
	sol.sortColors(nums);
	cout << nums << endl;
	return 0;
}
