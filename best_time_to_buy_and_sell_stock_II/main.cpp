#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			int sz = prices.size();
			if (sz == 0) return 0;

			vector<int> R(sz, 0);

			for (int i=1; i<sz; i++)
				R[i] = R[i-1]+max(0, prices[i]-prices[i-1]);

			return R[sz-1];
		}
};

int main() {
	int p;
	vector<int> prices;

	while (cin >> p)
		prices.push_back(p);

	Solution sol;

	cout << sol.maxProfit(prices) << endl;

	return 0;
}
