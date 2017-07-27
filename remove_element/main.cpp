#include <iostream>

using namespace std;

class Solution {
	public:
		int removeElement(int A[], int n, int elem) {
			int p = 0, q = 0;

			while (q < n) {
				if (A[q] != elem) {
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

	int n=0, elem;

	cin >> elem;

	while (cin >> A[n]) n++;

	Solution sol;

	n = sol.removeElement(A, n, elem);

	cout << n << endl;

	for (int i=0; i<n; i++)
		cout << A[i] << ' ';

	cout << endl;

	return 0;
}
