#include <iostream>
#include <vector>
#include <algorithm>
#include "dan.h"

using namespace std;


class Solution {
	private:
		static bool sortNumsi(const pair<int, int> &p1, const pair<int, int> &p2) {
			return p1.first < p2.first;
		}

	public:
		vector<int> countSmaller(vector<int>& nums) {
			int sz = nums.size();
			vector<int> res(sz, 0), bitidx(sz, 1);

			if (nums.empty()) return res;

			vector<pair<int, int>> numsi(sz);
			for (int i=0; i<sz; i++) numsi[i] = make_pair(nums[i], i);

			sort(numsi.begin(), numsi.end(), sortNumsi);


			for (int i=1; i<sz; i++)
				if (numsi[i].first == numsi[i-1].first)
					bitidx[numsi[i].second] = bitidx[numsi[i-1].second];
				else
					bitidx[numsi[i].second] = bitidx[numsi[i-1].second]+1;

			int maxidx = bitidx[numsi.back().second];
			vector<int> bit(maxidx+1, 0);

			for (int i = sz-1; i>=0; i--) {
				int p = bitidx[i]-1, sum = 0;
				while (p) {
					sum += bit[p];
					p -= (p & -p);
				}

				res[i] = sum;
				
				p = bitidx[i];
				while (p <= maxidx) {
					bit[p]++;
					p += (p & -p);
				}
			}

			return res;
		}
};

int main() {
	vector<int> nums;
	cin >> nums;

	Solution sol;
	cout << sol.countSmaller(nums) << endl;
	return 0;
}
