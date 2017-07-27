#include <iostream>

using namespace std;

class Solution {
	public:
		int removeDuplicates(int A[], int n) {
			if (n == 0)
				return 0;

			int p = 1, q = 1;
			int prev = A[0];

			while (q < n) {
				if (A[q] != prev) {
					prev = A[q];
					A[p] = A[q];
					p++;
				}

				q++;
			}

			return p;
		}
};

int main() {
	int A[100];
	int n = 0;

	while (cin >> A[n]) n++;

	Solution sol;

	n = sol.removeDuplicates(A, n);

	cout << n << endl;

	for (int i=0; i<n; i++)
		cout << A[i] << ' ';

	cout << endl;

	return 0;
}
