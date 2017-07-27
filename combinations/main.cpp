/**
 * This doesn't seem like the best solution
 * an iterative approach seems to potentially
 * save a lot computations. But OJ accepted it
 * anyway.
 */

#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		vector<vector<int> > combine(int n, int k) {
			vector<vector<int>> res;
			vector<int> partial(k);

			combine(1, n, k, partial, 0, res);

			return res;
		}

		void combine(int start, int n, int k, vector<int> &partial, int partial_start, vector<vector<int>> &res) {
			if (n-start+1<k) return;
			if (k == 0) {
				res.push_back(partial);
				return;
			}

			combine(start+1, n, k, partial, partial_start, res);
			partial[partial_start] = start;
			combine(start+1, n, k-1, partial, partial_start+1, res);
		}
};

int main() {
	int n, k;

	cin >> n >> k;

	Solution sol;

	cout << sol.combine(n, k) << endl;
	return 0;
}
