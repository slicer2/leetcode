#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {

		void rot(vector<vector<int> > &matrix, int lvl) {
			int upLvl = matrix.size() - lvl;

			if (upLvl-lvl <= 1)
				return;

			int i, j;
			for (i=lvl, j = upLvl-1; i<upLvl-1; i++, j--) {
				int t = matrix[lvl][i];
				matrix[lvl][i] = matrix[j][lvl];
				matrix[j][lvl] = matrix[upLvl-1][j];
				matrix[upLvl-1][j] = matrix[i][upLvl-1];
				matrix[i][upLvl-1] = t;
			}

			rot(matrix, lvl+1);
		}
	public:

		void rotate(vector<vector<int> > &matrix) {
			rot(matrix, 0);
		}

};

int main() {
	vector<vector<int> > matrix;
	cin >> matrix;

	cout << matrix << endl << endl;

	Solution sol;

	sol.rotate(matrix);

	cout << matrix << endl;
	return 0;
}
