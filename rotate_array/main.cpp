/**
 * rotate an array to the right by k steps
 */
 
#include <iostream>
using namespace std;

class Solution {
	void fliplr(int nums[], int start, int len) {
		for (int i=start, j=start+len-1; i<j; i++, j--) {
			int t = nums[i];
			nums[i] = nums[j];
			nums[j] = t;
		}
	}

	public:
		void rotate(int nums[], int n, int k) {
			k %= n;
			fliplr(nums, 0, n-k);
			fliplr(nums, n-k, k);
			fliplr(nums, 0, n);
		}
};

int main() {
	int n, k, *num;
	cin >> n >> k;

	num = new int [n];

	for (int i=0; i<n; i++)
		cin >> num[i];

	Solution sol;

	sol.rotate(num, n, k);

	for (int i=0; i<n; i++)
		cout << num[i] << ' ';

	cout << endl;
}
