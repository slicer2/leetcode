#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
			if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
				return 0;

			int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();

			vector<int> memoized(cols);

			if (obstacleGrid[0][0] == 0)
				memoized[0] = 1;
			else
				memoized[0] = 0;

			for (int i=1; i<cols; i++) {
				if (obstacleGrid[0][i] == 0)
					memoized[i] = memoized[i-1];
				else
					memoized[i] = 0;
			}

			for (int k=1; k<rows; k++) {
				int curr, prev;

				if (obstacleGrid[k][0] == 0)
					prev = memoized[0];
				else
					prev = 0;

				for (int i=1; i<cols; i++) {
					if (obstacleGrid[k][i] == 0)
						curr = prev + memoized[i];
					else
						curr = 0;

					memoized[i-1] = prev;
					prev = curr;
				}

				memoized[cols-1] = prev;
			}

			return memoized[cols-1];
		}
};

int main() {
	vector<vector<int> > obstacleGrid;
	vector<int> row;
	int n;
	string s;

	while (getline (cin, s)) {
		stringstream ss(s);
		row.clear();

		while (ss >> n)
			row.push_back(n);

		obstacleGrid.push_back(row);
	}

	cerr << obstacleGrid << endl;

	Solution sol;

	cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;


	return 0;
}
