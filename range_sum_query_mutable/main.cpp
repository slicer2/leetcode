#include <iostream>
#include <vector>
#include <cassert>
#include "dan.h"

using namespace std;



class NumArray {
	public:
		vector<int> arr;
		vector<int> bit;

		int cum(int i) {
			int res = 0;
			i++;

			while (i) {
				res += bit[i];
				i -= (i & -i);
			}

			return res;
		}

	public:
		NumArray(vector<int> &nums) {
			arr.resize(nums.size(), 0);
			bit.resize(arr.size() + 1, 0);

			for (int i=0; i<arr.size(); i++)
				update(i, nums[i]);

			//cerr << bit << endl;
		}

		void update(int i, int val) {
			int delta = val - arr[i];
			arr[i] = val;

			i++;

			while (i < bit.size()) {
				bit[i] += delta;
				i += (i & -i);
			}
		}

		int sumRange(int i, int j) {
			return cum(j) - cum(i-1);
		}
};

int main() {
	vector<int> nums;
	cin >> nums;

	NumArray na(nums);


	cout << na.sumRange(2, 5) << endl;
	na.update(3, 5);
	cout << na.sumRange(2, 5) << endl;
	return 0;
}
