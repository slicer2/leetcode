#include <iostream>
#include "dan.h"
#include <vector>

using namespace std;

class Solution {

	public:

		int calculateMinimumHP(vector<vector<int> > &dungeon) {
			unsigned nRow = dungeon.size(), nCol = dungeon[0].size();
			vector<int> col(nRow);

			col[nRow-1] = dungeon[nRow-1][nCol-1];

			for (int i=nRow-2; i>=0; i--)
				if (col[i+1] < 0)
					col[i] = col[i+1] + dungeon[i][nCol-1];
				else
					col[i] = dungeon[i][nCol-1];

			for (int j=nCol-2; j>=0; j--) {
				vector<int> _col(nRow);

				if (col[nRow-1] < 0)
					_col[nRow-1] = dungeon[nRow-1][j] + col[nRow-1];
				else
					_col[nRow-1] = dungeon[nRow-1][j];

				for (int i=nRow-2; i>=0; i--) {
					int t1, t2;
					if (_col[i+1] < 0)
						t1 = _col[i+1] + dungeon[i][j];
					else
						t1 = dungeon[i][j];

					if (col[i] < 0)
						t2 = col[i] + dungeon[i][j];
					else
						t2 = dungeon[i][j];

					if (t1 > t2)
						_col[i] = t1;
					else
						_col[i] = t2;
				}

				col = _col;
			}

			if (col[0] > 0)
				return 1;
			else
				return -col[0]+1;
		}

};

int main() {
	vector<vector<int> > dungeon;
	cin >> dungeon;
	cout << dungeon << endl;

	Solution sol;
	cout << sol.calculateMinimumHP(dungeon) << endl;
	return 0;
}
