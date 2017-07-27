#include <iostream>

using namespace std;

class Solution {
	public:
		int removeDuplicates(int A[], int n) {
			if (n == 0)
				return 0;

			int p = 0, q = 0;
			int prev = A[0]-1;
			int prevCnt = 1;

			while (q < n) {
				if (A[q] == prev) {
					prevCnt++;

					if (prevCnt == 2)
						A[p++] = A[q++];
					else
						q++;
				}
				else {
					prev = A[q];
					prevCnt = 1;
					A[p++] = A[q++];
				}
			}

			return p;
		}
};

int main() {
	int A[100];
	int n = 0;

	while (cin >> A[n++]);

	n--;

	cout << n << endl;

	for (int i=0; i<n; i++)
		cout << A[i] << ' ';

	cout << endl;

	Solution sol;

	n = sol.removeDuplicates(A, n);

	cout << n << endl;

	for (int i=0; i<n; i++)
		cout << A[i] << ' ';

	cout << endl;

	return 0;
}
