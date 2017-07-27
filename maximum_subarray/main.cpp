#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int maxSubArray(int A[], int n) {

			int p = 1;
			int maxSum = A[0], maxRightSum = A[0];

			while (p < n) {
				if (maxRightSum >= 0)
					maxRightSum += A[p];
				else
					maxRightSum = A[p];

				if (maxSum < maxRightSum)
					maxSum = maxRightSum;

				p++;
			}

			return maxSum;
		}
};

int main() {
	vector<int> arr;
	int n;

	while (cin >> n) {
		arr.push_back(n);
	}

	n = arr.size();

	int *A = new int [n];

	for (int i=0; i<n; i++)
		A[i] = arr[i];

	Solution sol;

	cout << sol.maxSubArray(A, n) << endl;

	return 0;
}
