#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
	public:
		void merge(int A[], int m, int B[], int n) {
			if (n == 0)
				return;

			int p = 0;

			for (; p<m; p++) {
				if (A[p] > B[0]) {
					int t = A[p];
					A[p] = B[0];
					B[0] = t;

					int q = 0;
					while (q<n-1 && B[q] > B[q+1]) {
						int t = B[q];
						B[q] = B[q+1];
						B[q+1] = t;

						q++;
					}
				}
			}

			for (int i=0; i<n; i++)
				A[p++] = B[i];
		}
};

int main() {
	int m, n;

	cin >> m >> n;

	int *A = new int [m+n];
	int *B = new int [n];

	A[0] = rand() % 2;

	for (int i=1; i<m; i++)
		A[i] = (rand() % 2) + A[i-1];


	B[0] = rand() % 2;
		
	for (int i=1; i<n; i++)
		B[i] = (rand() % 2) + B[i-1];

	for (int i=0; i<m; i++)
		cout << A[i] << ' ';
	cout << endl;

	for (int i=0; i<n; i++)
		cout << B[i] << ' ';
	cout << endl;

	Solution sol;

	sol.merge(A, m, B, n);

	for (int i=0; i<m+n; i++)
		cout << A[i] << ' ';

	cout << endl;

	return 0;
}
