#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {

			if (prices.size() <= 1)
				return 0;

			int max_profit = 0;
			int prev_sell;
			int prev_sell_day;


			for (int i=1; i<prices.size(); i++) {
				if (prices[i] > prices[i-1]) {
					max_profit += prices[i] - prices[i-1];
					prev_sell = prices[i];
					prev_sell_day = i;
				}
				continue;

				if (i-1>prev_sell_day) {
					if (prices[i] > prices[i-1]) {
						max_profit += prices[i] - prices[i-1];
						prev_sell = prices[i];
						prev_sell_day = i;
					}
				}
				else {
					if (prices[i] > prices[i-1]) {
						max_profit += prices[i] - prices[i-1];
						prev_sell = prices[i];
						prev_sell_day = i;
					}
				}
			}

			return max_profit;
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
