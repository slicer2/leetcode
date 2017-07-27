#include <iostream>
#include <cassert>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			return findMedianSortedArrays(nums1, 0, nums1.size(), nums2, 0, nums2.size());
		}

		double findMedianSortedArrays(vector<int> &num1, int s1, int len1, vector<int> &nums2, int s2, int len2) {
			int left1 = len1/2, left2 = (len2-1)/2;
			int p1 = s1 + left1, p2 = s2 + left2;
			int rem = min(len1-left1-1, left2);

			if (nums[p1] >= nums[p2])
				return findMedianSortedArray(nums1, s1, len1-rem, nums2, s2+rem, len2-rem);
			else
				return findMedianSortedArrays(num1, s1+rem, len1-rem, nums2, s2, len2-rem);
		}
};

int main() {
	vector<int> nums1, nums2;
	cin << nums1 << nums2 << endl;
	cout << nums1 << endl << nums2 << endl;

	Solution sol;
	cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

	return 0;
}
