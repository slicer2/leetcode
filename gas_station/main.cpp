#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
ostream & operator << (ostream & os, vector<T> v) {
	typename vector<T>::iterator it;
	for (it=v.begin(); it != v.end(); it++)
		os << (*it) << ' ';

	os<< endl;

	return os;
}

class Solution {
	public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		vector<int> gasCost;

		//cerr << gas.size() << endl;
		assert(gas.size() == cost.size());
		assert(gas.size() > 0);


		for (int i=0; i<gas.size(); i++)
			gasCost.push_back(gas[i]-cost[i]);

		if (gasCost.size() == 1) {
			if (gasCost[0] >= 0)
				return 0;
			else
				return -1;
		}

		int comb = gasCost[0];
		int idx = 0;

		vector<int> combIdx, combCost;


		for (int i=1; i<gasCost.size(); i++) {
			if ( (gasCost[i] <= 0 && comb <= 0) || (gasCost[i] >= 0 && comb >= 0) )
				comb += gasCost[i];
			else {
				combCost.push_back(comb);		
				comb = gasCost[i];
				combIdx.push_back(idx);
				idx = i;
			}
		}

		if ( combCost.size() ) {
			if ( (comb <= 0 && combCost[0] <= 0) || (comb >= 0 && combCost[0] >= 0) ) {
				combCost[0] += comb;
				combIdx[0] = idx;
			}
			else {
				combCost.push_back(comb);
				combIdx.push_back(idx);
			}
		}
		else {
			combCost.push_back(comb);
			combIdx.push_back(idx);
		}

		if (combCost.size() == 1) {
			if (combCost[0] >= 0)
				return combIdx[0];
			else
				return -1;
		}
		else {
			int startIdx = -1;
			for (int i=0; i<combCost.size(); i++)
				if (combCost[i] > 0) {
					startIdx = i;
					break;
				}
				else
					if (combCost[i] < 0) {
						startIdx = (i+1) % combCost.size();
						break;
					}

			assert (startIdx != -1);

			vector<int> new_gas, new_cost, new_idx;

			int i = startIdx;
			do {
				new_gas.push_back(combCost[i]);
				new_idx.push_back(combIdx[i]);
				new_cost.push_back(-combCost[(i+1) % combCost.size()]);
				//cerr<< new_gas;
				//cerr<< new_cost;
				//cerr<< new_idx;

				i = (i+2) % combCost.size();
			} while (i != startIdx);

			int stationIdx = canCompleteCircuit(new_gas, new_cost);
			
			if (stationIdx == -1)
				return -1;
			else
				return new_idx[stationIdx];
		}
	}
};

int main() {
	int a, c;
	vector<int> gas, cost;

	while (cin >> a >> c) {
		gas.push_back(a);
		cost.push_back(c);
	}

	Solution s;

	//cerr << gas;
	//cerr << cost;
	cout << s.canCompleteCircuit(gas, cost) << endl;
	return 0;
}
