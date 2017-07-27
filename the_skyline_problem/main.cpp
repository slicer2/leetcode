#include <iostream>
#include <vector>
#include <map>
#include "dan.h"
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
	public:
		vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
			return vector<pair<int, int> >(0);
		}
};

int main() {
	vector<int> building;
	vector<vector<int> > buildings;

	while (cin >> building)
		buildings.push_back(building);

	Solution sol;
	vector<pair<int, int> > skyline = sol.getSkyline(buildings);

	for (auto y: skyline)
		cout << y.first << "   " << y.second << endl;

	return 0;
}
