#include <iostream>
#include <vector>
#include "dan.h"

using namespace std;

class Solution {
	public:
		int maximalRectangle(vector<vector<char> > &matrix) {
			if (matrix.size() == 0 || matrix[0].size() == 0)
				return 0;

			vector<int> max_ones_vertical(matrix[0].size()), max_ones_horizontal(matrix[0].size());

			int max_area = 0;

			for (int i=0; i<(int)matrix[0].size(); i++)
				max_ones_vertical[i] = 0;


			for (int i=0; i<(int)matrix.size(); i++) {

				for (int j=0; j<(int)matrix[0].size(); j++) {
					if (matrix[i][j] == '1') {
						max_ones_vertical[j] = max_ones_vertical[j] + 1;

						if (j > 0)
							max_ones_horizontal[j] = max_ones_horizontal[j-1]+1;
						else
							max_ones_horizontal[j] = matrix[i][j] - '0';
					}
					else {
						max_ones_vertical[j] = 0;
						max_ones_horizontal[j] = 0;
					}

					int max_height = max_ones_vertical[j];

					if (max_height > 0)
						for (int k=0; k<max_ones_horizontal[j]; k++) {
							if (max_height > max_ones_vertical[j-k])
								max_height = max_ones_vertical[j-k];

							if (max_height == 0) break;

							int area = (k+1) * max_height;

							if (area > max_area) {
								max_area = area;
								//cerr << "max_area = " << max_area << " i = " << i << " j = " << j << endl;
							}
						}

					//cerr << i << ' ' << j << ' ' << max_ones_horizontal[j] << ' ' << max_ones_vertical[j] << endl;
				}
			}

			return max_area;
		}
};

int main() {
	string s;
	vector<char> row;
	vector<vector<char> > matrix;

	while (getline(cin, s)) {
		row.clear();

		cout << "s = " << s << endl;

		for (auto &x: s) {
			row.push_back(x);
		}

		matrix.push_back(row);
	}

	cout << "maxtr = " << endl << matrix << endl;

	Solution sol;

	cout << sol.maximalRectangle(matrix) << endl;

	return 0;
}
