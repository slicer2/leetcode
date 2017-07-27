#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.size() <= 1)
				return 0;

			int lowest = prices[0];
			int max_profit = 0;

			for (unsigned int i=1; i<prices.size(); i++) {
				if (prices[i] < lowest)
					lowest = prices[i];
				else
					if (prices[i] - lowest > max_profit)
						max_profit = prices[i] - lowest;
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
