#include <iostream>
#include <vector>
#include <limits>
#include "dan.h"

using namespace std;

class Solution {
	int max(int a, int b) {
		return ((a>b)?a:b);
	}

	int maxGap(vector<int> &num, int lb, int ub, int &maxVal, int &minVal) {
		if ( (ub == lb && !num.empty()) || num.size() == 1) {
			maxVal = num[0];
			minVal = num[0];
			return 0;
		}

		int mid = lb + (ub-lb)/2;

		int maxLeft, maxRight;
		int minLeft, minRight;
		int maxGapLeft, maxGapRight;

		vector<int> left, right;

		for (auto &x: num) {
			if (x <= mid)
				left.push_back(x);
			else
				right.push_back(x);
		}

		if (!left.empty()) {
			if (!right.empty()) {
				maxGapLeft = maxGap(left, lb, mid, maxLeft, minLeft);
				maxGapRight = maxGap(right, mid+1, ub, maxRight, minRight);

				maxVal = maxRight;
				minVal = minLeft;
				return max(max(maxGapLeft, maxGapRight), minRight - maxLeft);
			}
			else {
				maxGapLeft = maxGap(left, lb, mid, maxLeft, minLeft);
				maxVal = maxLeft;
				minVal = minLeft;

				return maxGapLeft;
			}
		}
		else {
			maxGapRight = maxGap(right, mid+1, ub, maxRight, minRight);
			maxVal = maxRight;
			minVal = minRight;

			return maxGapRight;
		}
	}

	public:
	int maximumGap(vector<int> &num) {
		if (num.size() < 2)
			return 0;

		int dummy;

		return maxGap(num, 0, numeric_limits<int>::max(), dummy, dummy);
	}
};

int main() {
	vector<int> num;
	cin >> num;

	Solution sol;
	cout << sol.maximumGap(num) << endl;

	return 0;
}
