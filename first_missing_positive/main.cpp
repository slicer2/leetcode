#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int firstMissingPositive(vector<int>& nums) {
			int sz = nums.size();
			for (int i=0; i<sz; i++) {
				int p = nums[i];
				while(p-1>=0 && p-1<sz && nums[p-1] != p) {
					int tmp = nums[p-1];
					nums[p-1] = p;
					p = tmp;
				}
			}

			for (int i=0; i<sz; i++)
				if (nums[i] != i+1) return i+1;

			return sz+1;
		}
};

int main() {
	vector<int> nums;
	cin >> nums;

	Solution sol;

	cout << sol.firstMissingPositive(nums) << endl;
}
