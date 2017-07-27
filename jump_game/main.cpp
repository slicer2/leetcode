#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

class Solution {
	public:

	bool canJump(int A[], int n) {
		if (n == 1)
			return true;

		int minNext = n-1;

		int p = n-1;

		while (p != 0) {
			p--;

			if (minNext <= A[p] + p)
				minNext = p;
		}

		if (minNext == 0)
			return true;
		else
			return false;
	}

};

int main() {
	int num;
	int n = 0;
	int *A = new int [30000];

	while (cin >> num) {
		A[n++] = num;
	}

	Solution sol;


	if (sol.canJump(A, n))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}
