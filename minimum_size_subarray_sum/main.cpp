#include <iostream>
#include <vector>
#include <string>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int minSubArrayLen(int s, vector<int>& nums) {
			int sz = nums.size(), p = 0, q = 0;
			if (sz == 0) return 0;
			int sum = nums[0], len = sz+1;

			while (true) {
				if (sum >= s) {
					len = min(len, q-p+1);
					sum -= nums[p++];
				}
				else
					if (q+1<sz)
						sum += nums[++q];
					else break;
			}

			return (len==sz+1)?0:len;
		}
};

int main() {
	vector<int> nums;
	int s;
	cin >> s;

	string dummy;
	getline(cin , dummy);

	cin >> nums;

	Solution sol;
	cout << sol.minSubArrayLen(s, nums) << endl;

	return 0;
}
