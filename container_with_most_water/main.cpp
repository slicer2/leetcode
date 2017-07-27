#include <iostream>
#include <vector>
#include <algorithm>
#include "dan.h"

using namespace std;

class Solution {
	public:

		int maxArea(vector<int> &height) {
			int p = 0, q = height.size()-1, maxA = (q-p)*min(height[p], height[q]), h0;

			while (p < q) {
				if (height[p] < height[q]) {
					h0 = height[p];
					while (p < q && height[p] <= h0) p++;
				}
				else {
					h0 = height[q];
					while (p < q && height[q] <= h0) q--;
				}

				maxA = max(maxA, (q-p)*min(height[p], height[q]));
			}

			return maxA;
		}

};

int main() {
	vector<int> height;
	cin >> height;

	Solution sol;

	cout << sol.maxArea(height) << endl;

	return 0;
}
