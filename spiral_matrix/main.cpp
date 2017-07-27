#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "dan.h"

using namespace std;

template <typename T>
istream & operator >> (istream & is, vector<vector<T> > &matrix) {
	vector<T> row;
	string s;
	T n;

	while (getline(is, s)) {
		stringstream ss(s);
		row.clear();

		while (ss>>n)
			row.push_back(n);

		matrix.push_back(row);
	}

	return is;
}

class Solution {
	public:
		vector<int> spiralOrder(vector<vector<int> > &matrix) {
			vector<int> result;

			if (matrix.size() == 0 || matrix[0].size() == 0)
				return result;

			int r = 0, c = -1;
			int r_lb = 0, r_ub = matrix.size();
			int c_lb = -1, c_ub = matrix[0].size();

			int dir = 0;

			int len;

			switch (dir) {
				case 0:
					len = c_ub - c - 1;
					break;
				case 1:
					len = r_ub - r - 1;
					break;
				case 2:
					len = c - c_lb - 1;
				default:
					len = r - r_lb - 1;
			}

			while (len > 0) {
				for (int i=0; i<len; i++)
					switch (dir) {
						case 0:
							result.push_back(matrix[r][++c]);
							break;
						case 1:
							result.push_back(matrix[++r][c]);
							break;
						case 2:
							result.push_back(matrix[r][--c]);
							break;
						default:
							result.push_back(matrix[--r][c]);
					}

				switch (dir) {
					case 0:
						c_ub = c;
						break;
					case 1:
						r_ub = r;
						break;
					case 2:
						c_lb = c;
						break;
					default:
						r_lb = r;
				}

				dir = (dir + 1) % 4;

				switch (dir) {
					case 0:
						len = c_ub - c - 1;
						break;
					case 1:
						len = r_ub - r - 1;
						break;
					case 2:
						len = c - c_lb - 1;
						break;
					default:
						len = r - r_lb - 1;
				}

			}

			return result;
		}
};

int main() {
	vector<vector<int> > matrix;

	cin >> matrix;


	Solution sol;

	cout << sol.spiralOrder(matrix) << endl;

	return 0;
}
