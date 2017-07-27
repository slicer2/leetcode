#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int jump(int A[], int n) {
			int step = 0;
			int start = 0;
			int end = 1;

			while (end < n && start < end) {
				int maxRight = -1;

				for (int i=start; i<end; i++)
					if (maxRight < A[i]+i)
						maxRight = A[i]+i;

				start = end;
				end = maxRight+1;
				step++;
			}

			if (end >= n)
				return step;
			else
				return -1;
		}

};

int main() {
	vector<int> num;

	cin >> num;

	int *A = new int [ num.size() ];
	for (int i=0; i<(int)num.size(); i++)
		A[i] = num[i];

	cerr << "n = " << num.size() << endl;
	Solution sol;

	cout << sol.jump(A, num.size()) << endl;

	return 0;
}
