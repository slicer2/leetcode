/**
 * best time to buy and sell stock in at most
 * k trnsactions.
 *
 * this is a generalization of II from 2 to k
 */
#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			int sz = prices.size();
			if (!sz) return 0;
			vector<int> R(sz, 0), Q(sz, 0), pR(sz, 0);

			for (int i=0; i<2; i++) {
				for (int j=1; j<sz; j++) {
					R[j] = max(R[j-1], Q[j-1]+prices[j]-prices[j-1]);
					Q[j] = max(pR[j-1], Q[j-1]+prices[j]-prices[j-1]);
				}

				pR = R;
				cout << R << endl;
			}

			return R[sz-1];
		}
};

int main() {
	vector<int> prices;

	cin >> prices;
	cout << prices << endl;

	Solution sol;

	cout << sol.maxProfit(prices) << endl;

	return 0;
}
