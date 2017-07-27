#include <vector>
#include "dan.h"
#include <queue>
#include <cstdlib>

using namespace std;

class Solution {
	public:
		int numIslands(vector<vector<char>> &grid) {
			if (grid.size() == 0 || grid[0].size() == 0)
				return 0;

			unsigned int nRow = grid.size();
			unsigned int nCol = grid[0].size();

			vector<vector<char> > visited(nRow, vector<char>(nCol, 0));

			queue<pair<unsigned, unsigned> > q;

			int nIslands = 0;

			for (unsigned iRow = 0; iRow < nRow; iRow++)
				for (unsigned iCol = 0; iCol < nCol; iCol++) {
					if (grid[iRow][iCol] == '1' && visited[iRow][iCol] == 0) {
						nIslands++;

						visited[iRow][iCol] = 1;
						q.push(make_pair(iRow, iCol));

						while (!q.empty()) {
							pair<unsigned, unsigned> p = q.front();
							q.pop();

							if (p.second < nCol-1)
								if (grid[p.first][p.second+1] == '1' && visited[p.first][p.second+1] == 0) {
									visited[p.first][p.second+1] = 1;
									q.push(make_pair(p.first, p.second+1));
								}

							if (p.second > 0)
								if (grid[p.first][p.second-1] == '1' && visited[p.first][p.second-1] == 0) {
									visited[p.first][p.second-1] = 1;
									q.push(make_pair(p.first, p.second-1));
								}

							if (p.first < nRow-1)
								if (grid[p.first+1][p.second] == '1' && visited[p.first+1][p.second] == 0) {
									visited[p.first+1][p.second] = 1;
									q.push(make_pair(p.first+1, p.second));
								}

							if (p.first > 0)
								if (grid[p.first-1][p.second] == '1' && visited[p.first-1][p.second] == 0) {
									visited[p.first-1][p.second] = 1;
									q.push(make_pair(p.first-1, p.second));
								}
						}
					}
				}

				return nIslands;
		}
};

int main() {
	vector<vector<char> > grid;
	cin >> grid;

	Solution sol;
	cout << sol.numIslands(grid) << endl;

	return 0;
}
