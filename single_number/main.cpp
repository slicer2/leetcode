#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
	public:
		int singleNumber(int A[], int n) {
			int result;

			for (int i=0; i<n; i++)
				result ^= A[i];

			return result;
		}
};


int main() {
	int n;

	cin >> n;

	int *a = new int[n];

	int num;

	for (int i=0; i<n; i++)
		cin >> a[i];

	Solution s;

	cout << s.singleNumber(a, n) << endl;
}
