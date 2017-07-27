#include <vector>
#include <iostream>
#include "dan.h"

using namespace std;

class Solution {
	int searchInsert(int A[], int n, int target) {
		if (n == 0)
			return 0;

		if (target <= A[0])
			return 0;

		if (target > A[n-1])
			return n;

		int start = 0, end = n-1;

		while (start + 1 < end) {
			int mid = (start+end)/2;
			if (A[mid] >= target)
				end = mid;
			else
				start = mid;
		}

			return end;
	}
	public:
	vector<int> searchRange(int A[], int n, int target) {
		int start = searchInsert(A, n, target);

		if (n > 0 && start < n && A[start] == target)
			return vector<int>({start, searchInsert(A, n, target+1)-1});
		else
			return vector<int>(2, -1);
	}
};

int main() {
	int *A = new int [1000];

	int target;

	int p = 0;

	cin >> target;

	while (cin >> A[p])
		p++;

	cout << "p = " << p << endl;

	Solution sol;

	cout << sol.searchRange(A, p, target) << endl;

	return 0;
}
