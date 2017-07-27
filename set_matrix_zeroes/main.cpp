#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "dan.h"

using namespace std;

class Solution {
	public:
		void setZeroes(vector<vector<int> > &matrix) {
			int rows = matrix.size();
			if (rows == 0)
				return;

			int cols = matrix[0].size();

			bool row0_has_0 = false, col0_has_0 = false;

			cerr << matrix << endl;

			for (int i=0; i<rows; i++)
				for (int j=0; j<cols; j++){
					if (matrix[i][j] == 0) {
						matrix[0][j] = 0;
						matrix[i][0] = 0;

						if (i == 0)
							row0_has_0 = true;

						if (j == 0)
							col0_has_0 = true;
					}
				}

			cerr << matrix << endl;

			for (int i=1; i<rows; i++)
				if (matrix[i][0] == 0)
					for (int j=0; j<cols; j++)
						matrix[i][j] = 0;

			for (int j=1; j<cols; j++)
				if (matrix[0][j] == 0)
					for (int i=0; i<rows; i++)
						matrix[i][j] = 0;

			if (row0_has_0)
				for (int j=0; j<cols; j++)
					matrix[0][j] = 0;

			if (col0_has_0)
				for (int i=0; i<rows; i++)
					matrix[i][0] = 0;

		}
};

int main() {
	string s;
	vector<int> row;
	vector<vector<int> > matrix;
	int num;

	while (getline(cin, s)) {
		row.clear();

		stringstream ss(s);

		while (ss >> num) {
			row.push_back(num);
		}

		matrix.push_back(row);
	}

	Solution sol;

	sol.setZeroes(matrix);

	cout << matrix << endl;

	return 0;
}
