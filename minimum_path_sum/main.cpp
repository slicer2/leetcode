#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include "dan.h"

using namespace std;

class Solution {
	vector<vector<int> >memoized;

	int min(int a, int b) {
		return ((a<b)?a:b);
	}

	int minPath(vector<vector<int> > &grid, int r, int c){
		if (memoized[r][c] != -1)
			return memoized[r][c];

		if (r == 0 && c == 0) {
			memoized[0][0] = grid[0][0];
			return grid[0][0];
		}

		int minNbr = INT_MAX;

		if (r > 0)
			minNbr = min(minNbr, minPath(grid, r-1, c));

		if (c > 0)
			minNbr = min(minNbr, minPath(grid, r, c-1));

		memoized[r][c] = minNbr + grid[r][c];

		return memoized[r][c];
	}

	public:
		int minPathSum(vector<vector<int> > &grid) {
			if (grid.size() == 0 || grid[0].size() == 0)
				return 0;

			memoized = grid;
			for (auto &x: memoized)
				for (auto &y:x)
					y = -1;

			return minPath(grid, grid.size()-1, grid[0].size()-1);
		}
};

int main() {
	string s;
	vector<int> row;
	int n;
	vector<vector<int> > grid;

	while (getline(cin, s)) {
		stringstream ss(s);
		row.clear();

		while (ss >> n)
			row.push_back(n);

		grid.push_back(row);
	}

	Solution sol;
	
	cout << sol.minPathSum(grid) << endl;

	return 0;
}
