#include <iostream>
#include "dan.h"
#include <vector>

using namespace std;
class Solution {
	public:
		int numTrees(int n) {
			if (n == 0)
				return 1;

			vector<int> sow(n);

			sow[0] = 1;

			for (int i=1; i<=n; i++) {
				sow[i] += sow[i-1];

				if (i != 1)
					sow[i] += sow[i-1];

				for (int j=2; j<= i-1; j++)
					sow[i] += sow[j-1]*sow[i-j];
			}

			return sow[n];
		}
};

int main() {
	int n;
	cin >> n;

	Solution sol;

	cout << sol.numTrees(n) << endl;
	return 0;
}
